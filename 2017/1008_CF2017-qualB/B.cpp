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
int D[200010];
int M;
int T[200010];

int main () {
  cin >> N;
  for (auto i = 0; i < N; ++i) {
    cin >> D[i];
  }
  cin >> M;
  for (auto i = 0; i < M; ++i) {
    cin >> T[i];
  }
  multiset<int> S;
  for (auto i = 0; i < N; ++i) {
    S.insert(D[i]);
  }
  for (auto i = 0; i < M; ++i) {
    auto it = S.find(T[i]);
    if (it == S.end()) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
