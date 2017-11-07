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

int N, M;
typedef tuple<int, int> takahashi;
vector<takahashi> V;

int main () {
  cin >> N >> M;
  for (auto i = 0; i < N; ++i) {
    int L, R;
    cin >> L >> R;
    V.push_back(takahashi(L, R));
  }
  sort(V.begin(), V.end());
  priority_queue<int, vector<int>, less<int> > Q;
  vector<int> W;
  int ind = 1;
  for (auto x : V) {
    if (ind <= get<0>(x)) {
      ++ind;
    } else {
      Q.push(get<1>(x));
      cerr << Q.top() << endl;
      W.push_back(Q.top());
      Q.pop();
    }
  }
  for (auto it = W.begin(); it != W.end(); ++it) {
    *it = M+1 - *it;
  }
  sort(W.begin(), W.end());
  for (auto x : W) {
    cerr << x << " ";
  }
  cerr << endl;
  ind = 1;
  int ans = 0;
  for (auto x : W) {
    if (ind <= x) {
      ++ind;
    } else {
      ++ans;
    }
  }
  cout << ans << endl;
}

