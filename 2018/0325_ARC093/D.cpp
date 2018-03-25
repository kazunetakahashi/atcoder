/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-3-25 21:07:52
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

int A, B;
bool ans[100][100];

void flush()
{
  for (auto i = 0; i < 100; i++)
  {
    for (auto j = 0; j < 100; j++)
    {
      cout << (ans[i][j] ? '#' : '.');
    }
    cout << endl;
  }
}

int main()
{
  cin >> A >> B;
  for (auto i = 0; i < 50; i++)
  {
    for (auto j = 0; j < 100; j++)
    {
      ans[i][j] = true;
    }
  }
  for (auto i = 50; i < 100; i++)
  {
    for (auto j = 0; j < 100; j++)
    {
      ans[i][j] = false;
    }
  }
  int nowa = 1;
  while (nowa < A)
  {
    for (auto i = 1; i < 100; i += 2)
    {
      for (auto j = 1; j < 100; j += 2)
      {
        ans[i][j] = false;
        nowa++;
        break;
      }
      break;
    }
  }
  int nowb = 1;
  while (nowb < B)
  {
    for (auto i = 51; i < 100; i += 2)
    {
      for (auto j = 1; j < 100; j += 2)
      {
        ans[i][j] = true;
        nowb++;
        break;
      }
      break;
    }
  }
  flush();
}