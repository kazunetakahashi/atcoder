#include <iostream>
#include <iomanip> // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple> // get<n>(xxx)
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set> // S.insert(M);
// if (S.find(key) != S.end()) { }
// for (auto it=S.begin(); it != S.end(); it++) { }
// auto it = S.lower_bound(M);
#include <random> // random_device rd; mt19937 mt(rd());
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
#include <valarray>
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.
// insert #if<tab> by my emacs. #if DEBUG == 1 ... #end

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

#define mattype long long

// 行列
struct matrix {
  int row, col;
  valarray<mattype> a;
  matrix(int N, int M) { // matrix A(N, M); で初期化できる。
    a = valarray<mattype>(N * M);
    row = N;
    col = M;
  }
};

mattype MOD = 1000000007; 

matrix mod_multiply(matrix A, matrix B) {
  assert(A.col == B.row);
  int N = A.col;
  matrix C(A.row, B.col);
  for (auto i=0; i<C.row; i++) {
    for (auto j=0; j<C.col; j++) {
      C.a[i*C.col + j] = ((valarray<mattype>)A.a[slice(i*A.col, N, 1)] *
                          (valarray<mattype>)B.a[slice(j, N, B.col)]).sum()%MOD;
    }
  }
  return C;
}

matrix mod_pow(matrix A, mattype n) { // n \geq 1
  if (n%2 == 0) {
    matrix B = mod_pow(A, n/2);
    return mod_multiply(B, B);
  } else if (n == 1) {
    return A;
  } else {
    return mod_multiply(A, mod_pow(A, n-1));
  }
}

int main () {
  int N, M;
  cin >> N >> M;
  int X[100010];
  for (auto i = 0; i < M; ++i) {
    cin >> X[i];
  }
  matrix A(3, 3);
  A.a = {1, 1, 1, 2, 1, 0, 1, 1, 1};
  matrix B(3, 3);
  B.a = {1, 0, 0, 2, 1, 0, 1, 1, 1};
  matrix x(3, 1);
  x.a = {1, 0, 0};
  int cnt = 0;
  for (auto i = 0; i < M; ++i) {
    x = mod_multiply(mod_pow(A, X[i] - 1 - cnt), x);
    x = mod_multiply(B, x);
    cnt = X[i];
  }
  x = mod_multiply(mod_pow(A, N - cnt), x);
  cout << x.a[0] << endl;
}
