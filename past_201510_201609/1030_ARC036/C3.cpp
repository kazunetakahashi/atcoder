#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cassert>
using namespace std;

typedef long long ll;

const ll M = 1000000007;

int N, K;
string S;

ll dp[310][2][310];

void zero_one(int x, int t) {
  int y = (x+1)%2;
  for (auto i=0; i<K+1; i++) {
    dp[t+1][x][max(0, i-1)] += dp[t][x][i];
    dp[t+1][x][max(0, i-1)] %= M;
  }
  dp[t+1][x][0] += M - dp[t][y][K];
  dp[t+1][x][0] %= M;
  for (auto i=0; i<K; i++) {
    dp[t+1][y][i+1] += dp[t][y][i];
    dp[t+1][y][i+1] %= M;
  }
}

ll dynamic() {
  fill(&dp[0][0][0], &dp[0][0][0]+310*2*310, 0);
  dp[0][0][0] = 1;
  dp[0][1][0] = 1;
  for (auto i=0; i<N; i++) {
    if (S[i] == '0') {
      zero_one(0, i);
    } else if (S[i] == '1') {
      zero_one(1, i);
    } else {
      zero_one(0, i);
      zero_one(1, i);
    }
  }
  ll ans = 0;
  ll ans2 = 0;
  for (auto i=0; i<K+1; i++) {
    ans += dp[N][0][i];
    ans %= M;
    ans2 += dp[N][1][i];
    ans2 %= M;
  }
  assert(ans == ans2);
  return ans;
}

int main() {
  cin >> N >> K >> S;
  cout << dynamic() << endl;
}
