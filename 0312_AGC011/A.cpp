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

int N, C, K;
int T[100010];

int main () {
  cin >> N >> C >> K;
  for (auto i = 0; i < N; ++i) {
    cin >> T[i];
  }
  sort(T, T+N);
  int ans = 0;
  int now_t = T[0];
  int now_p = 0;
  for (auto i = 0; i < N; ++i) {
    if (now_p >= C || T[i] - now_t > K) {
      ++ans;
      now_t = T[i];
      now_p = 1;
    } else {
      ++now_p;
    }
    //cerr << now_t << " " << now_p << endl;
  }
  ++ans;
  cout << ans << endl;
}
