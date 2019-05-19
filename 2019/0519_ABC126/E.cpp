#define DEBUG 1

/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 5/19/2019, 9:22:36 PM
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

int N, M;
vector<int> V[100010];
bool visited[100010];

bool dfs(int v)
{
  if (visited[v])
  {
    return false;
  }
  visited[v] = true;
  for (auto x : V[v])
  {
    dfs(x);
  }
  return true;
}

int main()
{
  cin >> N >> M;
  for (auto i = 0; i < M; i++)
  {
    int x, y, z;
    cin >> x >> y >> z;
    x--;
    y--;
    V[x].push_back(y);
    V[y].push_back(x);
  }
  fill(visited, visited + 100010, false);
  int ans = 0;
  for (auto i = 0; i < N; i++)
  {
    if (dfs(i))
    {
      ans++;
    }
  }
  cout << ans << endl;
}