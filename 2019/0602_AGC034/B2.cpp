#define DEBUG 1

/**
 * File    : B2.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-6-2 21:39:22
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

string S;
vector<vector<int>> V;

ll count(vector<int> W)
{
  ll ans = 0;
  reverse(W.begin(), W.end());
  int t = 0;
  for (auto x : W)
  {
    if (x == 1)
    {
      t++;
    }
    else
    {
      ans += t;
    }
  }
  return ans;
}

int main()
{
  cin >> S;
  int N = S.size();
  S = S + "X";
  vector<int> W;
  for (auto i = 0; i < N; i++)
  {
    if (S[i] == 'A')
    {
      W.push_back(0);
    }
    else if (S[i] == 'B' && S[i + 1] == 'C')
    {
      W.push_back(1);
      i++;
    }
    else
    {
      if (!W.empty())
      {
        V.push_back(W);
      }
      W.clear();
    }
  }
  if (!W.empty())
  {
    V.push_back(W);
  }
  ll ans = 0;
  for (auto W : V)
  {
    ans += count(W);
  }
  cout << ans << endl;
}