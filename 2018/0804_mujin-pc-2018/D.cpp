/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-8-4 21:41:00
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

int N, M;
int cnt[1010][1010];

int rev(int k)
{
  string S = to_string(k);
  reverse(S.begin(), S.end());
  return stoi(S);
}

int calc(int x, int y)
{
  if (cnt[x][y] != -1)
  {
    return cnt[x][y];
  }
  if (x == 0 || y == 0)
  {
    return cnt[x][y] = 0;
  }
  cnt[x][y] = -2;
  int new_x = rev(x);
  int new_y = rev(y);
  if (new_x < new_y)
  {
    new_y = new_y - new_x;
  }
  else
  {
    new_x = new_x - new_y;
  }
  int k = calc(new_x, new_y);
  if (k == -2)
  {
    return cnt[x][y] = -2;
  }
  else
  {
    return cnt[x][y] = k + 1;
  }
}

int main()
{
  cin >> N >> M;
  fill(&cnt[0][0], &cnt[0][0] + 1010 * 1010, -1);
  int ans = 0;
  for (auto i = 0; i <= N; i++)
  {
    for (auto j = 0; j <= M; j++)
    {
      if (calc(i, j) == -2)
      {
        ans++;
      }
    }
  }
  cout << ans << endl;
}