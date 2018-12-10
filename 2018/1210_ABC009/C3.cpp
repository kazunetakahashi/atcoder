/**
 * File    : C3.cpp
 * Author  : Kazune Takahashi
 * Created : 12/10/2018, 11:23:26 PM
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
int cnt[26];
string T;

bool check(int j)
{
  if (cnt[j] == 0)
  {
    return false;
  }
  string tmp = {(char)('a' + j)};
  string U = T + tmp;
  int cnt_t[26];
  for (auto i = 0; i < 26; i++)
  {
    cnt_t[i] = cnt[i];
  }
  cnt_t[j]--;
  int k = U.size();
  int score = 0;
  for (auto i = 0; i < k; i++)
  {
    if (U[i] != S[i])
    {
      score++;
    }
  }
  for (auto i = k; i < N; i++)
  {
    if (cnt_t[S[i] - 'a'] > 0)
    {
      cnt_t[S[i] - 'a']--;
    }
    else
    {
      score++;
    }
  }
  return (score <= K);
}

int main()
{
  cin >> N >> K >> S;
  fill(cnt, cnt + 26, 0);
  for (auto x : S)
  {
    cnt[x - 'a']++;
  }
  T = "";
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < 26; j++)
    {
      if (check(j))
      {
        string tmp = {(char)('a' + j)};
        T = T + tmp;
        cnt[j]--;
        break;
      }
    }
  }
  cout << T << endl;
}