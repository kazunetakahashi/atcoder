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

// Convex Hull Trick を使用する。
// プログラミングコンテストチャレンジブック 第2版 p.306 の実装を参考にする。

ll K[200010];
ll L[200010];

deque<int> Q;

ll f(int j, ll x) {
  return K[j] * x + L[j];
}

bool skip_f2(int f1, int f2, int f3) {
  return (K[f1] - K[f2]) * (L[f3] - L[f1])
    + (K[f1] - K[f3]) * (L[f1] - L[f2]) <= 0;
}

void add(int t) { // 必ず傾きが広義単調減少になるように入れていく。
#if DEBUG == 1
  cerr << "add " << t << endl;
#endif
  while (Q.size() >= 2) {
    auto it = Q.end();
    auto last = it-1;
    auto last2 = it-2;
    if (skip_f2(*last2, *last, t)) {
#if DEBUG == 1
      cerr << "skipped " << *last << endl;
#endif
      Q.pop_back();
    } else {
      break;
    }
  }
  Q.push_back(t);
}

ll get_min(int x) { // 必ず x 座標が増えていく順に使用する。
#if DEBUG == 1
  cerr << "get_min " << x << endl;
#endif
  while (Q.size() >= 2) {
    auto it = Q.begin();
    auto it2 = it+1;
    if (f(*it, x) >= f(*it2, x)) {
#if DEBUG == 1
      cerr << "popped " << *it << endl;
#endif
      Q.pop_front();
    } else {
      break;
    }
  }
#if DEBUG == 1
  cerr << "f(" << *(Q.begin()) << ", "
       << x << ") = " << f(*(Q.begin()), x) + x * x << endl;
#endif
  return f(*(Q.begin()), x);
}

int main () {
  int N;
  cin >> N;
  ll a[200010];
  for (auto i = 0; i < N; ++i) {
    cin >> a[i];
  }
  for (auto j = 0; j < N; ++j) {
    K[j] = -2 * j;
    L[j] = a[j] + j * j;
  }
  for (auto j = 0; j < N; ++j) {
    add(j);
  }
  ll ans[200010];
  for (auto i = 0; i < N; ++i) {
    ans[i] = get_min(i);
  }
  for (auto i = 0; i < N; ++i) {
    cout << ans[i] + i * i << endl;
  }
}
