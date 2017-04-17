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

int n;
string S[60];
int cnt[60][26];
int mini[26];

int main () {
  cin >> n;
  for (auto i = 0; i < n; ++i) {
    cin >> S[i];
  }
  fill(&cnt[0][0], &cnt[0][0]+60*26, 0);
  for (auto i = 0; i < n; ++i) {
    for (auto x : S[i]) {
      cnt[i][x - 'a']++;
    }
  }
  fill(mini, mini+26, 100);
  for (auto i = 0; i < 26; ++i) {
    for (auto j = 0; j < n; ++j) {
      mini[i] = min(mini[i], cnt[j][i]);
    }
  }
  string ans = "";
  for (auto i = 0; i < 26; ++i) {
    string t{'a' + i};
    for (auto j = 0; j < mini[i]; ++j) {
      ans += t;
    }
  }
  cout << ans << endl;
}
