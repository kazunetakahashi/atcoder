/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-5-26 21:11:43
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

int N;
int A[200010];
ll X[200010];

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  int l = 0, r = 0;
  int sum = 0;
  while (l < N)
  {
    while (r < N && (sum + A[r] == (sum & A[r])))
    {
      sum += A[r++];
    }
    X[l] = r - 1;
    sum -= A[l++];
  }
  ll ans = 0;
  for (auto i = 0; i < N; i++)
  {
    ans += X[i] - i + 1;
  }
  cout << ans << endl;
}