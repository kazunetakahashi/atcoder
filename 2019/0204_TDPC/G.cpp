/**
 * File    : G.cpp
 * Author  : Kazune Takahashi
 * Created : 2/9/2019, 5:25:56 PM
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
const ll infty = 1000000000000000010;

string S;
ll L;
ll K;

ll DP[1000010];
ll pos[1000010][26];

int main()
{
  cin >> S >> K;
  L = S.size();
  DP[L] = 1;
  for (auto i = 0; i < 26; i++)
  {
    pos[L][i] = -1;
  }
  for (auto i = L - 1; i >= 0; i--)
  {
    for (auto j = 0; j < 26; j++)
    {
      pos[i][j] = pos[i + 1][j];
    }
    pos[i][S[i] - 'a'] = i + 1;
  }
  for (auto i = L - 1; i >= 0; i--)
  {
    DP[i] = 1;
    for (auto j = 0; j < 26; j++)
    {
      if (pos[i][j] >= 0)
      {
        DP[i] += DP[pos[i][j]];
        if (DP[i] > infty)
        {
          DP[i] = infty;
          break;
        }
      }
    }
  }
  K++;
  if (K > DP[0])
  {
    cout << "Eel" << endl;
    return 0;
  }
  string ans = "";
  for (auto i = 0; i < L; i++)
  {
    for (auto j = 0; j < 26; j++)
    {
      if (pos[i][j] >= 0)
      {
        if (K > DP[pos[i][j]])
        {
          K -= DP[pos[i][j]];
        }
        else if (K > 0)
        {
          string t{(char)('a' + j)};
          ans += t;
          K--;
          break;
        }
        else
        {
          cout << ans << endl;
          return 0;
        }
      }
    }
  }
  cout << ans << endl;
}