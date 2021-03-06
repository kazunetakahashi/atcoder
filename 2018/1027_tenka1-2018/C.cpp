/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-10-27 20:57:45
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

int N;
vector<ll> X;
vector<ll> A;
ll start = 0;
ll B[100010];
ll ans = 0;

void solve()
{
  for (auto i = 0; i < N - 1; i++)
  {
    if (i % 2 == 0)
    {
      B[i] = A[i / 2];
    }
    else
    {
      B[i] = A[N - 1 - i / 2 - 1];
    }
  }
  ll sum = abs(start - B[0]);
  for (auto i = 0; i < N - 2; i++)
  {
    // cerr << "B[" << i << "] = " << B[i] << endl;
    sum += abs(B[i] - B[i + 1]);
  }
  ans = max(ans, sum);
}

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    ll x;
    cin >> x;
    X.push_back(x);
  }
  for (auto i = max(0, N / 2 - 1); i < min(N, N / 2 + 2); i++)
  {
    start = X[i];
    A.clear();
    for (auto j = 0; j < N; j++)
    {
      if (j != i)
      {
        A.push_back(X[j]);
      }
    }
    sort(A.begin(), A.end());
    solve();
    reverse(A.begin(), A.end());
    solve();
  }
  cout << ans << endl;
}