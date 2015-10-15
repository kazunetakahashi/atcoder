#define mattype long long

#include <iostream>
#include <algorithm>
#include <valarray>
#include <cassert>
#include <string>
#include <random>
using namespace std;

// 行列
struct matrix {
  int row, col;
  valarray<mattype> a;
  matrix(int N, int M) {
    a = valarray<mattype>(N * M);
    row = N;
    col = M;
  }
  bool operator<(const matrix& right) const { // 使わないけどtupleに必要
    if (row != right.row) {
      return row < right.row;
    }
    if (col != right.col) {
      return col < right.col;
    }
    for (auto i=0; i<row*col; i++) {
      if (a[i] != right.a[i]) {
        return a[i] < right.a[i];
      }
    }
    return false;
  }
  bool operator>(const matrix& right) const { // 使わないけどtupleに必要
    if (row != right.row) {
      return row > right.row;
    }
    if (col != right.col) {
      return col > right.col;
    }
    for (auto i=0; i<row*col; i++) {
      if (a[i] != right.a[i]) {
        return a[i] > right.a[i];
      }
    }
    return false;
  }
  bool operator==(const matrix& right) const {
    if (row != right.row) return false;
    if (col != right.col) return false;
    for (auto i=0; i<row*col; i++) {
      if (a[i] != right.a[i]) {
        return false;
      }
    }
    return true;
  }
  string to_s() const {
    string res = "";
    for (auto i=0; i<row; i++) {
      for (auto j=0; j<col; j++) {
        res += to_string(a[i*col+j]);
        if (j != col-1) res += " ";
      }
      if (i != row-1) res += "\n";
    }
    return res;
  }
  void input() { // 大抵行列表示で入力されるからこれで事足りるでしょう。
    for (auto i=0; i<row*col; i++) {
      cin >> a[i];
    }
  }
};

ostream& operator<<(ostream& s, const matrix A) {
  return s << A.to_s();
}

matrix multiply(matrix A, matrix B) {
  assert(A.col == B.row);
  int N = A.col;
  matrix C(A.row, B.col);
  for (auto i=0; i<C.row; i++) {
    for (auto j=0; j<C.col; j++) {
      C.a[i*C.col + j] = ((valarray<mattype>)A.a[slice(i*A.col, N, 1)] *
                          (valarray<mattype>)B.a[slice(j, N, B.col)]).sum();
    }
  }
  return C;
}

bool AB_is_equal_to_C(matrix A, matrix B, matrix C, int times) { // AB = C かどうかを判定。timesには回数を指定。
  // N * M が 10^6 くらいなら、times = 10 で 1秒単位がかかるようになるから要注意。
  // でも 10 はほしいところである。
  assert(A.col == B.row);
  assert(A.row == C.row);
  assert(B.col == C.col);
  random_device rd;
  mt19937 mt(rd());
  matrix p = matrix(B.col, 1);
  for (auto i=0; i<times; i++) {
    for (auto j=0; j<B.col; j++) {
      p.a[j] = mt()%10000;
    }
    if (multiply(A, multiply(B, p)) == multiply(C, p)) {
      /*
      cerr << "ABp is following:" << endl;
      cerr << multiply(A, multiply(B, p)) << endl;
      cerr << "Cp is following:" << endl;
      cerr << multiply(C, p) << endl;
      */
      continue;
    } else {
      return false;
    }
  }
  return true;
}

int main() {
  int N;
  cin >> N;
  matrix A(N, N);
  A.input();
  matrix B(N, N);
  B.input();
  matrix C(N, N);
  C.input();
  cout << (AB_is_equal_to_C(A, B, C, 10) ? "YES" : "NO") << endl;
}
