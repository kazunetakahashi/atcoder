#define DEBUG 1

/**
 * File    : D2.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-26 00:08:10
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

int N, M;
ll A[100010];
ll B[100010];
ll C[100010];
typedef tuple<ll, ll> T;
vector<T> V;

int main()
{
  cin >> N >> M;
  for (auto i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  for (auto i = 0; i < M; i++)
  {
    cin >> B[i] >> C[i];
  }
  for (auto i = 0; i < N; i++)
  {
    V.push_back(T(A[i], 1));
  }
  for (auto i = 0; i < M; i++)
  {
    V.push_back(T(C[i], B[i]));
  }
  ll cnt = N;
  ll ans = 0;
  sort(V.begin(), V.end());
  reverse(V.begin(), V.end());
  for (auto x : V)
  {
    ll val = get<0>(x);
    ll c = get<1>(x);
    ans += val * min(c, cnt);
    cnt -= min(c, cnt);
    if (cnt == 0)
    {
      break;
    }
  }
  cout << ans << endl;
}