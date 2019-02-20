#define DEBUG 1

/**
 * File    : D4.cpp
 * Author  : Kazune Takahashi
 * Created : 2/21/2019, 12:09:38 AM
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

const string base = "-";

void char_max(string &a, string b)
{
  if (a == base)
  {
    a = b;
  }
  else if (a.size() < b.size())
  {
    a = b;
  }
  else if (a.size() == b.size() && a < b)
  {
    a = b;
  }
}

ll X[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string DP[10010];
int N, M;
ll A[10];

int main()
{
  cin >> N >> M;
  for (auto i = 0; i < M; i++)
  {
    cin >> A[i];
  }
  for (auto i = 0; i < 10010; i++)
  {
    DP[i] = base;
  }
  DP[0] = "";
  for (auto i = 0; i <= N; i++)
  {
    if (DP[i] == base)
    {
      continue;
    }
    for (auto j = 0; j < M; j++)
    {
      char_max(DP[i + X[A[j]]], DP[i] + (char)('0' + A[j]));
    }
  }
  cout << DP[N] << endl;
}