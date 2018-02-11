/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-2-11 15:47:35
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

string S;
vector<bool> V;

bool ok(int K)
{
  vector<bool> W = V;
  int now = 0;
  while (now < (int)V.size() - K)
  {
    if (W[now])
    {
      now++;
    }
    else
    {
      for (auto saki = now + K; saki < (int)V.size(); saki++)
      {
        if (!W[saki])
        {
          W[now] = !W[now];
          W[saki] = !W[saki];
          now = saki;
          break;
        }
        else
        {
          saki++;
        }
      }
      if (!W[now])
      {
        break;
      }
    }
  }
  for (auto x : W)
  {
    if (!x)
    {
      return false;
    }
  }
  return true;
}

int main()
{
  cin >> S;
  S = "0" + S + "0";
  for (auto i = 0; i < (int)S.size() - 1; i++)
  {
    V.push_back(S[i] == S[i - 1]);
  }
  int lb = 1;
  int ub = S.size() + 1;
  while (ub - lb > 1)
  {
    int t = (ub + lb) / 2;
    if (ok(t))
    {
      lb = t;
    }
    else
    {
      ub = t;
    }
  }
  cout << lb << endl;
}