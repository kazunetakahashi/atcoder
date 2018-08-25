/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-8-25 20:45:21
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
ll x[100010];
vector<ll> V[2];

int main()
{
  cin >> N >> K;
  for (auto i = 0; i < N; i++)
  {
    cin >> x[i];
  }
  for (auto i = 0; i < N; i++)
  {
    if (x[i] > 0)
    {
      V[0].push_back(x[i]);
    }
    else
    {
      V[1].push_back(-x[i]);
    }
  }
  sort(V[1].begin(), V[1].end());
  ll ans = 100000000000000;
  for (auto i = 0; i < 2; i++)
  {
    if ((int)V[i].size() >= K)
    {
      ans = min(ans, V[i][K - 1]);
    }
  }
  for (auto k = 0; k <= K; k++)
  {
    int l = K - k;
    if ((int)V[0].size() >= k && l >= 0 && (int)V[1].size() >= l)
    {
      ans = min(ans, V[0][k - 1] + 2 * V[1][l - 1]);
      ans = min(ans, 2 * V[0][k - 1] + V[1][l - 1]);
    }
  }
  cout << ans << endl;
}