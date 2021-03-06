#define DEBUG 1

/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 3/23/2019, 10:52:02 PM
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
const ll infty = 10000000000000007;

ll N, A, B;
int p[5010];
ll R[5010][5010];
ll L[5010][5010];
ll cost[5010][5010];

ll calc(int l, int r)
{
  if (cost[l][r] < infty)
  {
    return cost[l][r];
  }
  else if (l + 1 == r)
  {
    cost[l][r] = 0;
  }
  else
  {
    cost[l][r] = min(A, B * min(1LL, R[l][r - 1])) + calc(l + 1, r);
    cost[l][r] = min(cost[l][r], min(B, A * min(1LL, L[r - 1][l])) + calc(l, r - 1));
  }
#if DEBUG == 1
  cerr << "cost[" << l << "][" << r << "] = " << cost[l][r] << endl;
#endif
  return cost[l][r];
}

int main()
{
  cin >> N >> A >> B;
  for (auto i = 0; i < N; i++)
  {
    cin >> p[i];
    p[i]--;
  }
  fill(&cost[0][0], &cost[0][0] + 5010 * 5010, infty);
  for (auto i = 0; i < N; i++)
  {
    R[i][i] = 0;
    for (auto j = i + 1; j < N; j++)
    {
      R[i][j] = R[i][j - 1];
      if (p[i] > p[j])
      {
        R[i][j]++;
      }
#if DEBUG == 1
      cerr << "R[" << i << "][" << j << "] = " << R[i][j] << endl;
#endif
    }
  }
  for (auto i = 0; i < N; i++)
  {
    L[i][i] = 0;
    for (auto j = i - 1; j >= 0; j--)
    {
      L[i][j] = L[i][j + 1];
      if (p[i] < p[j])
      {
        L[i][j]++;
      }
#if DEBUG == 1
      cerr << "L[" << i << "][" << j << "] = " << L[i][j] << endl;
#endif
    }
  }
  cout << calc(0, N) << endl;
}