/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 11/24/2018, 8:10:20 PM
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
ll a[1010];
ll sum[1010];
vector<ll> V;

int main()
{
  cin >> N >> K;
  for (auto i = 0; i < N; i++)
  {
    cin >> a[i];
  }
  sum[0] = 0;
  for (auto i = 0; i < N; i++)
  {
    sum[i + 1] = sum[i] + a[i];
  }
  for (auto i = 0; i <= N; i++)
  {
    for (auto j = 0; j < i; j++)
    {
      V.push_back(sum[i] - sum[j]);
    }
  }
  for (auto x : V)
  {
    cerr << x << endl;
  }
  int L = V.size();
  for (int i = 60 - 1; i >= 0; i--)
  {
    int cnt = 0;
    for (auto j = 0; j < L; j++)
    {
      if ((V[j] >> i) & 1)
      {
        cnt++;
      }
    }
    if (cnt >= K)
    {
      cerr << "i = " << i << ", cnt = " << cnt << endl;
      auto it = V.begin();
      while (it != V.end())
      {
        if (((*it) >> 1) & 1)
        {
          it++;
        }
        else
        {
          it = V.erase(it);
        }
      }
    }
  }
  ll ans = V[0];
  for (auto i = 0; i < K; i++)
  {
    ans = ans & V[i];
  }
  cout << ans << endl;
}