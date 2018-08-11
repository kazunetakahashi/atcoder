/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-8-11 21:03:52
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

ll N;

int main()
{
  cin >> N;
  bool bit[40];
  fill(bit, bit + 40, false);
  for (auto k = 0; k < 32; k++)
  {
    ll x = (1 << k);
    ll y = 2 * x;
    if (N % y != 0)
    {
      bit[k] = true;
      if (k % 2 == 0)
      {
        N -= x;
      }
      else
      {
        N += x;
      }
    }
    else
    {
      bit[k] = false;
    }
    if (N == 0)
    {
      break;
    }
  }
  int K = 0;
  for (int i = 40 - 1; i >= 0; i--)
  {
    if (bit[i])
    {
      K = i;
      break;
    }
  }
  string S = "";
  for (auto i = 0; i <= K; i++)
  {
    if (bit[i])
    {
      S = "1" + S;
    }
    else
    {
      S = "0" + S;
    }
  }
  cout << S << endl;
}