/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-10-27 20:58:14
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
int n;

void det()
{
  for (auto i = 1; i < 1000; i++)
  {
    if (i * (i + 1) / 2 == N)
    {
      n = i;
      cout << "Yes" << endl;
      return;
    }
  }
  cout << "No" << endl;
  exit(0);
}

int main()
{
  cin >> N;
  det();
  vector<vector<int>> V(n + 1, vector<int>(n));
  int now = 0;
  for (auto i = 0; i < n + 1; i++)
  {
    for (auto j = 0; j < i; j++)
    {
      V[i][j] = V[j][i - 1];
    }
    for (auto j = i; j < n; j++)
    {
      V[i][j] = now++;
    }
  }
  assert(now == N);
  cout << n + 1 << endl;
  for (auto i = 0; i < n + 1; i++)
  {
    cout << n << " ";
    for (auto j = 0; j < n; j++)
    {
      cout << V[i][j] + 1;
      if (j < n - 1)
      {
        cout << " ";
      }
      else
      {
        cout << endl;
      }
    }
  }
}