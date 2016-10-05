#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int N;
  cin >> N;
  int R[3010];
  for (auto i = 0; i < N; i++) {
    cin >> R[i];
  }
  int dp[3010][2];
  fill(&dp[0][0], &dp[0][0]+3010*2, 0);
  dp[0][0] = dp[0][1] = 1;
  for (auto i = 0; i < N; i++) {
    for (auto j = 0; j < i; j++) {
      if (R[j] < R[i]) dp[i][0] = max(dp[i][0], dp[j][1]+1);
      else if (R[j] > R[i]) dp[i][1] = max(dp[i][1], dp[j][0]+1);
    }
  }
  int ans = max(dp[N-1][0], dp[N-1][1]);
  //cerr << ans << endl;
  if (ans < 3) {
    cout << 0 << endl;
  } else {
    cout << ans << endl;
  }
}
