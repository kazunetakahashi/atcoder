#define DEBUG 1

/**
 * File    : D3.cpp
 * Author  : Kazune Takahashi
 * Created : 4/7/2019, 12:33:27 AM
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

ll X[3];
ll K;
ll A[3][1010];
vector<ll> ans;
typedef tuple<int, int, int> point;
set<point> S;
typedef tuple<ll, point> D;
priority_queue<D> Q;

int main()
{
  for (auto i = 0; i < 3; i++)
  {
    cin >> X[i];
  }
  cin >> K;
  for (auto i = 0; i < 3; i++)
  {
    for (auto j = 0; j < X[i]; j++)
    {
      cin >> A[i][j];
    }
    A[i][X[i]] = -(ll)1e17;
    X[i]++;
  }
  for (auto i = 0; i < 3; i++)
  {
    sort(A[i], A[i] + X[i]);
    reverse(A[i], A[i] + X[i]);
  }
  Q.push(D(A[0][0] + A[1][0] + A[2][0], point(0, 0, 0)));
  S.insert(point(0, 0, 0));
  for (auto i = 0; i < K; i++)
  {
    ll v = get<0>(Q.top());
    ll x = get<0>(get<1>(Q.top()));
    ll y = get<1>(get<1>(Q.top()));
    ll z = get<2>(get<1>(Q.top()));
    Q.pop();
    cout << v << endl;
    for (auto j = 0; j < 3; j++)
    {
      if (j == 0)
      {
        x++;
      }
      else if (j == 1)
      {
        y++;
      }
      else
      {
        z++;
      }
      point p = point(x, y, z);
      if (S.find(p) == S.end())
      {
        Q.push(D(A[0][x] + A[1][y] + A[2][z], p));
        S.insert(p);
      }
      if (j == 0)
      {
        x--;
      }
      else if (j == 1)
      {
        y--;
      }
      else
      {
        z--;
      }
    }
  }
}
