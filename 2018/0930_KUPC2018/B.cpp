/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-9-30 13:05:09
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
string c[100];
int start;

bool solve(string S)
{
  int now = start;
  for (auto i = 0; i < H - 1; i++)
  {
    if (S[i] == 'L')
    {
      now--;
    }
    else if (S[i] == 'R')
    {
      now++;
    }
    if (!(0 <= now && now < W))
    {
      return true;
    }
    if (c[i + 1][now] == 'x')
    {
      return false;
    }
  }
  return true;
}

vector<string> V[100];

int main()
{
  cin >> H >> W;
  for (auto i = 0; i < H; i++)
  {
    cin >> c[i];
  }
  reverse(c, c + H);
  for (auto i = 0; i < W; i++)
  {
    if (c[0][i] == 's')
    {
      start = i;
      break;
    }
  }
  V[0].push_back("");
  for (auto i = 0; i < H - 1; i++)
  {
    for (auto x : V[i])
    {
      V[i + 1].push_back(x + "L");
      V[i + 1].push_back(x + "R");
      V[i + 1].push_back(x + "S");
    }
  }
  for (auto x : V[H - 1])
  {
    if (solve(x))
    {
      cout << x << endl;
      return 0;
    }
  }
  cout << "impossible" << endl;
}