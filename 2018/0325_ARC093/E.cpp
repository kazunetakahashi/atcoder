/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-3-25 21:58:58
 * Powered by Visual Studio Code
 */

#include <iostream>
#include <iomanip>   // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple>
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set>
#include <random> // random_device rd; mt19937 mt(rd());
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

const int MAX_SIZE = 1000010;
const long long MOD = 1000000007;

long long inv[MAX_SIZE];
long long fact[MAX_SIZE];
long long factinv[MAX_SIZE];

const int UFSIZE = 100010;
int union_find[UFSIZE];

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

void init() {
  inv[1] = 1;
  for (int i=2; i<MAX_SIZE; i++) {
    inv[i] = ((MOD - inv[MOD%i]) * (MOD/i))%MOD;
  }
  fact[0] = factinv[0] = 1;
  for (int i=1; i<MAX_SIZE; i++) {
    fact[i] = (i * fact[i-1])%MOD;
    factinv[i] = (inv[i] * factinv[i-1])%MOD;
  }
  for (auto i=0; i<UFSIZE; i++) {
    union_find[i] = i;
  }
}

long long C(int n, int k) {
  if (n >=0 && k >= 0 && n-k >= 0) {
    return ((fact[n] * factinv[k])%MOD * factinv[n-k])%MOD;
  }
  return 0;
}

long long power(long long x, long long n) {
  if (n == 0) {
    return 1;
  } else if (n%2 == 1) {
    return (x * power(x, n-1)) % MOD;
  } else {
    long long half = power(x, n/2);
    return (half * half) % MOD;
  }
}

long long gcm(long long a, long long b) {
  if (a < b) {
    return gcm(b, a);
  }
  if (b == 0) return a;
  return gcm(b, a%b);
}

typedef tuple<ll, int, int> edge;
typedef tuple<ll, int> path;

int N, M;
ll X;
vector<edge> V;
vector<path> T[1010];
vector<edge> W;

path parent[10][1010];
int depth[1010];

void dfs(int v, int p, ll cost, int d)
{
  parent[0][v] = path(cost, p);
  depth[v] = d;
  for (auto x : T[v])
  {
    if (get<1>(x) != p)
    {
      dfs(get<1>(x), v, get<0>(x), d + 1);
    }
  }
}

void init2()
{
  dfs(0, -1, 0, 0);
  for (auto k = 0; k+1 < 10; k++)
  {
    for (auto v = 0; v < N; v++)
    {
      if (get<1>(parent[k][v]) < 0)
      {
        parent[k + 1][v] = path(0, -1);
      }
      else
      {
        ll cost = get<0>(parent[k][v]);
        int u = get<1>(parent[k][v]);
        int new_u = get<1>(parent[k][u]);
        ll new_cost = max(cost, get<0>(parent[k][u]));
        parent[k + 1][v] = path(new_cost, new_u);
#if DEBUG == 1
        cerr << "parent[" << k + 1 << "][" << v << "] = (" << new_cost << ", " << new_u << ")" << endl;
#endif
      }
    }
  }
}

ll lca(int u, int v)
{
  if (depth[u] > depth[v])
    swap(u, v);
  ll ans = 0;
#if DEBUG == 1
  cerr << "depth[" << u << "] = " << depth[u]
       << ", depth[" << v << "] = " << depth[v] << endl;
#endif
  for (auto k = 0; k < 10; k++)
  {
    if ((depth[v] - depth[u]) >> k & 1)
    {
      ans = max(ans, get<0>(parent[k][v]));
      v = get<1>(parent[k][v]);
    }
  }
  if (u == v)
    return ans;
  for (auto k = 9; k >= 0; k--)
  {
    if (get<1>(parent[k][u]) != get<1>(parent[k][v]))
    {
      ans = max(ans, get<0>(parent[k][u]));
      ans = max(ans, get<0>(parent[k][v]));
      u = get<1>(parent[k][u]);
      v = get<1>(parent[k][v]);
    }
  }
  ans = max(ans, get<0>(parent[0][v]));
  ans = max(ans, get<0>(parent[0][u]));
  return ans;
}

int main()
{
  init();
  cin >> N >> M;
  cin >> X;
  for (auto i = 0; i < M; i++)
  {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--;
    v--;
    V.push_back(edge(w, u, v));
  }
  sort(V.begin(), V.end());
  ll Y = 0;
  for (auto e : V)
  {
    ll cost = get<0>(e);
    int u = get<1>(e);
    int v = get<2>(e);
    if (!issame(u, v))
    {
      unite(u, v);
      T[u].push_back(path(cost, v));
      T[v].push_back(path(cost, u));
      Y += cost;
    }
    else
    {
      W.push_back(e);
    }
  }
#if DEBUG == 1
  cerr << "X = " << X << ", Y = " << Y << endl;
#endif
  if (X < Y)
  {
    cout << 0 << endl;
    return 0;
  }
  ll ans = 0;
  ll K = N - 1;
  ll L = W.size();
  if (X == Y)
  {
    ans = (((power(2, K) + MOD - 2) % MOD) * power(2, L)) % MOD;
  }
#if DEBUG == 1
  cerr << "L = " << L << ", ans = " << ans << endl;
#endif
  init2();
  ll L1 = 0;
  ll L2 = 0;
  for (auto e : W)
  {
    ll cost = get<0>(e);
    int u = get<1>(e);
    int v = get<2>(e);
    ll temp = cost - lca(u, v);
    if (temp < X - Y)
      L2++;
    else if (temp == X - Y)
      L1++;
  }
#if DEBUG == 1
  cerr << "L1 = " << L1 << ", L2 = " << L2 << endl;
#endif
  ans += (2 * (power(2, L - L2) + MOD - power(2, L - L2 - L1))) % MOD;
  ans %= MOD;
  cout << ans << endl;
}