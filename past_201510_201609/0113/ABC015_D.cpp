#include <iostream>
#include <algorithm>
using namespace std;

int dp[60][10010];

int main() {
  int W;
  cin >> W;
  int N, K;
  cin >> N >> K;
  int A[60];
  int B[60];
  for (auto i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }
  fill(&dp[0][0], &dp[0][0]+60*10010, 0);
  for (auto k = 0; k < N; k++) {
    for (auto i = K; i > 0; i--) {
      for (auto j = A[k]; j <= W; j++) {
        dp[i][j] = max(dp[i][j], dp[i-1][j-A[k]] + B[k]);
      }
    }
  }
  int ans = 0;
  for (auto i = 0; i <= K; i++) {
    for (auto j = 0; j <= W; j++) {
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << endl;
}
