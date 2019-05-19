#define DEBUG 1

/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 5/19/2019, 9:06:56 PM
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

ll N, K;
ll P[100010];
ll cnt[50];

int main()
{
  cin >> N >> K;
  for (auto i = K; i <= N; i++)
  {
    P[i] = 0;
  }
  for (auto i = 1; i < K; i++)
  {
    ll t = i;
    while (t < K)
    {
      P[i]++;
      t *= 2;
    }
  }
  fill(cnt, cnt + 100, 0);
  for (auto i = 1; i <= N; i++)
  {
    cnt[P[i]]++;
  }
  double ans = 0;
  for (auto i = 0; i < 50; i++)
  {
    ll t = 1;
    for (auto j = 0; j < i; j++)
    {
      t *= 2;
    }
    ans += cnt[i] / (double)t;
  }
  ans /= N;
  cout << ans << endl;
}