/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-12-24 20:12:32
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

int N;
typedef tuple<ll, ll> P;
vector<vector<P>> V;

void flush()
{
  assert((int)V.size() == N);
  for (auto v : V)
  {
    assert((int)v.size() == 5);
    for (auto i = 0; i < 5; i++)
    {
      cout << get<0>(v[i]) << " " << get<1>(v[i]);
      if (i < 4)
      {
        cout << " ";
      }
      else
      {
        cout << endl;
      }
    }
  }
}

int main()
{
  cin >> N;
  int ub = 20;
  int lb = 20;
  for (auto i = 0; i < N; i++)
  {
    vector<P> v;
    v.push_back(P(-lb, -1000000000));
    lb += 2;
    v.push_back(P(ub, 1000000000));
    ub += 2;
    v.push_back(P(-lb, -1000000000));
    lb += 2;
    v.push_back(P(ub, 1000000000));
    ub += 2;
    v.push_back(P(-lb, -1000000000));
    lb += 2;
    V.push_back(v);
  }
  flush();
}