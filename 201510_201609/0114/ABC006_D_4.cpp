#include <iostream>
#include <algorithm>
using namespace std;

int N;
int c[30010];
int dp[30010];
int table[30010];
const int infty = 100000000;

int main() {
  cin >> N;
  for (auto i = 0; i < N; i++) {
    cin >> c[i];
  }
  fill(dp, dp+30010, 1);
  fill(table, table+30010, infty);
  table[0] = -infty;
  for (auto i = 0; i < N; i++) {
    int lb = 0;
    int ub = 30010;
    while (ub - lb > 1) {
      int t = (lb+ub)/2;
      // cerr << "t = " << t << endl;
      if (table[t] < c[i]) {
        lb = t;
      } else {
        ub = t;
      }
    }
    dp[i] = lb + 1;
    table[dp[i]] = min(table[dp[i]], c[i]);
    // cerr << "table[" << dp[i] << "] = " << table[dp[i]] << endl; 
  }
  int maxi = 0;
  for (auto i = 0; i < N; i++) {
    maxi = max(maxi, dp[i]);
  }
  cout << N - maxi << endl;
}
