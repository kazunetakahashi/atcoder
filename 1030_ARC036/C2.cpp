#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll M = 1000000007;

int N, K;
string S;

ll dp[310][6][6];

int dfs(string s) {
  if (s.size() == N) {
    for (auto i=0; i<N; i++) {
      for (auto j=i; j<N; j++) {
        int sa = 0;
        for (auto k=i; k<=j; k++) {
          if (s[k] == '0') {
            sa--;
          } else {
            sa++;
          }
        }
        if (abs(sa) > K) {
          return 0;
        }
      }
    }
    return 1;
  } else {
    if (S[s.size()] == '?') {
      return dfs(s+"1") + dfs(s+"0");
    } else {
      return dfs(s+(char)S[s.size()]);
    }
  }
}

void zero(int t) {
  for (auto i=0; i<K; i++) {
    for (auto j=0; j<K+1; j++) {
      dp[t+1][i+1][max(0, j-1)] += dp[t][i][j];
      dp[t+1][i+1][max(0, j-1)] %= M;
    }
  }
}

void one(int t) {
  for (auto i=0; i<K; i++) {
    for (auto j=0; j<K+1; j++) {
      dp[t+1][max(0, j-1)][i+1] += dp[t][j][i];
      dp[t+1][max(0, j-1)][i+1] %= M;
    }
  }
}

ll dynamic() {
  fill(&dp[0][0][0], &dp[0][0][0]+310*6*6, 0);
  dp[0][0][0] = 1;
  for (auto i=0; i<N; i++) {
    if (S[i] == '0') {
      zero(i);
    } else if (S[i] == '1') {
      one(i);
    } else {
      zero(i);
      one(i);
    }
  }
  ll ans = 0;
  for (auto i=0; i<K+1; i++) {
    for (auto j=0; j<K+1; j++) {
      ans += dp[N][i][j];
      ans %= M;
    }
  }
  return ans;
}

int main() {
  cin >> N >> K >> S;
  if (N <= 12) {
    cout << dfs("") << endl;
  } else if (K <= 5) {
    cout << dynamic() << endl;
  }
}
