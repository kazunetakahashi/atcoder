/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-8-4 21:05:06
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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

int N, M;
string S[2010];
ll cnt[2010][2010];
ll imos[2010][2010][4];

ll calc(int i, int j, int k)
{
  if (imos[i][j][k] != -1)
  {
    return imos[i][j][k];
  }
  if (!(0 <= i && i < N && 0 <= j && j < M))
  {
    return 0;
  }
  if (cnt[i][j] == 0)
  {
    return imos[i][j][k] = 0;
  }
  int new_i = i + dx[k];
  int new_j = j + dy[k];
  ll x = calc(new_i, new_j, k);
  return imos[i][j][k] = x + 1;
}

ll calc2(int i, int j, int k)
{
  ll x = calc(i, j, k);
  if (x > 0)
  {
    return x - 1;
  }
  return 0;
}

int main()
{
  cin >> N >> M;
  for (auto i = 0; i < N; i++)
  {
    cin >> S[i];
  }
  fill(&cnt[0][0], &cnt[0][0] + 2010 * 2010, 0);
  for (auto i = 1; i <= N; i++)
  {
    for (auto j = 1; j <= M; j++)
    {
      cnt[i][j] = ((S[i - 1][j - 1] == '.') ? 1 : 0);
    }
  }
  N += 2;
  M += 2;
  fill(&imos[0][0][0], &imos[0][0][0] + 2010 * 2010 * 4, -1);
  ll ans = 0;
  for (auto k = 0; k < 4; k++)
  {
    int new_k = (k + 1) % 4;
    for (auto i = 0; i < N; i++)
    {
      for (auto j = 0; j < M; j++)
      {
        ans += calc2(i, j, k) * calc2(i, j, new_k);
      }
    }
  }
  cout << ans << endl;
}