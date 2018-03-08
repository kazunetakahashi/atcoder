/**
 * File    : A.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-3-8 21:12:11
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
double x[110], y[110];

double dist(double a, double b)
{
  return sqrt(a * a + b * b);
}

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> x[i] >> y[i];
  }
  double ans = 0;
  for (auto i = 0; i < N; i++)
  {
    for (auto j = i + 1; j < N; j++)
    {
      ans = max(ans, dist(x[i] - x[j], y[i] - y[j]));
    }
  }
  cout << fixed << setprecision(6) << ans << endl;
}