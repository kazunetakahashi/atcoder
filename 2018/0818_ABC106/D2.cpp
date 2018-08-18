/**
 * File    : D2.cpp
 * Author  : Kazune Takahashi
 * Created : 8/18/2018, 9:08:51 PM
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
#include <random> // auto rd = bind(uniform_int_distribution<int>(0, 9), mt19937(19920725));
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

int N, M, Q;

typedef tuple<int, int> que;

vector<int> seg[510];
vector<que> X[510];
int imos[510][510];
int ans[100010];

int main()
{
  cin >> N >> M >> Q;
  for (auto i = 0; i < M; i++)
  {
    int l, r;
    cin >> l >> r;
    seg[r].push_back(l);
  }
  for (auto i = 0; i < Q; i++)
  {
    int l, r;
    cin >> l >> r;
    X[r].push_back(que(l, i));
  }
  fill(&imos[0][0], &imos[0][0] + 510 * 510, 0);
  for (auto r = 1; r <= N; r++)
  {
    for (auto x : seg[r])
    {
      imos[r][x]++;
    }
    for (int i = r - 1; i >= 0; i--)
    {
      imos[r][i] += imos[r][i + 1];
    }
    if (r > 0)
    {
      for (auto i = 0; i < r; i++)
      {
        imos[r][i] += imos[r - 1][i];
      }
    }
    for (auto x : X[r])
    {
      int l = get<0>(x);
      int ind = get<1>(x);
      ans[ind] = imos[r][l];
    }
  }
  for (auto i = 0; i < Q; i++)
  {
    cout << ans[i] << endl;
  }
}