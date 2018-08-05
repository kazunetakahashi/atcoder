/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-8-5 21:17:59
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

int main()
{
  int D, G;
  cin >> D >> G;
  G /= 100;
  vector<int> p;
  vector<int> c;
  for (auto i = 0; i < D; i++)
  {
    int x, y;
    cin >> x >> y;
    p.push_back(x);
    c.push_back(y / 100);
  }
  int ans = 1000000000;
  for (auto i = 0; i < (1 << D); i++)
  {
    int cnt = 0;
    int score = 0;
    for (auto j = 0; j < D; j++)
    {
      if ((i >> j) & 1)
      {
        cnt += p[j];
        score += p[j] * (j + 1) + c[j];
      }
    }
    if (score >= G)
    {
      ans = min(ans, cnt);
      continue;
    }
    for (auto j = D - 1; j >= 0; j--)
    {
      if (!((bool)((i >> j) & 1)))
      {
        int tmp = p[j];
        while (tmp > 0)
        {
          score += j + 1;
          tmp--;
          cnt++;
          if (score >= G)
          {
            ans = min(ans, cnt);
            break;
          }
        }
        break;
      }
    }
  }
  cout << ans << endl;
}