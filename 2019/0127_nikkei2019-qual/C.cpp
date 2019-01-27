/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 1/27/2019, 9:07:00 PM
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

int N = 0;
ll A[100010];
ll B[100010];
typedef tuple<ll, ll, ll> T;
T C[100010];
ll ans = 0;

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> A[i] >> B[i];
    C[i] = T(A[i] + B[i], A[i], B[i]);
  }
  sort(C, C + N);
  reverse(C, C + N);
  for (auto i = 0; i < N; i++)
  {
    if (i % 2 == 0)
    {
      ans += get<1>(C[i]);
    }
    else
    {
      ans -= get<2>(C[i]);
    }
  }
  cout << ans << endl;
}