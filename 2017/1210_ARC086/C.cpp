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

int N, K;
int A[200010];
int cnt[200010];

int main () {
  cin >> N >> K;
  fill(cnt, cnt+200010, 0);
  for (auto i = 0; i < N; ++i) {
    cin >> A[i];
    cnt[A[i]]++;
  }
  vector<int> V;
  for (auto i = 1; i <= N; ++i) {
    if (cnt[i] > 0) {
      V.push_back(cnt[i]);
    }
  }
  int ans = 0;
  sort(V.begin(), V.end());
  int s = V.size();
  for (auto x : V) {
    if (s <= K) break;
    ans += x;
    s--;
  }
  cout << ans << endl;
}
