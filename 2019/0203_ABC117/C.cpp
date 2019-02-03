/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2/3/2019, 9:04:54 PM
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

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

ll N, M;
ll X[100010];
ll Y[100010];

int main()
{
  cin >> N >> M;
  for (auto i = 0; i < M; i++)
  {
    cin >> X[i];
  }
  if (N >= M)
  {
    cout << 0 << endl;
    return 0;
  }
  sort(X, X + M);
  for (auto i = 0; i < M - 1; i++)
  {
    Y[i] = X[i + 1] - X[i];
  }
  sort(Y, Y + M - 1);
  ll sum = 0;
  for (auto i = 0; i < M - N; i++)
  {
    sum += Y[i];
  }
  cout << sum << endl;
}