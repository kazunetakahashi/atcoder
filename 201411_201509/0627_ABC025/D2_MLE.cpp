#include <iostream>
#include <algorithm>
// #include <tuple>
using namespace std;
 
// typedef tuple<int, int> point;
typedef long long ll;
 
const int M = 1000000007;
 
const int dx[2][2] = { {-5, 5}, {-1, 1} };
 
ll DP[33554442];
 
bool sft(int table, int c) {
  return (((table >> c) & 1) == 1);
}
 
bool checker(int table, int p) {
  bool ok = true;
  int pp[2] = {p/5, p%5};
  for (auto i=0; (i<2) && ok; i++) {
    if ((pp[i] == 0) || (pp[i] == 4)) continue;
    int q = p+dx[i][0];
    int r = p+dx[i][1];
    bool qb = sft(table, q);
    bool rb = sft(table, r);
    ok = ((qb && rb) || (!qb && !rb));
  }
  return ok;
}
 
/*
void vis(int i, int d) {
  if (d == 0) return;
  cerr << "d = " << d << endl;
  int cnt = 0;
  for (auto j=0; j<25; j++) {
    if (sft(i, j)) {
      cnt++;
    }
  }
  cerr << "cnt = " << cnt << endl;
  for (auto j=0; j<25; j++) {
    if (sft(i, j)) {
      cerr << "o";
    } else {
      cerr << "x";
    }
    if (j%5 == 4) {
      cerr << endl;
    }
  }
}
*/
 
int main() {
  bool used[25]; // used[num] = numが使われているか否か
  fill(used, used+25, false);
  bool field[25]; // field[zahyo] = zahyoが空欄であるか否か
  fill(field, field+25, true);
  int X[25]; // num -> zahyo
  int x[5][5]; // 場本体
  for (auto i=0; i<5; i++) {
    for (auto j=0; j<5; j++) {
      cin >> x[i][j];
      x[i][j]--;
      if (x[i][j] == -1) {
      } else {
        X[x[i][j]] = i * 5 + j;
        used[x[i][j]] = true;
        field[i * 5 + j] = false;
      }
    }
  }
  /*
  cerr << "unused : ";
  for (auto i=0; i<25; i++) {
    if (!used[i]) {
      cerr << i << " ";
    }
  }
  cerr << endl;
  cerr << "initial field : " << endl;
  for (auto j=0; j<25; j++) {
    if (field[j]) {
      cerr << "o";
    } else {
      cerr << "x";
    }
    if (j%5 == 4) {
      cerr << endl;
    }
  }
  */
  fill(DP, DP+33554442, 0);
  DP[0] = 1;
  for (auto cnt=1; cnt<=25; cnt++) {
    int i = (1 << cnt) - 1;
    while (i < (1 << 25)) {
      int num = cnt-1;
      if (used[num]) {
        if (sft(i, X[num]) && checker(i, X[num])) {
          DP[i] = DP[i-(1 << X[num])];
        }
      } else {
        for (auto j=0; j<25; j++) {
          if (field[j] && sft(i, j) && checker(i, j)) {
            DP[i] += DP[i - (1 << j)];
            DP[i] %= M;
          }
        }
      }
      // vis(i, DP[i]);      
      // 処理
      int temp1 = i & (-i);
      int temp2 = i + temp1;
      // cerr << temp1 << " " << temp2 << endl;
      int temp3 = i & (~temp2);
      // cerr << temp3 << endl;
      i = (((temp3/temp1) >> 1) | temp2);
      // cerr << i << endl;
    }
  }
  cout << DP[(1 << 25)-1] << endl;
}
