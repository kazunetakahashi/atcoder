#include <iostream>
#include <iomanip> // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple> // get<n>(xxx)
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set> // S.insert(M);
// if (S.find(key) != S.end()) { }
// for (auto it=S.begin(); it != S.end(); it++) { }
// auto it = S.lower_bound(M);
#include <random> // random_device rd; mt19937 mt(rd());
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.
// insert #if<tab> by my emacs. #if DEBUG == 1 ... #end

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

string S;

map<int, int> SS;

int ctoi(char c) {
  int cnt = c - 'a';
  return (1 << cnt);
}

int main () {
  cin >> S;
  int N = S.size();
  int cnt[26];
  fill(cnt, cnt+26, 0);
  for (auto x : S) {
    cnt[x - 'a']++;
  }
  bool ok = true;
  for (auto i = 0; i < 26; ++i) {
    if (cnt[i] % 2  != 0) ok = false;
  }
  if (ok) {
    cout << 1 << endl;
    return 0;
  }
  int dp[200010];
  dp[0] = 1;
  dp[1] = 1;
  int now = 0;
  SS[now] = 0;
  now = now ^ ctoi(S[0]);
  SS[now] = 1;
  for (auto i = 2; i <= N; ++i) {
    now = now ^ ctoi(S[i-1]);
    if (SS.find(now) == SS.end()) {
      SS[now] = i;
      dp[i] = dp[i-1] + 1;
    } else {
      dp[i] = dp[SS[now]];
    }
  }
  for (auto i = 0; i <= N; ++i) {
    cerr << "dp[" << i << "] = " << dp[i] << endl;
  }
  cout << dp[N] << endl;
}
