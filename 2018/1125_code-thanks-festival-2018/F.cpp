/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 11/25/2018, 12:58:28 PM
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

int N, M, K;
int P[310];
int root = 0;
vector<int> children[310];
int cnt_c[310];

int calc_c(int v)
{
  cnt_c[v] = 0;
  for (auto x : children[v])
  {
    cnt_c[v] += calc_c(x);
  }
  return cnt_c[v] + 1;
}

int main()
{
  cin >> N >> M >> K;
  for (auto i = 0; i < N; i++)
  {
    cin >> P[i];
    P[i]--;
  }
  for (auto i = 0; i < N; i++)
  {
    if (P[i] == -1)
    {
      root = i;
    }
    else
    {
      children[P[i]].push_back(i);
    }
  }
  assert(calc_c(root) == N);
  
}