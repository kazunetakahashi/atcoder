/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-12-1 22:41:10
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

int N, C;
int s[100010];
int t[100010];
int c[100010];
bool broad[30][100010];
typedef tuple<int, int> X;
vector<X> V;
int ans = 0;

int main()
{
  cin >> N >> C;
  for (auto i = 0; i < N; i++)
  {
    cin >> s[i] >> t[i] >> c[i];
  }
  fill(&broad[0][0], &broad[0][0] + 30 * 100010, false);
  for (auto i = 0; i < N; i++)
  {
    for (auto j = s[i] - 1; j < t[i]; j++)
    {
      broad[c[i]][j] = true;
    }
  }
  for (auto i = 0; i < C; i++)
  {
    if (broad[i][0])
    {
      V.push_back(X(0, 1));
    }
    for (auto j = 1; j < 100010; j++)
    {
      if (broad[i][j - 1] && !broad[i][j])
      {
        V.push_back(X(j, 0));
      }
      else if (!broad[i][j - 1] && broad[i][j])
      {
        V.push_back(X(j, 1));
      }
    }
  }
  sort(V.begin(), V.end());
  int t = 0;
  for (auto x : V)
  {
    // cerr << "(" << get<0>(x) << ", " << get<1>(x) << ")" << endl;
    if (get<1>(x) == 0)
    {
      t--;
    }
    else
    {
      t++;
    }
    ans = max(ans, t);
  }
  cout << ans << endl;
}