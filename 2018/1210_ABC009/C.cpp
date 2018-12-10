/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 12/10/2018, 10:44:34 PM
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

int N, K;
string S;
string T;
bool changed[110];

int main()
{
  cin >> N >> K >> S;
  T = S;
  sort(T.begin(), T.end());
  fill(changed, changed + 110, false);
  for (auto i = 0; i < N; i++)
  {
    if (S[i] == T[i])
    {
      continue;
    }
    if (K == 0)
    {
      break;
    }
    if (K >= 2 || changed[i])
    {
      if (!changed[i])
      {
        changed[i] = true;
        K--;
      }
      for (int j = N - 1; j >= 0; j--)
      {
        if (T[i] == S[j])
        {
          swap(S[i], S[j]);
          if (!changed[j])
          {
            changed[j] = true;
            K--;
          }
          break;
        }
      }
    }
    else
    {
      for (int j = N - 1; j >= 0; j--)
      {
        if (T[i] == S[j] && changed[j])
        {
          swap(S[i], S[j]);
          changed[i] = true;
          K--;
          break;
        }
      }
    }
  }
  cout << S << endl;
}