/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-9-1 21:31:09
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

typedef tuple<int, int> path;

ll L;
int N;
vector<path> V[100];

void flush()
{
  int M;
  for (auto i = 0; i < N; i++)
  {
    M += (int)V[i].size();
  }
  cout << N << " " << M << endl;
  for (auto i = 0; i < N; i++)
  {
    for (auto x : V[i])
    {
      cout << i + 1 << " " << get<0>(x) + 1 << " " << get<1>(x) << endl;
    }
  }
}

void add_edge(int v, int w, int c)
{
  if (v > w)
  {
    swap(v, w);
  }
  V[v].push_back(path(w, c));
}

int main()
{
  cin >> L;
  N = 0;
  for (auto i = 0; i < 200; i++)
  {
    if ((L >> i) == 0)
    {
      N = i;
      break;
    }
  }
  assert(0 < N && N <= 20);
  int pow = 1;
  for (auto i = 0; i < N - 1; i++)
  {
    add_edge(i, i + 1, 0);
    add_edge(i, i + 1, pow);
    pow *= 2;
  }
  for (auto i = 0; i < N - 1; i++)
  {
    if ((L >> i) & 1)
    {
      int cost = L & (((1 << N) - 1) << (i + 1));
      add_edge(i, N - 1, cost);
    }
  }
  flush();
}