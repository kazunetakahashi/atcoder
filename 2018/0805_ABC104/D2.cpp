/**
 * File    : D2.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-8-6 21:43:08
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
const ll M = 1000000007;

string S;
int N;
ll DP[100010][4];

void calc(int i, char x)
{
  int l = x - 'A';
  for (auto k = 0; k < 4; k++)
  {
    DP[i][k] += DP[i - 1][k];
    DP[i][k] %= M;
  }
  DP[i][l + 1] += DP[i][l];
  DP[i][l + 1] %= M;
}

void calc(int i)
{
  char x = S[i - 1];
  if (x == '?')
  {
    calc(i, 'A');
    calc(i, 'B');
    calc(i, 'C');
  }
  else
  {
    calc(i, x);
  }
}

int main()
{
  cin >> S;
  N = S.size();
  fill(&DP[0][0], &DP[0][0] + 100010 * 4, 0);
  DP[0][0] = 1;
  for (auto i = 1; i <= N; i++)
  {
    calc(i);
  }
  cout << DP[N][3] << endl;
}