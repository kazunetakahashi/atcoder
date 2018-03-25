/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-3-25 21:00:57
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
  int A[100010];
  A[0] = 0;
  for (auto i = 1; i <= N; i++)
  {
    cin >> A[i];
  }
  A[N + 1] = 0;
  int ans = 0;
  for (auto i = 0; i <= N; i++)
  {
    ans += abs(A[i] - A[i + 1]);
  }
  for (auto i = 1; i <= N; i++)
  {
    cout << ans - abs(A[i - 1] - A[i]) - abs(A[i] - A[i + 1]) + abs(A[i - 1] - A[i + 1]) << endl;
  }
}