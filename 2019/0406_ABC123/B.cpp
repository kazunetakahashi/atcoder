#define DEBUG 1

/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 4/6/2019, 9:03:49 PM
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

int A[5];
int B[5];

int main()
{
  for (auto i = 0; i < 5; i++)
  {
    cin >> A[i];
  }
  for (auto i = 0; i < 5; i++)
  {
    B[i] = A[i] % 10;
  }
  sort(B, B + 5);
  if (B[4] == 0)
  {
    int ans = 0;
    for (auto i = 0; i < 5; i++)
    {
      ans += A[i];
    }
    cout << ans << endl;
  }
  else
  {
    for (auto i = 0; i < 5; i++)
    {
      A[i] = (A[i] + 9) / 10 * 10;
    }
    int amari = 0;
    for (auto i = 0; i < 5; i++)
    {
      if (B[i] > 0)
      {
        amari = B[i];
        break;
      }
    }
    int ans = -10;
    for (auto i = 0; i < 5; i++)
    {
      ans += A[i];
    }
    cout << ans + amari << endl;
  }
}