/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-5-20 21:05:39
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

int N;
int P[200010];

int solve()
{
  int now = 0;
  for (auto i = 0; i < N; i++)
  {
    if (P[i] == now + 1)
    {
      now++;
    }
  }
  return N - now;
}

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> P[i];
  }
  int ans = solve();
  reverse(P, P + 200010);
  for (auto i = 0; i < N; i++)
  {
    P[i] = N - P[i] + 1;
    cerr << "P[" << i << "] = " << P[i] << endl;
  }
  ans = min(ans, solve());
  cout << ans << endl;
}