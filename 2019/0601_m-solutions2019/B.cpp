#define DEBUG 1

/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-6-1 21:01:48
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
  cout << "YES" << endl;
  exit(0);
}

void No()
{
  cout << "NO" << endl;
  exit(0);
}

/*
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
*/

// const ll MOD = 1000000007;

string S;

int main()
{
  cin >> S;
  while (S.size() < 15)
  {
    S = S + "o";
  }
  int cnt = 0;
  for (auto x : S)
  {
    if (x == 'o')
    {
      cnt++;
    }
  }
  if (cnt >= 8)
  {
    Yes();
  }
  else
  {
    No();
  }
}