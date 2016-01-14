// 50点
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int c[30010];
int dp[30010];

int main() {
  cin >> N;
  for (auto i = 0; i < N; i++) {
    cin >> c[i];
  }
  fill(dp, dp+30010, 1);
  for (auto i = 1; i < N; i++) {
    for (auto j = 0; j < i; j++) {
      if (c[j] < c[i]) {
        dp[i] = max(dp[i], dp[j]+1);
      }
    }
  }
  int maxi = 0;
  for (auto i = 0; i < N; i++) {
    maxi = max(maxi, dp[i]);
  }
  cout << N - maxi << endl;
}
