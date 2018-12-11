/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 12/11/2018, 10:53:23 PM
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

ll cnt(ll X)
{
  string S = to_string(X);
  while ((int)S.size() < 20)
  {
    S = "0" + S;
  }
  cerr << S << endl;
  ll DP[21][2][2]; // digit, equal?, 4-9?
  fill(&DP[0][0][0], &DP[0][0][0] + 21 * 2 * 2, 0);
  DP[0][1][0] = 1;
  for (auto i = 1; i < 21; i++)
  {
    if (S[i - 1] == '4' || S[i - 1] == '9')
    {
      DP[i][1][1] += DP[i - 1][1][0];
      DP[i][1][1] += DP[i - 1][1][1];
    }
    else
    {
      DP[i][1][0] += DP[i - 1][1][0];
      DP[i][1][1] += DP[i - 1][1][1];
    }
    int x = S[i - 1] - '0';
    for (auto j = 0; j < x; j++)
    {
      if (j == 4 || j == 9)
      {
        DP[i][0][1] += DP[i - 1][1][0];
        DP[i][0][1] += DP[i - 1][1][1];
      }
      else
      {
        DP[i][0][0] += DP[i - 1][1][0];
        DP[i][0][1] += DP[i - 1][1][1];
      }
    }
    DP[i][0][0] += 8 * DP[i][0][0];
    DP[i][0][1] += 2 * DP[i][0][0];
    DP[i][0][1] += 10 * DP[i][0][1];
  }
  return DP[20][0][1] + DP[20][1][1];
}

int main()
{
  ll A, B;
  cin >> A >> B;
  cout << cnt(B) - cnt(A - 1) << endl;
}