/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-5-26 20:27:08
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

int N;
string S;
int sum[2][300010];
int cost[300010];

int main()
{
  cin >> N;
  cin >> S;
  for (auto i = 0; i < N; i++)
  {
    int x = (S[i] == 'W');
    sum[x][i] = 1;
    sum[1 - x][i] = 0;
  }
  for (auto i = 1; i < N; i++)
  {
    sum[0][i] += sum[0][i - 1];
  }
  for (auto i = N - 2; i >= 0; i--)
  {
    sum[1][i] += sum[1][i + 1];
  }
  cost[0] = sum[1][1];
  for (auto i = 1; i < N - 1; i++)
  {
    cerr << "cost[" << i << "] = " << sum[0][i - 1] << " + " << sum[1][i + 1] << endl;
    cost[i] = sum[0][i - 1] + sum[1][i + 1];
  }
  cost[N - 1] = sum[0][N - 2];
  int mini = N;
  for (auto i = 0; i < N; i++)
  {
    mini = min(mini, cost[i]);
  }
  cout << mini << endl;
}