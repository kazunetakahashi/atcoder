/**
 * File    : A.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-11-10 15:20:13
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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

int N, M, L;
string S[500];
string T[29];

void input()
{
  cin >> N >> M >> L;
  for (auto i = 0; i < N; i++)
  {
    cin >> S[i];
  }
}

void make_wall()
{
  string wall = "";
  for (auto i = 0; i < M; i++)
  {
    wall += "#";
  }
  for (auto i = 0; i < M; i++)
  {
    T[i] = wall;
  }
  T[14][14] = '.';
}

void flush()
{
  for (auto i = 0; i < M; i++)
  {
    cout << T[i] << endl;
  }
}

void solve(int k)
{
  assert(1 <= k && k <= 13);
  for (auto i = 1; i <= k; i++)
  {
    for (auto t = 0; t < 4; t++)
    {
      int x = M / 2 + dx[t] * i;
      int y = M / 2 + dy[t] * i;
      T[x][y] = '.';
    }
  }
}

int main()
{
  input();
  make_wall();
  solve(9);
  flush();
}