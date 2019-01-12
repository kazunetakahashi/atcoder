/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 1/12/2019, 9:15:17 PM
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
const ll infty = 1000000007;

int N, Q;
ll A[100010];
ll X[100010];
set<ll> S;
map<ll, ll> M;
ll Y[100010];
ll Z[100010];

void flush()
{
  for (auto i = 0; i < Q; i++)
  {
    cout << M[X[i]] << endl;
  }
}

int main()
{
  cin >> N >> Q;
  for (auto i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  for (auto i = 0; i < Q; i++)
  {
    cin >> X[i];
    S.insert(X[i]);
  }
  reverse(A, A + N);
  Y[N + 1] = 0;
  Y[N] = 0;
  Y[N - 1] = A[N - 1];
  Y[N - 2] = A[N - 2];
  for (auto i = N - 3; i >= 0; i--)
  {
    Y[i] = A[i] + Y[i + 2];
  }
  Z[0] = A[0];
  for (auto i = 1; i < N; i++)
  {
    Z[i] = A[i] + Z[i - 1];
  }
  auto it = S.begin();
  for (auto i = N; i >= 0; i--)
  {
    int second = i / 2;
    int first = i - second;
    ll score;
    if (first == 0)
    {
      score = Y[0];
    }
    else if (first == second)
    {
      score = Z[first - 1] + Y[i];
    }
    else
    {
      score = Z[first - 1] + Y[i + 1];
    }
    ll upper;
    if (second == 0)
    {
      upper = infty;
    }
    else
    {
      ll maxi = A[first - 1];
      ll mini = A[first + second - 1];
      // cerr << "maxi = " << maxi << ", mini = " << mini << endl;
      upper = (maxi + mini + 1) / 2;
    }
    // cerr << "i = " << i << ", upper = " << upper << endl;
    while (it != S.end())
    {
      if (*it <= upper)
      {
        M[*it] = score;
        it++;
      }
      else
      {
        break;
      }
    }
  }
  flush();
}