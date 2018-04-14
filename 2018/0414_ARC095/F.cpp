/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-4-14 21:58:25
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

int N;
vector<int> V[100010];
int visited[100010];
vector<int> path;
vector<int> ans;
vector<int> ans2;

int longest(int v)
{
  fill(visited, visited+100010, -1);
  queue<int> Q;
  Q.push(v);
  visited[v] = 0;
  while (!Q.empty())
  {
    int now = Q.front();
    Q.pop();
    for (auto x : V[now])
    {
      if (visited[x] == -1)
      {
        visited[x] = visited[now] + 1;
        Q.push(x);
      }
    }
  }
  int maxi = 0;
  int max_t = v;
  for (auto i = 0; i < N; i++)
  {
    assert(visited[i] >= 0);
    if (visited[i] > maxi)
    {
      maxi = visited[i];
      max_t = i;
    }
  }
  return max_t;
}

int main()
{
  cin >> N;
  for (auto i = 0; i < N-1; i++)
  {
    int v, w;
    cin >> v >> w;
    v--;
    w--;
    V[v].push_back(w);
    V[w].push_back(v);
  }
  int start = longest(0);
  int goal = longest(start);
  assert(V[start].size() == 1 && V[goal].size() == 1);
  longest(start);
  int dist = visited[goal];
  int now = goal;
  path.push_back(goal);
  while (dist > 0)
  {
    // cerr << "dist = " << dist << ", now = " << now << endl;
    for (auto x : V[now])
    {
      // cerr << "visited[" << x << "] = " << visited[x] << endl;
      if (visited[x] == dist - 1)
      {
        now = x;
        path.push_back(now);
        dist--;
        break;
      }
    }
  }
  reverse(path.begin(), path.end());
  int S = path.size();
  int cnt = 2;
  for (auto i = 1; i < S - 1; i++)
  {
    assert(V[path[i]].size() >= 2);
    // cerr << "V[" << path[i] << "].size() = " << V[path[i]].size() << endl;
    cnt += V[path[i]].size() - 1;
  }
  if (cnt != N)
  {
    // cerr << "N = " << N << ", cnt = " << cnt << endl;
    assert(cnt < N);
    cout << -1 << endl;
    return 0;
  }
  ans.push_back(1);
  int num = 1;
  for (auto i = 1; i < S - 1; i++)
  {
    int subtree = V[path[i]].size() - 1;
    vector<int> X;
    for (auto j = 1; j < subtree; j++)
    {
      X.push_back(j);
    }
    X.push_back(0);
    for (auto i = 0; i < subtree; i++)
    {
      ans.push_back(X[i] + num + 1);
    }
    num += subtree;
  }
  assert(num + 1 == N);
  ans.push_back(num + 1);
  assert((int)ans.size() == N);
  //
  reverse(path.begin(), path.end());
  ans2.push_back(1);
  num = 1;
  for (auto i = 1; i < S - 1; i++)
  {
    int subtree = V[path[i]].size() - 1;
    vector<int> X;
    for (auto j = 1; j < subtree; j++)
    {
      X.push_back(j);
    }
    X.push_back(0);
    for (auto i = 0; i < subtree; i++)
    {
      ans2.push_back(X[i] + num + 1);
    }
    num += subtree;
  }
  ans2.push_back(num + 1);
  for (auto i = 0; i < N; i++)
  {
    if (ans[i] > ans2[i]) {
      swap(ans, ans2);
      break;
    } else if (ans[i] < ans2[i]) {
      break;
    }
  }
  for (auto i = 0; i < N; i++)
  {
    cout << ans[i];
    if (i < N-1)
    {
      cout << " ";
    }
    else
    {
      cout << endl;
    }
  }
}