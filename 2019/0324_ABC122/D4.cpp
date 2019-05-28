#define DEBUG 1

/**
 * File    : D4.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-28 12:34:39
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
const ll MOD = 1000000007;

set<string> forbid;
vector<string> C = {"A", "G", "C", "T"};
map<string, ll> M[110];
int N;

void make_string(string S)
{
  if (S.size() == 4)
  {
    for (auto k = 0; k < 2; k++)
    {
      string s = S.substr(k, 3);
      if (s == "AGC")
      {
        forbid.insert(S);
        return;
      }
    }
    for (auto l = 0; l < 3; l++)
    {
      string T = S;
      swap(T[l], T[l + 1]);
      for (auto k = 0; k < 2; k++)
      {
        string s = T.substr(k, 3);
        if (s == "AGC")
        {
          forbid.insert(S);
          return;
        }
      }
    }
    return;
  }
  for (auto x : C)
  {
    make_string(S + x);
  }
}

int main()
{
  cin >> N;
  make_string("");
  M[0]["TTT"] = 1;
  for (auto i = 0; i < N; i++)
  {
    for (auto e : M[i])
    {
      string S = e.first;
      ll cnt = e.second;
      if (cnt == 0)
      {
        break;
      }
      for (auto x : C)
      {
        string T = S + x;
        string U = T.substr(1, 3);
        if (forbid.find(T) == forbid.end())
        {
          if (M[i + 1].find(U) == M[i + 1].end())
          {
            M[i + 1][U] = cnt;
          }
          else
          {
            M[i + 1][U] += cnt;
            M[i + 1][U] %= MOD;
          }
        }
      }
    }
  }
  ll ans = 0;
  for (auto x : M[N])
  {
    ans += x.second;
    ans %= MOD;
  }
  cout << ans << endl;
}