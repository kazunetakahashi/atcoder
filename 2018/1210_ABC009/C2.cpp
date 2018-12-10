/**
 * File    : C2.cpp
 * Author  : Kazune Takahashi
 * Created : 12/10/2018, 10:56:51 PM
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

int N, K;
string S;
string T;

int score(int t)
{
  int score = 0;
  for (auto i = 0; i < t; i++)
  {
    if (S[i] != T[i])
    {
      score++;
    }
  }
  int cnt[26];
  fill(cnt, cnt + 26, 0);
  for (auto i = t; i < N; i++)
  {
    cnt[T[i] - 'a']++;
  }
  for (auto i = t; i < N; i++)
  {
    if (cnt[S[i] - 'a'] > 0)
    {
      cnt[S[i] - 'a']--;
    }
    else
    {
      score++;
    }
  }
  return score;
}

bool check(int t)
{
  return (score(t) <= K);
}

int main()
{
  cin >> N >> K >> S;
  T = S;
  sort(T.begin(), T.end());
  int now = 0;
  while (now < N)
  {
    int lb = now;
    int ub = N + 1;
    while (ub - lb > 1)
    {
      int t = (ub + lb) / 2;
      if (check(t))
      {
        lb = t;
      }
      else
      {
        ub = t;
      }
    }
    now = lb;
    if (now < N)
    {
      bool changed = false;
      for (int i = N - 1; i >= now; i--)
      {
        if (S[now] == T[i])
        {
          swap(T[i], S[now]);
          changed = true;
          break;
        }
      }
      if (!changed)
      {
        break;
      }
    }
  }
  cout << T << endl;
}