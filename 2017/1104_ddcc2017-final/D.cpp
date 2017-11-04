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
const ll M = 1000000007;

typedef tuple<ll, int, int> key; // bit, backback, back

vector<ll> connected[60][60];

map<key, ll> dp;

int N;
vector<int> V[60];

void make_connected(int x, int y) {
  bool visited[60];
  fill(visited, visited+60, false);
  visited[x] = true;
  visited[y] = true;
  for (auto i = 0; i < N; ++i) {
    if (visited[i]) continue;
    ll ans = 0;
    stack<int> S;
    S.push(i);
    while (!S.empty()) {
      int now = S.top();
      S.pop();
      if (!visited[now]) {
        visited[now] = true;
        ans += 1ll << now;
        for (auto e : V[now]) {
          if (!visited[e]) {
            S.push(e);
          }
        }
      }
    }
    connected[x][y].push_back(ans);
  }
  connected[y][x] = connected[x][y];
}

inline bool all_or_nothing(const ll& bit, const ll& con) {
  ll hanten = ((1ll << N) - 1) ^ bit;
  cerr << "bit = " << bit << ", con = " << con
       << ", hanten = " << hanten << endl;
  if ((bit & con) == con) {
    return true; 
  }
  return (((((1ll << N) - 1) ^ bit) & con) == con);
}

inline bool valid(key k) {
  const ll& bit = get<0>(k);
  const int& a = get<1>(k);
  const int& b = get<2>(k);
  for (auto& x : connected[a][b]) {
    if (!(all_or_nothing(bit, x))) return false;
  }
  return true;
}

inline int cnt_one(ll bit) {
  int cnt = 0;
  while (bit > 0) {
    if ((bit & 1ll) == 1) ++cnt;
    bit = (bit >> 1);
  }
  return cnt;
}

ll value(key k) {
  ll bit = get<0>(k);
  int c = cnt_one(bit);
  // if (c == 1) return 1;
  if (!valid(k)) return 0;
  if (c == 2) return 1;
  auto it = dp.find(k);
  if (it != dp.end()) return (*it).second;
  ll ans = 0;
  const int& a = get<1>(k);
  const int& b = get<2>(k);
  bit -= (1ll << b);
  for (auto i = 0; i < N; ++i) {
    if (i == a) continue;
    if ((bit & (1ll << i)) == 0) continue;
    ans += value(key(bit, i, a));
    ans %= M;    
  }
  dp[k] = ans;
  return ans;
}

int main () {
  cin >> N;
  for (auto i = 0; i < N-1; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
  }
  if (N == 1) {
    cout << 1 << endl;
    return 0;
  } else if (N == 2) {
    cout << 2 << endl;
    return 0;    
  }
  for (auto i = 0; i < N; ++i) {
    if (V[i].size() > 4) {
      cout << 0 << endl;
      return 0;
    }
  }
  for (auto i = 0; i < N; ++i) {
    for (auto j = i+1; j < N; ++j) {
      make_connected(i, j);
    }
  }
  ll ans = 0;
  for (auto i = 0; i < N; ++i) {
    for (auto j = 0; j < N; ++j) {
      if (i == j) continue;
      cerr << "i = " << i << ", j = " << j << ", val = "
           << value(key(((1ll << N) - 1), i, j)) << endl;
      ans += value(key(((1ll << N) - 1), i, j));
      ans %= M;
    }
  }
  cout << ans << endl;
}
