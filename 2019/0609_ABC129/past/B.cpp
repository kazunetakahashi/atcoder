#define DEBUG 1

/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 6/9/2019, 9:02:13 PM
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

/*
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
*/

/*
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
*/

// const ll MOD = 1000000007;

int N;
ll W[110];

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> W[i];
  }
  ll ans = 10000000000000;
  for (auto i = 0; i <= N; i++)
  {
    ll A = 0, B = 0;
    for (auto j = 0; j < i; j++)
    {
      A += W[j];
    }
    for (auto j = i; j < N; j++)
    {
      B += W[j];
    }
    ans = min(ans, abs(A - B));
  }
  cout << ans << endl;
}