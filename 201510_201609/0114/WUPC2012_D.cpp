#include <iostream>
#include <algorithm>
using namespace std;

int N;
int a[110][110];
int dp[110][110];

int main() {
  cin >> N;
  for (auto i = 0; i < N; i++) {
    for (auto j = 0; j <= i; j++) {
      cin >> a[i][j];
    }
  }
  dp[0][0] = a[0][0];
  for (auto i = 1; i < N; i++) {
    for (auto j = 0; j <= i; j++) {
      dp[i][j] = 0;
      if (j > 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + a[i][j]);
      dp[i][j] = max(dp[i][j], dp[i-1][j] + a[i][j]);      
    }
  }
  int ans = 0;
  for (auto i = 0; i < N; i++) {
    ans = max(ans, dp[N-1][i]);
  }
  cout << ans << endl;
}
