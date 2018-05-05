/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-5-5 21:04:33
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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

int H, W;
string S[100];

bool valid(int i, int j)
{
  return (0 <= i && i < H && 0 <= j && j < W && S[i][j] == '#');
}

int main()
{
  cin >> H >> W;
  for (auto i = 0; i < H; i++)
  {
    cin >> S[i];
  }
  for (auto i = 0; i < H; i++)
  {
    for (auto j = 0; j < W; j++)
    {
      if (S[i][j] == '#')
      {
        bool ok = false;
        for (auto k = 0; k < 4; k++)
        {
          int x = i + dx[k];
          int y = j + dy[k];
          if (valid(x, y))
          {
            ok = true;
            break;
          }
        }
        if (!ok)
        {
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Yes" << endl;
}