#define DEBUG 1

/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-25 21:27:40
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

int Q;
char c;
ll a, b;
ll A = 0;
ll B = 0;
ll cnt_l = 0;
ll cnt_r = 0;
ll lower = -1000000000000LL;
priority_queue<ll> L;
priority_queue<ll, vector<ll>, greater<ll>> R;

void merge()
{
  ll x = L.top();
  ll y = R.top();
  if (a <= x)
  {
    L.push(a);
  }
  else if (a >= y)
  {
    R.push(a);
  }
  else
  {
    L.push(a);
  }
  while (L.size() > R.size())
  {
    ll t = L.top();
    L.pop();
    R.push(t);
  }
  while (L.size() < R.size())
  {
    ll t = R.top();
    R.pop();
    L.push(t);
  }
  B += b;
  if (a < 0)
  {
    cnt_l++;
    A += abs(a);
  }
  else if (a > 0)
  {
    cnt_r++;
    A += abs(a);
  }
}

void flush()
{
  ll val = L.top();
  ll ans = A + B;
  ll dist = abs(val);
  ll c = abs(cnt_l - cnt_r);
  ans -= dist * c;
  cout << val << " " << ans << endl;
}

int main()
{
  cin >> Q;
  L.push(-1000000000000LL);
  R.push(1000000000000LL);
  for (auto i = 0; i < Q; i++)
  {
    cin >> c;
    if (c == '1')
    {
      cin >> a >> b;
      merge();
    }
    else
    {
      flush();
    }
  }
}