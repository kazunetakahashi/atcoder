#define DEBUG 1

/**
 * File    : A.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-6-2 20:42:31
 * Powered by Visual Studio Code
 */

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <complex>
#include <tuple>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <random>
#include <chrono>
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

void Yes()
{
  cout << "Yes" << endl;
  exit(0);
}

void No()
{
  cout << "No" << endl;
  exit(0);
}

/*
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
*/

// const ll MOD = 1000000007;

string S;
int A, B, C, D, N;

bool solve(int X, int Y)
{
  for (auto i = X; i < Y - 2; i++)
  {
    if (S[i + 1] == '#' && S[i + 2] == '#')
    {
      return false;
    }
  }
  return true;
}

bool solve2(int X, int Y, int Z, int W)
{
  for (auto i = Z; i < W - 1; i++)
  {
    if (S[i - 1] == '.' && S[i] == '.' && S[i + 1] == '.')
    {
      S[i] = '#';
      return solve(X, Y);
    }
  }
  S[W] = '#';
  return solve(X, Y);
}

int main()
{
  cin >> N >> A >> B >> C >> D >> S;
  A--;
  B--;
  C--;
  D--;
  if (C < D)
  {
    if (solve(A, C) && solve(B, D))
    {
      Yes();
    }
    No();
  }
  if (solve(B, D) && solve2(A, C, B, D))
  {
    Yes();
  }
  No();
}