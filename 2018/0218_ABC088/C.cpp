/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-2-18 21:04:53
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

int main()
{
  int c[100][100];
  for (auto i = 0; i < 3; i++)
  {
    for (auto j = 0; j < 3; j++)
    {
      cin >> c[i][j];
    }
  }
  for (auto i = 0; i < 2; i++)
  {
    if (!(c[i+1][0] - c[i][0] == c[i+1][1] - c[i][1]
        && c[i+1][1] - c[i][1] == c[i+1][2] - c[i][2])) {
      cout << "No" << endl;
      return 0;
    }
  }
 for (auto i = 0; i < 2; i++)
  {
    if (!(c[0][i+1] - c[0][i] == c[1][i+1] - c[1][i]
        && c[1][i+1] - c[1][i] == c[2][i+1] - c[2][i])) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}