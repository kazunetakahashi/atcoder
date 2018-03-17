/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-3-17 20:08:39
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

typedef tuple<int, int, int> P;
vector<P> V;
vector<int> W;
int N;

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    int a, b;
    cin >> a >> b;
    V.push_back(P(a, b, 0));
  }
  for (auto i = 0; i < N; i++)
  {
    int a, b;
    cin >> a >> b;
    V.push_back(P(a, b, 1));
  }
  sort(V.begin(), V.end());
  int ans = 0;
  for (auto e : V)
  {
    int x = get<0>(e);
    int y = get<1>(e);
    int c = get<2>(e);
    if (c == 0)
    {
      W.push_back(y);
    }
    else
    {
      sort(W.begin(), W.end());
      reverse(W.begin(), W.end());
      for (auto it = W.begin(); it != W.end(); it++)
      {
        if (*it < y)
        {
          ans++;
          W.erase(it);
          break;
        }
      }
    }
  }
  cout << ans << endl;
}