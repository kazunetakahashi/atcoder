#define DEBUG 1

/**
 * File    : F2.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-6-2 00:47:04
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
#include <bitset>
using namespace std;

typedef long long ll;

bitset<2010> dp_L[2010];
bitset<2010> dp_R[2010];
bitset<2010> W[2010];

int main()
{
  int N;
  cin >> N;
  for (auto i = 1; i < N; i++)
  {
    string S;
    cin >> S;
    for (auto j = 0; j < i; j++)
    {
      if (S[j] == '0')
      {
        W[j][i] = 1;
      }
      else
      {
        W[i][j] = 1;
      }
    }
  }
  for (auto i = 0; i < N; i++)
  {
    dp_L[i][i] = 1;
    dp_R[i][i] = 1;
  }
  for (auto n = 1; n < N; n++)
  {
    for (auto a = 0; a + n < N; a++)
    {
      int b = a + n;
      if ((dp_R[a + 1] & dp_L[b] & W[a]).any())
      {
        dp_L[a][b] = 1;
      }
      if ((dp_R[a] & dp_L[b - 1] & W[b]).any())
      {
        dp_R[b][a] = 1;
      }
    }
  }
  int ans = (dp_R[0] & dp_L[N - 1]).count();
  cout << ans << endl;
}