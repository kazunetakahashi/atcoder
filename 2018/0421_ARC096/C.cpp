/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-4-21 20:42:39
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

ll A, B, C, X, Y;

int main()
{
  cin >> A >> B >> C >> X >> Y;
  if (A + B <= 2 * C) {
    cout << A * X + B * Y << endl;
    return 0;
  }
  ll Z = 2 * min(A, B);
  X -= Z/2;
  Y -= Z/2;
  if (A > 2 * C) {
    Z += 2 * X;
    X = 0;
  }
  if (B > 2 * C) {
    Z += 2 * Y;
    Y = 0;
  }
  cout << A * X + B * Y + C * Z << endl;
  return 0;
}