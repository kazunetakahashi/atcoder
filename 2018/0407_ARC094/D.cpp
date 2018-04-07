/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-4-7 21:10:12
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
// const ll M = 1000000007;

ll A, B;

int solve()
{
  ll S = A * B;
  if (A > B)
    swap(A, B);
  if (S <= 2)
    return 0;
  int X = sqrt(S);
  return 2 * X - 1;
}

int main()
{
  int Q;
  cin >> Q;
  for (auto i = 0; i < Q; i++)
  {
    cin >> A >> B;
    cout << solve() << endl;
  }
}