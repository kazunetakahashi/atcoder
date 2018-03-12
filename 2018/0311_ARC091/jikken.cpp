/**
 * File    : jikken.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-3-11 21:36:22
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

int main()
{
  int N;
  cin >> N;
  vector<int> V;
  for (auto i = 0; i < N; i++)
  {
    V.push_back(i);
  }
  bool ok[100][100];
  fill(&ok[0][0], &ok[0][0] + 100 * 100, false);
  do
  {
    int A = 1, B = 1;
    int lis[100];
    lis[0] = 1;
    for (auto i = 1; i < N; i++)
    {
      lis[i] = 1;
      for (auto j = 0; j < i; j++)
      {
        if (V[j] < V[i])
        {
          lis[i] = max(lis[i], lis[j] + 1);
        }
      }
    }
    for (auto i = 0; i < N; i++)
    {
      A = max(A, lis[i]);
    }
    lis[0] = 1;
    for (auto i = 1; i < N; i++)
    {
      lis[i] = 1;
      for (auto j = 0; j < i; j++)
      {
        if (V[j] > V[i])
        {
          lis[i] = max(lis[i], lis[j] + 1);
        }
      }
    }
    for (auto i = 0; i < N; i++)
    {
      B = max(B, lis[i]);
    }
    for (auto i = 0; i < N; i++)
    {
      cout << V[i] << " ";
    }
    cout << "(" << A << ", " << B << ")" << endl;
    ok[A][B] = true;
  } while (next_permutation(V.begin(), V.end()));
  for (auto i = 1; i <= N; i++)
  {
    for (auto j = 1; j <= N; j++)
    {
      if (i + j <= N+1)
      {
        cout << "(" << i << ", " << j << ") = " << ok[i][j] << endl;
      }
    }
  }
}