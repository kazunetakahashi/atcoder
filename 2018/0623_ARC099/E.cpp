/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-6-23 21:49:57
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
#include <chrono> // std::chrono::system_clock::time_point start_time, end_time;
// start = std::chrono::system_clock::now();
// double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time).count();
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

int N, M;
set<int> W[1000];
vector<int> V[1000];

vector<pair<int, int>> res;

int visited[1000];
int cnt[2];

bool nuri(int v, int k)
{
  visited[v] = k;
  for (auto x : V[v])
  {
    if (visited[x] == 0)
    {
      if (!nuri(x, 3 - k))
      {
        return false;
      }
    }
    else if (visited[x] == k)
    {
      return false;
    }
  }
  cnt[k - 1]++;
  return true;
}

bool reach[1000][1000];

int main()
{
  cin >> N >> M;
  for (auto i = 0; i < M; i++)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    W[a].insert(b);
    W[b].insert(a);
  }
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < N; j++)
    {
      if (i == j)
        continue;
      if (W[i].find(j) == W[i].end())
      {
        V[i].push_back(j);
        // cerr << "V[" << i << "].push_back(" << j << ")" << endl;
      }
    }
  }
  fill(visited, visited + 1000, 0);
  for (auto k = 0; k < N; k++)
  {
    if (visited[k] != 0)
    {
      continue;
    }
    cnt[0] = cnt[1] = 0;
    if (!nuri(k, 1))
    {
      cout << -1 << endl;
      return 0;
    }
    res.push_back(make_pair(cnt[0], cnt[1]));
  }
  fill(&reach[0][0], &reach[0][0] + 1000 * 1000, false);
  reach[0][0] = true;
  for (int i = 0; i < (int)res.size(); i++)
  {
    auto e = res[i];
    int x = e.first;
    int y = e.second;
    // cerr << "i = " << i << endl;
    // cerr << "x = " << x << ", y = " << y << endl;
    for (auto j = N; j >= 0; j--)
    {
      if (reach[i][j])
      {
        // cerr << "j = " << j << endl;
        reach[i + 1][x + j] = true;
        reach[i + 1][y + j] = true;
      }
    }
  }
  int ans = 1000000007;
  for (auto i = 0; i <= N; i++)
  {
    int j = N - i;
    if (reach[(int)res.size()][i])
    {
      ans = min(ans, i * (i - 1) / 2 + j * (j - 1) / 2);
    }
  }
  cout << ans << endl;
}
