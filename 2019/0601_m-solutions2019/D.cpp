#define DEBUG 1

/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-6-1 21:12:09
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

typedef tuple<int, int> X;

ll sum = 0;
int N;
ll c[10010];
int ind = 0;
bool visited[10010];
vector<int> V[10010];
ll assign[10010];

void dfs(int v)
{
  if (!visited[v])
  {
    visited[v] = true;
    assign[v] = c[ind++];
    for (auto x : V[v])
    {
      dfs(v);
    }
  }
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
    V[b].push_back(a);
    V[a].push_back(b);
  }
  for (auto i = 0; i < N; i++)
  {
    cin >> c[i];
  }
  sort(c, c + N);
  reverse(c, c + N);
  fill(visited, visited + N, false);
  dfs(0);
  for (auto i = 0; i < N; i++)
  {
    for (auto j : V[i])
    {
      sum += min(assign[i], assign[j]);
    }
  }
  cout << sum / 2 << endl;
  for (auto i = 0; i < N; i++)
  {
    cout << assign[i];
    if (i < N - 1)
    {
      cout << " ";
    }
    else
    {
      cout << endl;
    }
  }
}