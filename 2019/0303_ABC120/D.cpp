#define DEBUG 1

/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 3/3/2019, 9:11:17 PM
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

// https://topcoder.g.hatena.ne.jp/iwiwi/20131226/1388062106 より。

ll N, M;
int A[100010];
int B[100010];

vector<int> i2g;
vector<vector<int>> g2i;

void init(int n)
{
  i2g.resize(n);
  g2i.resize(n);
  for (int i = 0; i < n; ++i)
  {
    i2g[i] = i;
    g2i[i].assign(1, i);
  }
}

void merge(int ia, int ib)
{
  if (g2i[i2g[ia]].size() < g2i[i2g[ib]].size())
  {
    swap(ia, ib);
  }
  int ga = i2g[ia], gb = i2g[ib];
  for (int j : g2i[gb])
  {
    i2g[j] = ga;
  }
  g2i[ga].insert(g2i[ga].end(), g2i[gb].begin(), g2i[gb].end());
  g2i[gb].clear();
}

bool is_same_group(int ia, int ib)
{
  return i2g[ia] == i2g[ib];
}

vector<int> ans;

int main()
{
  cin >> N >> M;
  for (auto i = 0; i < M; i++)
  {
    cin >> A[i] >> B[i];
    A[i]--;
    B[i]--;
  }
  reverse(A, A + M);
  reverse(B, B + M);
  init(N);
  ll cnt = N * (N - 1) / 2;
  ans.push_back(cnt);
  for (auto i = 0; i < M; i++)
  {
    if (is_same_group(A[i], B[i]))
    {
      ans.push_back(cnt);
    }
    else
    {
      int ga = i2g[A[i]], gb = i2g[B[i]];
      ll X = g2i[ga].size();
      ll Y = g2i[gb].size();
      cnt -= X * Y;
      ans.push_back(cnt);
      merge(A[i], B[i]);
    }
  }
  reverse(ans.begin(), ans.end());
  for (auto i = 0; i <= M; i++)
  {
    if (i == 0)
    {
      assert(ans[i] == 0);
    }
    else
    {
      cout << ans[i] << endl;
    }
  }
}