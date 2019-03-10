#define DEBUG 1

/**
 * File    : E2.cpp
 * Author  : Kazune Takahashi
 * Created : 3/10/2019, 2:26:12 PM
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
#include <functional>
#include <random> // auto rd = bind(uniform_int_distribution<int>(0, 9), mt19937(10101010));
#include <chrono> // std::chrono::system_clock::time_point start_time, end_time;
// start = std::chrono::system_clock::now();
// double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time).count();
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

class UnionFind
{
public:
  vector<long long> par;

  UnionFind(int n) : par(n, -1) {}
  void init(int n)
  {
    par.assign(n, -1);
  }

  int root(int x)
  {
    if (par[x] < 0)
    {
      return x;
    }
    return par[x] = root(par[x]);
  }

  bool is_same(int x, int y)
  {
    return root(x) == root(y);
  }

  bool merge(int x, int y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
    {
      return false;
    }
    if (par[x] > par[y])
    {
      swap(x, y);
    }
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  long long size(int x)
  {
    return -par[root(x)];
  }
};

int N, M;
ll X[100010];
int A[100010];
int B[100010];
ll Y[100010];
typedef tuple<ll, int, int, bool> edge;
vector<edge> V;
vector<int> W[100010];
typedef tuple<ll, int> task;
vector<task> T;

void dfs(ll cost, int v)
{
  if (W[v].empty())
  {
    return;
  }
  for (auto i : W[v])
  {
    edge x = V[i];
    ll score = get<0>(x);
    int a = get<1>(x);
    int b = get<2>(x);
    int dst = ((a == v) ? b : a);
    if (get<3>(x))
    {
      continue;
    }
    if (cost >= score)
    {
      get<3>(x) = true;
      if (!W[dst].empty())
      {
        dfs(cost, dst);
      }
    }
  }
  W[v].clear();
}

int main()
{
  cin >> N >> M;
  for (auto i = 0; i < N; i++)
  {
    cin >> X[i];
  }
  for (auto i = 0; i < M; i++)
  {
    cin >> A[i] >> B[i] >> Y[i];
    A[i]--;
    B[i]--;
    V.push_back(edge(Y[i], A[i], B[i], false));
  }
  sort(V.begin(), V.end());
  for (auto i = 0; i < M; i++)
  {
    edge x = V[i];
    int a = get<1>(x);
    int b = get<2>(x);
    W[a].push_back(i);
    W[b].push_back(i);
  }
  UnionFind UF(N);
  for (auto i = 0; i < N; i++)
  {
    UF.par[i] = -X[i];
  }
  for (auto i = 0; i < M; i++)
  {
    edge x = V[i];
    ll cost = get<0>(x);
    int a = get<1>(x);
    int b = get<2>(x);
    ll score = 0;
    if (UF.is_same(a, b))
    {
      score = UF.size(a);
    }
    else
    {
      score = UF.size(a) + UF.size(b);
      UF.merge(a, b);
    }
    if (score >= cost)
    {
      T.push_back(task(cost, a));
    }
  }
#if DEBUG == 1
  cerr << "Here" << endl;
#endif
  reverse(T.begin(), T.end());
  for (auto x : T)
  {
    dfs(get<0>(x), get<1>(x));
  }
  int ans = 0;
  for (auto i = 0; i < M; i++)
  {
    if (!get<3>(V[i]))
    {
      ans++;
    }
  }
  cout << ans << endl;
}