#define DEBUG 1

/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 4/13/2019, 9:04:58 PM
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
// const ll M = 1000000007;

string S;
string T;
string U;

int main()
{
  cin >> S;
  int N = S.size();
  T = "", U = "";
  for (auto i = 0; i < N; i++)
  {
    if (i % 2 == 0)
    {
      T = T + "0";
      U = U + "1";
    }
    else
    {
      T = T + "1";
      U = U + "0";
    }
  }
  int ans = N;
  int t_ans = 0;
  for (auto i = 0; i < N; i++)
  {
    if (S[i] != T[i])
    {
      t_ans++;
    }
  }
  ans = min(ans, t_ans);
  t_ans = 0;
  for (auto i = 0; i < N; i++)
  {
    if (S[i] != U[i])
    {
      t_ans++;
    }
  }
  ans = min(ans, t_ans);
  cout << ans << endl;
}