#define DEBUG 1

/**
 * File    : F2.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-26 02:29:52
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
ll A, B;
priority_queue<ll> L;
priority_queue<ll, vector<ll>, greater<ll>> R;
ll a, b;

void merge()
{
  B += b;
  L.push(a);
  R.push(b);
  if (L.top() <= R.top())
  {
    // nothing
  }
  else
  {
    ll l = L.top();
    ll r = R.top();
    A += abs(l - r);
    L.pop();
    R.pop();
    L.push(r);
    R.push(l);
  }
}

void flush()
{
  cout << L.top() << " " << A + B << endl;
}

int main()
{
  cin >> Q;
  for (auto i = 0; i < Q; i++)
  {
    char c;
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