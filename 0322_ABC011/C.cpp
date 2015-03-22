#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int NG[3];

int main() {
  int N;
  cin >> N;
  for (auto i=0; i<3; i++) {
    cin >> NG[i];
  }
  bool table[110][310]; // time, now;
  fill(&table[0][0], &table[0][0]+110*310, false);
  table[0][0] = true;
  for (auto i=1; i<=100; i++) {
    for (auto j=0; j<=N; j++) {
      for (auto k=0; k<3; k++) {
        if (NG[k] == j) goto EXIT;
      }
      for (auto k=1; k<=3; k++) {
        if (table[i-1][j-k]) table[i][j] = true;
      }
    EXIT: continue;
    }
  }
  bool ans = false;
  for (auto i=0; i<=100; i++) {
    if (table[i][N]) {
      ans = true;
      break;
    }
  }
  cout << (ans ? "YES" : "NO") << endl;
}
