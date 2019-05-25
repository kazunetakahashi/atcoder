#define DEBUG 1

/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-25 21:06:56
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
typedef tuple<ll, ll> spell;
ll A[100010];
spell S[100010];

int main()
{
  cin >> N >> M;
  for (auto i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  sort(A, A + N);
  for (auto i = 0; i < M; i++)
  {
    ll b, c;
    cin >> b >> c;
    S[i] = spell(c, b);
  }
  int ind = 0;
  int ind_s = 0;
  ll now = 0;
  int cnt = 0;
  while (ind < N)
  {
    if (cnt == 0)
    {
      if (ind_s >= M)
      {
        break;
      }
      now = get<0>(S[ind_s]);
      cnt = get<1>(S[ind_s]);
      ind_s++;
    }
    if (A[ind] < now)
    {
      A[ind] = now;
      ind++;
      cnt--;
    }
    else
    {
      break;
    }
  }
  ll ans = 0;
  for (auto i = 0; i < N; i++)
  {
    ans += A[i];
  }
  cout << ans << endl;
}