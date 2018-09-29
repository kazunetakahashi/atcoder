/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-9-29 21:23:01
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
string S;
int parent[100010];

void no()
{
  cout << -1 << endl;
  exit(0);
}

void yes()
{
  for (auto i = 0; i < N; i++)
  {
    if (parent[i] != -1)
    {
      cout << i + 1 << " " << parent[i] + 1 << endl;
    }
  }
  exit(0);
}

int main()
{
  cin >> S;
  N = S.size();
  if (S[N - 1] == '1')
  {
    no();
  }
  for (auto i = 0; i < N - 2; i++)
  {
    int j = N - 2 - i;
    if (S[i] != S[j])
    {
      no();
    }
  }
  if (S[0] == '0')
  {
    no();
  }
  int M = N / 2;
  int now = 0;
  for (auto i = 0; i < M; i++)
  {
    if (S[i] == '1')
    {
      parent[now] = i + 1;
      now = i + 1;
      parent[now] = -1;
    }
    else
    {
      parent[i + 1] = now;
    }
  }
  for (auto i = M; i < N - 1; i++)
  {
    parent[i + 1] = now;
  }
  yes();
}