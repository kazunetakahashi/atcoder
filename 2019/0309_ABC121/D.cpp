#define DEBUG 1

/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 3/9/2019, 9:11:28 PM
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

ll A, B;

ll X(ll L)
{
  L++;
  ll ans = 0;
  if (ans % 4 == 1 || ans % 4 == 2)
  {
    ans++;
  }
  for (auto i = 1; i < 60; i++)
  {
    ll M = (1LL << (i + 1));
    ll cnt = L % M;
#if DEBUG == 1
    cerr << "M = " << M << ", cnt = " << cnt << endl;
#endif
    if (cnt >= M / 2)
    {
      cnt -= M / 2;
      if (cnt % 2 == 1)
      {
        ans += (1LL << i);
      }
    }
#if DEBUG == 1
    cerr << "ans = " << ans << endl;
#endif
  }
  return ans;
}

int main()
{
  cin >> A >> B;
  if (A == 0)
  {
    cout << X(B) << endl;
  }
  else
  {
    cout << (X(A - 1) ^ X(B)) << endl;
  }
}