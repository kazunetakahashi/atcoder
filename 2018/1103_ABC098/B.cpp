/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-11-3 11:49:10
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

int N;
string S;

int main()
{
  cin >> N >> S;
  int ans = 0;
  for (auto i = 0; i < N; i++)
  {
    string X[2] = {S.substr(0, i), S.substr(i, N - i)};
    bool A[2][26];
    fill(&A[0][0], &A[0][0] + 26 * 2, false);
    for (auto k = 0; k < 2; k++)
    {
      for (auto x : X[k])
      {
        A[k][x - 'a'] = true;
      }
    }
    int t_ans = 0;
    for (auto i = 0; i < 26; i++)
    {
      if (A[0][i] && A[1][i])
      {
        t_ans++;
      }
    }
    ans = max(ans, t_ans);
  }
  cout << ans << endl;
}
