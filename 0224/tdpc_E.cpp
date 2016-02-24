#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

ll dp[10][10010][100];
ll M = 1000000007;

int main() {
  int D;
  string N;
  cin >> D >> N;
  dp[1][0][0] = 1;
  for (auto k = 1; k < D; k++) {
    dp[1][0][k] = 0; 
  }
  for (auto j = 1; j < 10010; j++) {
    for (auto k = 0; k < D; k++) {
      dp[1][j][k] = 0;
      for (auto i = 0; i < 10; i++) {
        dp[1][j][k] += dp[1][j-1][(k-i+10*D)%D];
        dp[1][j][k] %= M;
      }
    }
  }
  for (auto i = 2; i < 10; i++) {
    for (auto j = 0; j < 10010; j++) {
      for (auto k = 0; k < D; k++) {
        dp[i][j][k] = dp[i-1][j][k];
        dp[i][j][k] += dp[1][j][(k-(i-1)+10*D)%D];
        dp[i][j][k] %= M;
      }
    }
  }
  /*
  for (auto i = 1; i < 10; i++) {
    for (auto j = 0; j < 10; j++) {
      for (auto k = 0; k < D; k++) {
        cout << "dp[" << i << "]["
             << j << "][" << k << "] = " << dp[i][j][k] << endl;
      }
    }
  }
  */
  int amari = 0;
  int sum = 0;
  ll ans = 0;
  for (unsigned i = 0; i < N.size(); i++) {
    int x = N[i] - '0';
    int y = (int)N.size() - 1 - (int)i;
    int z = (D - amari)%D;
    if (x == 0) continue;
    ans += dp[x][y][z];
    //cerr << "x = " << x << ", y = " << y << ", z = " << z << endl;
    ans %= M;
    amari += x;
    amari %= D;
    sum += x;
  }
  ans += M-1;
  ans %= M;
  if (sum%D == 0) {
    ans += 1;
    ans %= M;
  }
  cout << ans << endl;
}
