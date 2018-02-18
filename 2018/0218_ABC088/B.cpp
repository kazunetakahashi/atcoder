/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-2-18 21:02:21
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
  int N;
  cin >> N;
  int a[1010];
  for (auto i = 0; i < N; i++)
  {
    cin >> a[i];
  }
  sort(a, a + N);
  reverse(a, a + N);
  int A = 0, B = 0;
  for (auto i = 0; i < N; i++)
  {
    if (i%2 == 0) {
      A += a[i];
    } else {
      B += a[i];
    }
  }
  cout << A - B << endl;
}