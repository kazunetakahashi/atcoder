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

int A[8] = {0, 1, 2, 3, 4, 5, 6, 7};
int N, M;
set<int> V[10];

int main () {
  cin >> N >> M;
  for (auto i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    V[a].insert(b);
    V[b].insert(a);
  }
  int ans = 0;
  do {
    bool ok = true;
    for (auto i = 0; i < N-1; ++i) {
      if (V[A[i]].find(A[i+1]) == V[A[i]].end()) {
        ok = false;
        break;
      }
    }
    if (ok) ans++;
  } while (next_permutation(A+1, A+N));
  cout << ans << endl;
}
