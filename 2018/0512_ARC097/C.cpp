/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-5-12 20:48:31
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

string s;
int K;
set<string> S;

int main()
{
  cin >> s;
  cin >> K;
  int N = (int)S.size();
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; i + j < N && j < 5; j++)
    {
      S.insert(s.substr(i, j));
    }
  }
  auto it = S.begin();
  for (auto k = 0; k < K - 1; k++)
  {
    it++;
  }
  cout << *it << endl;
}