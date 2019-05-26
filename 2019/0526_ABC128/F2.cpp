#define DEBUG 1

/**
 * File    : F2.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-27 01:10:29
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

int N;
ll s[100010];
ll ans = 0;

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> s[i];
  }
  for (auto C = 1; C < N; C++)
  {
    set<int> S;
    ll score = 0;
    int x = 0;
    while (true)
    {
      if (x * C >= N)
      {
        break;
      }
      int A = (N - 1) - x * C;
      int B = A - C;
      if (B <= 0)
      {
        break;
      }
      int forward = N - 1 - x * C;
      if (S.find(forward) != S.end())
      {
        break;
      }
      score += s[forward];
      S.insert(forward);
      int back = x * C;
      if (S.find(back) != S.end())
      {
        break;
      }
      score += s[back];
      S.insert(back);
      ans = max(ans, score);
      x++;
    }
  }
  cout << ans << endl;
}