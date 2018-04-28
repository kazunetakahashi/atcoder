/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-4-28 21:09:25
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

#define DEBUG 0 // change 0 -> 1 if we need debug.

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

int N;
string S[310];
string T[310];

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> S[i];
  }
  int ans = 0;
  for (auto i = 0; i < N; i++)
  {
    T[i] = "";
    for (auto j = 0; j < N; j++)
    {
      T[i] += S[j][i];
    }
  }
  for (auto k = 0; k < N; k++)
  {
    bool ok = true;
    for (auto i = 0; i < N; i++)
    {
      if (T[i] != S[(i + k) % N])
      {
        ok = false;
        break;
      }
    }
    if (ok)
    {
      ans++;
    }
    for (auto i = 0; i < N; i++)
    {
      T[i] = T[i].substr(1, N - 1) + T[i].substr(0, 1);
    }
  }
  cout << ans * N << endl;
}