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

int N;
int ans[50];

void solve(int x, int y) {
  int s[50];
  fill(s, s+N, 0);
  int k = 1;
  for (auto i = x; i < y; ++i) {
    s[i] = k;
    k *= 10;
  }
  cout << "? ";
  for (auto i = 0; i < N; ++i) {
    cout << s[i];
    if (i < N-1) {
      cout << " ";
    } else {
      cout << endl;
    }
  }
  int w;
  cin >> w;
  for (auto i = x; i < y; ++i) {
    ans[i] = w%10;
    // cerr << "ans[" << i << "] = " << ans[i] << endl;
    if (ans[i] < 5) ans[i] += 10;
    w -= ans[i];
    w /= 10;
  }
}

int main () {
  cin >> N;
  fill(ans, ans+50, false);
  int ind = 0;
  while (ind < N) {
    solve(ind, min(N, ind+5));
    ind += 5;
  }
  cout << "! ";
  for (auto i = 0; i < N; ++i) {
    cout << ans[i]%2;
    if (i < N-1) {
      cout << " ";
    } else {
      cout << endl;
    }
  }
}
