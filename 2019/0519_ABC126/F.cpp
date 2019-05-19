#define DEBUG 1

/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 5/19/2019, 9:28:18 PM
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
#include <random> // auto rd = bind(uniform_int_distribution<int>(0, 9), mt19937(10101010));
#include <chrono> // std::chrono::system_clock::time_point start_time, end_time;
// start = std::chrono::system_clock::now();
// double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time).count();
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

int x[100010];

void test(ll M, ll K)
{
  cerr << "K = " << K << endl;
  for (auto i = 0; i < (1 << (M + 1)); i++)
  {
    x[i] = i / 2;
  }
  do
  {
    bool ok = true;
    for (auto i = 0; i < (1 << M); i++)
    {
      int start = 0;
      int goal = 0;
      for (auto j = 0; j < (1 << (M + 1)); j++)
      {
        if (x[i] == i)
        {
          start = j;
          break;
        }
      }
      for (auto j = (1 << (M + 1)) - 1; j >= 0; j--)
      {
        if (x[i] == i)
        {
          goal = j;
          break;
        }
      }
      int v = 0;
      for (auto j = start; j <= goal; j++)
      {
        v = v ^ j;
      }
      if (v != K)
      {
        ok = false;
        break;
      }
    }
    if (ok)
    {
      for (auto i = 0; i < (1 << (M + 1)); i++)
      {
        cerr << x[i] << " ";
      }
      cerr << endl;
      return;
    }
  } while (next_permutation(x, x + (1 << (M + 1))));
}

ll M, K;

int main()
{
  cin >> M >> K;
#if DEBUG == 1
  for (auto k = 0; k < (1 << M); k++)
  {
    test(M, k);
  }
#endif
  if (K != 0)
  {
    cout << -1 << endl;
  }
  else
  {
    for (auto i = 0; i < (1 << (M + 1)); i++)
    {
      cout << i / 2;
      if (i < (1 << (M + 1)) - 1)
      {
        cout << " ";
      }
      cout << endl;
    }
  }
}