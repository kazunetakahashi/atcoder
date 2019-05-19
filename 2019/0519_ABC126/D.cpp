#define DEBUG 1

/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 5/19/2019, 9:14:18 PM
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
typedef tuple<ll, int> edge;
vector<edge> V[100010];
int visited[100010];

void dfs(int v, int from, ll d)
{
  if (visited[v] >= 0)
  {
    return;
  }
  if (from == -1)
  {
    visited[v] = 0;
  }
  else
  {
    if (d % 2 == 0)
    {
      visited[v] = visited[from];
    }
    else
    {
      visited[v] = 1 - visited[from];
    }
  }
  for (auto x : V[v])
  {
    ll dist = get<0>(x);
    int w = get<1>(x);
    dfs(w, v, dist);
  }
}

int main()
{
  cin >> N;
  for (auto i = 0; i < N - 1; i++)
  {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--;
    v--;
    V[u].push_back(edge(w, v));
    V[v].push_back(edge(w, u));
  }
  fill(visited, visited + 100010, -1);
  dfs(0, -1, 0);
  for (auto i = 0; i < N; i++)
  {
    cout << visited[i] << endl;
  }
}