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
int num[200010];

int main () {
  cin >> S;
  int N = S.size();
  int cnt[26];
  fill(cnt, cnt+26, 0);
  for (auto x : S) {
    cnt[x - 'a']++;
  }
  int ans = 0;
  for (auto i = 0; i < 26; ++i) {
    if (cnt[i] % 2 == 1) {
      ans++;
    }
  }
  for (auto i = 0; i < 26; ++i) {
    char c = (char)('a' + i);
    int l = 0;
    for (auto j = 0; j < N; ++j) {
      if (S[j] == c) num[j] = l;
      l++;
    }
  }
  bool has_edge = false;
  if (cnt[S[0] - 'a'] % 2 == 1) {
    has_edge = true;
  }
  if (cnt[S[N-1] - 'a'] % 2 == 1) {
    has_edge = true;
  }
  for (auto i = 0; i < N-1; ++i) {
    if (S[i] != S[i+1]
        && num[i] % 2 == 0
        && num[i+1] % 2 == 0
        && cnt[S[i] - 'a'] % 2 == 1
        && cnt[S[i+1] - 'a'] % 2 == 1) {
      has_edge = true;
      break;
    }
  }
  if (has_edge) {
    cout << ans << endl;
  } else {
    cout << ans + 1 << endl;    
  }
}
