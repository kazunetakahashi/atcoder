/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-7-1 22:00:11
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
#include <random> // random_device rd; mt19937 mt(rd());
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

typedef tuple<int, int> D;

int N;
int A[100010];
int DP[100010];
int DP2[100010];

set<D> S[100010];

void make_S(int i)
{
  if (!S[i].empty())
  {
    return;
  }
  S[i].insert(D(-A[0], 0));
  S[i].insert(D(-A[i], i));
  for (auto j = 0; j < N; j++)
  {
    int mask = (1 << N) - 1 - (1 << j);
    int new_i = mask & i;
    if (new_i == i || new_i == 0)
    {
      continue;
    }
    make_S(new_i);
    auto it = S[new_i].begin();
    S[i].insert(*it);
    it++;
    S[i].insert(*it);
  }
}

int main()
{
  cin >> N;
  for (auto i = 0; i < (1 << N); i++)
  {
    cin >> A[i];
  }
  for (auto i = 0; i < (1 << N); i++)
  {
    make_S(i);
    auto it = S[i].begin();
    // cerr << "i = " << i << endl;
    // cerr << "(" << -get<0>(*it) << ", " << get<1>(*it) << ")" << endl;
    DP2[i] = -(get<0>(*it));
    it++;
    // cerr << "(" << -get<0>(*it) << ", " << get<1>(*it) << ")" << endl;
    DP2[i] += -(get<0>(*it));
  }
  // flush
  DP[0] = 0;
  for (auto i = 1; i < (1 << N); i++)
  {
    DP[i] = max(DP[i - 1], DP2[i]);
    cout << DP[i] << endl;
  }
}