/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-7-14 21:56:02
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
typedef tuple<string, string> P;
map<P, ll> M;
string T;

void make_dic()
{
  for (auto i = 0; i < (1 << N); i++)
  {
    string A = "", B = "";
    for (auto j = 0; j < N; j++)
    {
      if ((i >> j) & 1)
      {
        A = A + T[j];
      }
      else
      {
        B = B + T[j];
      }
    }
    auto it = P(A, B);
    if (M.find(it) == M.end())
    {
      M[it] = 1;
    }
    else
    {
      M[it]++;
    }
  }
}

ll cnt_dic()
{
  ll ans = 0;
  for (auto i = 0; i < (1 << N); i++)
  {
    string A = "", B = "";
    for (auto j = 0; j < N; j++)
    {
      if ((i >> j) & 1)
      {
        A = A + S[j];
      }
      else
      {
        B = B + S[j];
      }
    }
    auto it = P(A, B);
    if (M.find(it) != M.end())
    {
      if (N < 12)
      {
        cerr << "A = " << A << ", B = " << B
             << ", M = " << M[it] << endl;
      }
      ans += M[it];
    }
  }
  return ans;
}

int main()
{
  cin >> N >> S;
  T = S.substr(N, N);
  S = S.substr(0, N);
  make_dic();
  cout << cnt_dic() << endl;
}