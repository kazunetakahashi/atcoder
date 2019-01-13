/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 1/13/2019, 9:11:50 PM
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
const ll MOD = 1000000007;

int N, M;
int A[1010];
int B[1010];
vector<int> V;
ll ans = 1;

int main()
{
  cin >> N >> M;
  for (auto i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  for (auto i = 0; i < M; i++)
  {
    cin >> B[i];
  }
  sort(A, A + N);
  reverse(A, A + N);
  sort(B, B + M);
  reverse(B, B + M);
  A[N] = 0;
  B[M] = 0;
  int ind_a = 0;
  int ind_b = 0;
  int P = 0;
  for (auto i = N * M; i >= 1; i--)
  {
    // cerr << "i = " << i << ", A[" << ind_a << "] = " << A[ind_a]
    // << ", B[" << ind_b << "] = " << B[ind_b] << endl;
    if (i == A[ind_a] && i == B[ind_b])
    {
      ind_a++;
      ind_b++;
      P++;
    }
    else if (i == A[ind_a])
    {
      ans *= ind_b;
      ans %= MOD;
      ind_a++;
      P++;
    }
    else if (i == B[ind_b])
    {
      ans *= ind_a;
      ans %= MOD;
      ind_b++;
      P++;
    }
    else if (ind_a * ind_b - P > 0)
    {
      ans *= ind_a * ind_b - P;
      ans %= MOD;
      P++;
    }
    else
    {
      cout << 0 << endl;
      return 0;
    }
  }
  cout << ans << endl;
}