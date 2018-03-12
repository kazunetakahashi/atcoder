/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-3-12 16:05:13
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

int grundy(int a, int k)
{
  #if DEBUG == 1
  cerr << "a = " << a << ", k = " << k << endl;
  #endif
  if (a % k == 0)
    return a / k;
  int d = a / k;
  int x = (a - k * d) / (d + 1) + 1;
  x = min(a / (d + 1), x);
  for (auto i = 1; i <= x; i++)
  {
    if ((a - i * (d + 1)) % k == 0)
    {
      return (a - i * (d + 1)) / k;
    }
  }
  return grundy(a - x * (d + 1), k);
}

int main()
{
  int N;
  int A[210];
  int K[210];
  int g[210];
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> A[i] >> K[i];
    g[i] = grundy(A[i], K[i]);
  }
  int x = 0;
  for (auto i = 0; i < N; i++)
  {
    x = x ^ g[i];
  }
  if (x != 0)
  {
    cout << "Takahashi" << endl;
  }
  else
  {
    cout << "Aoki" << endl;
  }
}