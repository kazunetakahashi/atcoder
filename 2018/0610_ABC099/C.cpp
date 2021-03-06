/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-6-10 21:04:50
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
#include <random> // random_device rd; mt19937 mt(rd());
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

set<int> S;
int X[100010];

int main()
{
  int N;
  cin >> N;
  fill(X, X + 100010, 200010);
  int x = 1;
  while (x < 100010)
  {
    S.insert(x);
    x *= 6;
  }
  x = 1;
  while (x < 100010)
  {
    S.insert(x);
    x *= 9;
  }
  X[0] = 0;
  for (auto i = 0; i < N; i++)
  {
    for (auto x : S)
    {
      if (i + x < 100010)
      {
        X[i + x] = min(X[i + x], X[i] + 1);
      }
    }
  }
  cout << X[N] << endl;
}