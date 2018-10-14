/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-10-14 21:11:05
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

int N;
string S[1010];

void paint(int x, int y)
{
  if (S[x][y] == '.')
  {
    for (auto k = 0; k < 4; k++)
    {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if (0 <= nx && nx < N && 0 <= ny && ny < N)
      {
        if (S[nx][ny] == 'X')
        {
          return;
        }
      }
    }
    S[x][y] = 'X';
  }
}

int main()
{
  cin >> N;
  string T;
  for (auto i = 0; i < N; i++)
  {
    T += ".";
  }
  for (auto i = 0; i < N; i++)
  {
    S[i] = T;
  }
  int r[5] = {0, 3, 1, 4, 2};
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < N; j++)
    {
      if (j % 5 == r[i % 5])
      {
        S[i][j] = 'X';
      }
    }
  }
  for (auto i = 0; i < N; i++)
  {
    paint(0, i);
    paint(N - 1, i);
    paint(i, 0);
    paint(i, N - 1);
  }
  int cnt = 0;
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < N; j++)
    {
      if (S[i][j] == 'X')
      {
        cnt++;
      }
    }
  }
  for (auto i = 0; i < N; i++)
  {
    cout << S[i] << endl;
  }
  cerr << "cnt = " << cnt << endl;
}