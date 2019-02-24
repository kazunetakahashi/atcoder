#define DEBUG 1

/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2/24/2019, 9:06:24 PM
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
const ll infty = 100000000000007;

int N;
ll A[3];
ll l[10];

int main()
{
  cin >> N >> A[0] >> A[1] >> A[2];
  for (auto i = 0; i < N; i++)
  {
    cin >> l[i];
  }
  ll ans = infty;
  for (auto i = 0; i < (1 << 2 * N); i++)
  {
    vector<ll> V[3];
    for (auto j = 0; j < N; j++)
    {
      bool x = (i >> (2 * j)) & 1;
      bool y = (i >> (2 * j + 1)) & 1;
      if (x && y)
      {
        V[0].push_back(l[j]);
      }
      else if (!x && y)
      {
        V[1].push_back(l[j]);
      }
      else if (x && !y)
      {
        V[2].push_back(l[j]);
      }
    }
    bool ok = true;
    for (auto j = 0; j < 3; j++)
    {
      if (V[j].empty())
      {
        ok = false;
        break;
      }
    }
    if (!ok)
    {
      continue;
    }
    ll t = 0;
    for (auto j = 0; j < 3; j++)
    {
      /*
#if DEBUG == 1
      cerr << "j = " << j << ": ";
      for (auto x : V[j])
      {
        cerr << x << " ";
      }
      cerr << endl;
#endif
*/
      ll sum = 0;
      for (auto x : V[j])
      {
        sum += x;
      }
      t += ((ll)V[j].size() - 1) * 10 + abs(A[j] - sum);
    }
    ans = min(ans, t);
  }
  cout << ans << endl;
}