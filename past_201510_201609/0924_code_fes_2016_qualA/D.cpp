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

typedef long long ll;
typedef pair<int, ll> P;

//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};

// const int C ;
const ll M = 1000000000000007;

const int UFSIZE = 100010;
int union_find[UFSIZE];
ll mini[UFSIZE];
ll sa[UFSIZE];

void init() {
  for (auto i=0; i<UFSIZE; i++) {
    union_find[i] = i;
    sa[i] = 0;
    mini[UFSIZE] = 0;
  }
}

P root_itr(int a, ll sub) {
  if (a == union_find[a]) return make_pair(a, sub);
  P t = root_itr(union_find[a], sub+sa[a]);
  union_find[a] = t.first;
  mini[union_find[a]] = min(mini[a], mini[union_find[a]]);
  sa[a] = t.second;
  return t;
}

int root(int a) {
  return root_itr(a, 0).first;
}

ll calc_minus(int a, int b) {
  return sa[a] - sa[b];
}

ll calc_mini(int a) {
  return mini[root(a)];
}

bool issame(int a, int b) {
  return root(a) == root(b);
}

void unite(int a, int b, ll sub) {
  union_find[root(a)] = root(b);
  mini[root(b)] = min(mini[root(a)], mini[root(b)]);
  sa[root(a)] = sub + sa[b] - sa[a];
}

bool isroot(int a) {
  return root(a) == a;
}

typedef pair<int, ll> point;

int R, C;
int N;
int r[100010], c[100010];
ll a[100010];
vector<point> V[100010];

int main() {
  // initが必要
  init();
  cin >> R >> C;
  cin >> N;
  for (auto i = 0; i < N; i++) {
    cin >> r[i] >> c[i] >> a[i];
    r[i]--; c[i]--;
    V[r[i]].push_back(make_pair(c[i], a[i]));
  }
  for (auto i = 0; i < N; i++) {
    if (V[i].empty()) continue;
    int kcol = V[i][0].first;
    ll kval = V[i][0].second;
    for (auto it = V[i].begin()+1; it != V[i].end(); it++) {
      int scol = (*it).first;
      int sval = (*it).second;
      if (issame(kcol, scol)) {
        if (!(calc_minus(kcol, scol) == sval - kval)) {
          cout << "No" << endl;
          return 0;
        }
      } else {
        unite(kcol, scol, sval - kval);
      }
    }
  }
}
