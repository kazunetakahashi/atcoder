#define DEBUG 1

/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2/17/2019, 1:05:05 PM
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
#include <random> // auto rd = bind(uniform_int_distribution<int>(0, 9), mt19937(10101010));
#include <chrono> // std::chrono::system_clock::time_point start_time, end_time;
// start = std::chrono::system_clock::now();
// double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time).count();
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
const ll infty = 1000000000000000010;

ll H[2], K;
ll R[100010];
ll C[100010];
ll X[2][100010];

int main()
{
  cin >> H[0] >> H[1] >> K;
  for (auto i = 0; i < K; i++)
  {
    cin >> R[i] >> C[i];
    R[i]--;
    C[i]--;
  }
  sort(R, R + K);
  sort(C, C + K);
  fill(&X[0][0], &X[0][0] + 100010 * 2, 0);
  for (auto i = 0; i < K; i++)
  {
    X[0][R[i]]++;
  }
  for (auto i = 0; i < K; i++)
  {
    X[1][C[i]]++;
  }
  ll mini[2] = {infty, infty};
  for (auto k = 0; k < 2; k++)
  {
    ll sum = 0;
    for (auto i = 0LL; i < H[k]; i++)
    {
      X[k][i] = H[1 - k] - X[k][i];
      sum += i * X[k][i];
    }
    mini[k] = sum;
    ll passed = 0;
    ll remain = H[0] * H[1] - K;
    for (auto i = 0; i < H[k] - 1; i++)
    {
      passed += X[k][i];
      remain -= X[k][i];
      sum = sum + passed - remain;
      mini[k] = min(mini[k], sum);
    }
  }
  cout << mini[0] + mini[1] << endl;
}