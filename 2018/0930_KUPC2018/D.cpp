/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-9-30 14:19:12
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

string C = "";

bool que(int q) // (X/q) が奇数なら true
{
  assert(q % 2 == 1);
  cout << "? " << q << endl;
  string s;
  cin >> s;
  return (s != C);
}

int main()
{
  cout << "? 2" << endl;
  cin >> C;
  int lb = 1;
  int ub = 1000000007;
  while (ub - lb > 2)
  {
    int t = (lb + ub) / 2;
    if (t % 2 == 0)
    {
      t++;
    }
    if (que(t))
    {
      lb = t;
    }
    else
    {
      ub = t;
    }
  }
  if (C == "even")
  {
    cout << lb + 1 << endl;
  }
  else
  {
    cout << "! " << lb << endl;
  }
}