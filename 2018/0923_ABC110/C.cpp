/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-9-23 21:07:54
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
#include <functional>
#include <random> // auto rd = bind(uniform_int_distribution<int>(0, 9), mt19937(19920725));
#include <chrono> // std::chrono::system_clock::time_point start_time, end_time;
// start = std::chrono::system_clock::now();
// double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time).count();
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

set<int> to[26];
set<int> from[26];
string S, T;

int main()
{
  cin >> S >> T;
  int N = S.size();
  for (auto i = 0; i < N; i++)
  {
    int x = S[i] - 'a';
    int y = T[i] - 'a';
    to[x].insert(y);
    from[y].insert(x);
  }
  for (auto i = 0; i < N; i++)
  {
    if (to[i].size() > 1 || from[i].size() > 1)
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}