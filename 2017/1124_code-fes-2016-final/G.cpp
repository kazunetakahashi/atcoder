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
const ll infty = 1000000000007;

typedef tuple<ll, int, int> edge;

int N, Q;
int A[200010];
int B[200010];
ll C[200010];
ll X[200010];
vector<edge> V;

const int UFSIZE = 200010;
int union_find[UFSIZE];

void init() {
  for (auto i=0; i<UFSIZE; i++) {
    union_find[i] = i;
  }
}

int root(int a) {
  if (a == union_find[a]) return a;
  return (union_find[a] = root(union_find[a]));
}

bool issame(int a, int b) {
  return root(a) == root(b);
}

void unite(int a, int b) {
  union_find[root(a)] = root(b);
}

bool isroot(int a) {
  return root(a) == a;
}

int main () {
  cin >> N >> Q;
  for (auto i = 0; i < Q; ++i) {
    cin >> A[i] >> B[i] >> C[i];
  }
  fill(X, X+200010, infty);
  for (auto i = 0; i < Q; ++i) {
    V.push_back(edge(C[i], A[i], B[i]));
    X[A[i]] = min(X[A[i]], C[i]+1);
    X[B[i]] = min(X[B[i]], C[i]+2);
  }
  for (auto i = 0; i < 3*N; ++i) {
    X[(i+1)%N] = min(X[i%N]+2, X[(i+1)%N]);
  }
  for (auto i = 0; i < N; ++i) {
    V.push_back(edge(X[i], i, i+1));
  }
  sort(V.begin(), V.end());
  init();
  int used = 0;
  ll ans = 0;
  auto it = V.begin();
  while (used < N-1) {
    ll c = get<0>(*it);
    ll a = get<1>(*it);
    ll b = get<2>(*it);
    if (!issame(a, b)) {
      used++;
      ans += c;
      unite(a, b);
    }
    it++;
  }
  cout << ans << endl;
}
