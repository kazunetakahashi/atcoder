#define DEBUG 1

/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-6-1 22:04:14
 * Powered by Visual Studio Code
 */

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <complex>
#include <tuple>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <random>
#include <chrono>
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

/*
void Yes()
{
  cout << "Yes" << endl;
  exit(0);
}

void No()
{
  cout << "No" << endl;
  exit(0);
}
*/

/*
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
*/

// const ll MOD = 1000000007;

class UnionFind
{
public:
  vector<long long> par;

  UnionFind() {}

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

int N;
bool A[2010][2010];
vector<int> V[2010];
vector<int> W[2010];
vector<int> X;
set<int> Y;
bool visited[2010];
UnionFind uf;

void dfs(int v)
{
  if (!visited[v])
  {
    visited[v] = true;
    for (auto x : V[v])
    {
      if (!visited[x])
      {
        dfs(x);
      }
    }
    X.push_back(v);
  }
}

void dfs2(int v)
{
  if (!visited[v])
  {
    visited[v] = true;
    for (auto x : W[v])
    {
      if (!visited[x])
      {
        dfs2(x);
        uf.merge(v, x);
      }
    }
  }
}

void dfs3(int v)
{
  if (!visited[v] && Y.find(v) != Y.end())
  {
    visited[v] = true;
    for (auto x : V[v])
    {
      if (!visited[x] && Y.find(v) != Y.end())
      {
        dfs3(x);
      }
    }
  }
}

int main()
{
  cin >> N;
  for (auto i = 1; i < N; i++)
  {
    for (auto j = 0; j < i; j++)
    {
      int x;
      cin >> x;
      A[i][j] = (x == 1);
      if (A[i][j])
      {
        V[j].push_back(i);
        W[i].push_back(j);
      }
      else
      {
        V[i].push_back(j);
        W[j].push_back(i);
      }
    }
  }
  fill(visited, visited + N, false);
  for (auto i = 0; i < N; i++)
  {
    dfs(i);
  }
  uf = UnionFind(N);
  reverse(X.begin(), X.end());
  fill(visited, visited + N, false);
  for (auto x : X)
  {
    dfs2(x);
  }
  for (auto i = 0; i < N; i++)
  {
    bool ok = true;
    for (auto j = 0; j < N; j++)
    {
      if (uf.is_same(i, j))
      {
        ok = false;
        break;
      }
    }
    if (ok)
    {
      Y.insert(i);
    }
  }
  for (auto x : Y)
  {
    fill(visited, visited + N, false);
    dfs3(x);
    bool ok = true;
    for (auto y : Y)
    {
      if (!visited[y])
      {
        ok = false;
        break;
      }
    }
    if (ok)
    {
      cout << uf.size(x) << endl;
      return 0;
    }
  }
}