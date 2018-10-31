/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-10-31 22:31:10
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

int H, W;
string S[110];
bool valid[110][110];

int main()
{
  cin >> H >> W;
  for (auto i = 0; i < H; i++)
  {
    cin >> S[i];
  }
  fill(&valid[0][0], &valid[0][0] + 110 * 110, true);
  for (auto i = 0; i < H; i++)
  {
    bool ok = true;
    for (auto j = 0; j < W; j++)
    {
      if (S[i][j] == '#')
      {
        ok = false;
      }
    }
    if (ok)
    {
      for (auto j = 0; j < W; j++)
      {
        valid[i][j] = false;
      }
    }
  }
  for (auto j = 0; j < W; j++)
  {
    bool ok = true;
    for (auto i = 0; i < W; i++)
    {
      if (S[i][j] == '#')
      {
        ok = false;
      }
    }
    if (ok)
    {
      for (auto i = 0; i < H; i++)
      {
        valid[i][j] = false;
      }
    }
  }
  for (auto i = 0; i < H; i++)
  {
    string X = "";
    for (auto j = 0; j < W; j++)
    {
      if (valid[i][j])
      {
        X = X + S[i].substr(j, 1);
      }
    }
    if (X != "")
    {
      cout << X << endl;
    }
  }
}