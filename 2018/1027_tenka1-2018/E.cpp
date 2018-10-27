/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-10-27 22:01:40
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

const int C = 610;
// const ll M = 1000000007;

int H, W;
string S[310];
bool X[C][C];

int value(int x, int y)
{
  return (0 <= x && x < C && 0 <= y && y < C && X[x][y]);
}

int main()
{
  cin >> H >> W;
  for (auto i = 0; i < H; i++)
  {
    cin >> S[i];
  }
  fill(&X[0][0], &X[0][0] + C * C, false);
  for (auto i = 0; i < H; i++)
  {
    for (auto j = 0; j < W; j++)
    {
      if (S[i][j] == '#')
      {
        X[i + j][i - j + C / 2] = true;
      }
    }
  }
  ll ans = 0;
  for (auto i = 0; i < C; i++)
  {
    for (auto j = 0; j < C; j++)
    {
      for (auto l = 1; l < C; l++)
      {
        int cnt_x = 0;
        cnt_x += value(i - l, j);
        cnt_x += value(i + l, j);
        int cnt_y = 0;
        cnt_y += value(i, j - l);
        cnt_y += value(i, j + l);
        ans += cnt_x * cnt_y;
        if (H < 10 && cnt_x > 0 && cnt_y > 0)
        {
          cerr << "now: (" << i << ", " << j << ")" << endl;
          if (value(i - l, j) > 0)
          {
            cerr << "(" << i - l << ", " << j << ")" << endl;
          }
          if (value(i + l, j) > 0)
          {
            cerr << "(" << i + l << ", " << j << ")" << endl;
          }
          if (value(i, j - l) > 0)
          {
            cerr << "(" << i << ", " << j - l << ")" << endl;
          }
          if (value(i, j + l) > 0)
          {
            cerr << "(" << i << ", " << j + l << ")" << endl;
          }
        }
      }
    }
  }
  assert(ans % 6 == 0);
  cout << ans / 6 << endl;
}