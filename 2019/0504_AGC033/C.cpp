#define DEBUG 1

/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 5/4/2019, 11:00:40 PM
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

int N;
vector<int> V[200010];
vector<int> children[200010];
stack<int> S;
int parent[200010];
int G[200010];

void dfs(int v)
{
  for (auto x : V[v])
  {
    if (parent[x] == -2)
    {
      parent[x] = v;
      dfs(x);
    }
  }
}

int g(int v)
{
  if (G[v] >= 0)
  {
    return G[v];
  }
  vector<int> cnt(3, 0);
  for (auto x : children[v])
  {
    cnt[g(x)]++;
  }
  if (cnt[0] >= 2)
  {
    return G[v] = 0;
  }
  if (cnt[0] == 1)
  {
    if (cnt[2] >= 1)
    {
      return G[v] = 2;
    }
    if (cnt[1] >= 1)
    {
      return G[v] = 1;
    }
    return G[v] = 2;
  }
  if (cnt[2] >= 2)
  {
    return G[v] = 1;
  }
  if (cnt[2] == 1)
  {
    if (cnt[1] >= 1)
    {
      return G[v] = 0;
    }
    return G[v] = 1;
  }
  if (cnt[1] >= 2)
  {
    return G[v] = 2;
  }
  if (cnt[1] == 1)
  {
    return G[v] = 0;
  }
  return G[v] = 1;
}

int main()
{
  cin >> N;
  for (auto i = 0; i < N - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }
  fill(parent, parent + N, -2);
  fill(G, G + N, -1);
  parent[0] = -1;
  dfs(0);
  for (auto i = 1; i < N; i++)
  {
    children[parent[i]].push_back(i);
  }
  g(0);
  if (G[0] == 0)
  {
    cout << "Second" << endl;
  }
  else
  {
    cout << "First" << endl;
  }
}