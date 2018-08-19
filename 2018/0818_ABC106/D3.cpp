/**
 * File    : D3.cpp
 * Author  : Kazune Takahashi
 * Created : 8/19/2018, 8:27:56 PM
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

int N, M, Q;
int L[200010];
int R[200010];
int p[100010];
int q[100010];
int imos[510][510];

int main()
{
  cin >> N >> M >> Q;
  for (auto i = 0; i < M; i++)
  {
    cin >> L[i] >> R[i];
  }
  for (auto i = 0; i < Q; i++)
  {
    cin >> p[i] >> q[i];
  }
  fill(&imos[0][0], &imos[0][0] + 510 * 510, 0);
  for (auto i = 0; i < M; i++)
  {
    imos[L[i]][R[i]]++;
  }
  for (auto i = 1; i <= N; i++)
  {
    for (auto j = 1; j <= N; j++)
    {
      imos[i][j] += imos[i][j - 1] + imos[i - 1][j] - imos[i - 1][j - 1];
    }
  }
  for (auto i = 0; i < Q; i++)
  {
    cout << imos[q[i]][q[i]] - imos[p[i] - 1][q[i]] << endl;
  }
}