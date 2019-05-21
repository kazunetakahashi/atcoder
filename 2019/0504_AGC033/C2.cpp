#define DEBUG 1

/**
 * File    : C2.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-21 22:20:49
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
int visited[200010];

void dfs(int v, int d)
{
  if (visited[v] >= 0)
  {
    return;
  }
  visited[v] = d;
  for (auto x : V[v])
  {
    dfs(x, d + 1);
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
    V[a].push_back(b);
    V[b].push_back(a);
  }
  fill(visited, visited + N, -1);
  dfs(0, 0);
  int maxi = 0;
  int ind = 0;
  for (auto i = 0; i < N; i++)
  {
    if (visited[i] > maxi)
    {
      maxi = visited[i];
      ind = i;
    }
  }
  fill(visited, visited + N, -1);
  dfs(ind, 0);
  maxi = 0;
  for (auto i = 0; i < N; i++)
  {
    if (visited[i] > maxi)
    {
      maxi = visited[i];
    }
  }
  if (maxi % 3 == 1)
  {
    cout << "Second" << endl;
  }
  else
  {
    cout << "First" << endl;
  }
}