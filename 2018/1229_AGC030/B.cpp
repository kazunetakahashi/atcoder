/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 12/29/2018, 9:05:34 PM
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

ll L;
int N;
ll X[200010];
ll ans;

void solve()
{
  sort(X, X + N);
  ans = min(ans, X[N - 1]);
  for (auto i = 0; i < N - 1; i++)
  {
    ans = min(ans, 2 * X[i] + L - X[i + 1]);
  }
}

int main()
{
  cin >> L >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> X[i];
  }
  ans = N * L * 10;
  solve();
  for (auto i = 0; i < N; i++)
  {
    X[i] = L - X[i];
  }
  solve();
  cout << ans << endl;
}