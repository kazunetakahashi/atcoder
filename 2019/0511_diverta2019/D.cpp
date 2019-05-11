#define DEBUG 1

/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-11 21:31:45
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

ll N;
ll ans = 0;
vector<ll> V;

int main()
{
  cin >> N;
  for (auto i = 1LL; i < 1000010; i++)
  {
    if (N % i == 0 && N / i >= i)
    {
      if (N / i == i)
      {
        V.push_back(i);
      }
      else
      {
        V.push_back(i);
        V.push_back(N / i);
      }
    }
  }
  for (auto x : V)
  {
    ll m = x - 1;
    if (m > 0)
    {
      ll q = N / m;
      ll r = N % m;
      if (q == r)
      {
        ans += m;
      }
    }
  }
  cout << ans << endl;
}