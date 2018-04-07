/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-4-7 15:32:10
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
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define DEBUG 1 // change 0 -> 1 if we need debug.

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
const int infty = 1000000007;

int N, M, L, X;
int a[1010];
int DP[1010];
int DP2[1010];
int sum;

int main()
{
  cin >> N >> M >> L >> X;
  for (auto i = 0; i < N; i++)
  {
    cin >> a[i];
  }
  int maxi = (X - 1) * M + L;
  fill(DP, DP + M, infty);
  DP[0] = 0;
  for (auto i = 0; i < N; i++)
  {
    fill(DP2, DP2 + M, infty);
    for (auto j = 0; j < M; j++)
    {
      if (DP[j] == infty)
        continue;
      sum = DP[j] + a[i];
      DP2[sum % M] = min(DP[sum % M], sum);
    }
    for (auto j = 0; j < M; j++)
    {
      DP[j] = DP2[j];
    }
#if DEBUG == 1
    for (auto j = 0; j < M; j++)
    {
      cerr << DP[j] << " ";
    }
    cerr << endl;
#endif
  }
  cout << ((DP[L] <= maxi) ? "Yes" : "No") << endl;
}