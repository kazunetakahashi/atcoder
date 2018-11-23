/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 11/23/2018, 9:02:28 PM
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

int N;

bool ok(int x, int y)
{
  int X = 2 * x;
  int Y = 2 * y;
  return (-X + N <= Y && Y <= -X + 3 * N && X - N <= Y && Y <= X + N);
}

bool valid(int x, int y)
{
  return (ok(x, y) && ok(x + 1, y) && ok(x, y + 1) && ok(x + 1, y + 1));
}

int main()
{
  cin >> N;
  int ans = 0;
  for (auto x = 0; x < N; x++)
  {
    for (auto y = 0; y < N; y++)
    {
      if (valid(x, y))
      {
        ans++;
      }
    }
  }
  cout << ans << endl;
}