/**
 * File    : I.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-4-15 19:50:43
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

typedef tuple<int, int> P;

int H, W, N;

void init(vector<P> V)
{
  cout << V.size() << endl;
  for (auto e : V)
  {
    cout << get<0>(e) << " " << get<1>(e) << endl;
  }
}

string say(char c)
{
  cout << (char)c << endl;
  string S;
  cin >> S;
  return S;
}

int main()
{
  cin >> H >> W >> N;
  vector<P> V = {};
  string S;
  cin >> S;
  for (auto i = 0; i < H; i++)
  {
    char c = ((i % 2 == 0) ? 'R' : 'L');
    for (auto j = 0; j < W - 1; j++)
    {
      if (say(c) == "get-clear") {
        return 0;
      }
    }
    if (say('D') == "get-clear") {
      return 0;
    }
  }
}