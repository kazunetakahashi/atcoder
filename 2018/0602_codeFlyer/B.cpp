/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-6-2 21:02:16
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

int A, B, N;
string X;

int main()
{
  cin >> A >> B >> N;
  cin >> X;
  for (auto x : X)
  {
    if (x == 'S' && A > 0)
    {
      A--;
    }
    else if (x == 'C' && B > 0)
    {
      B--;
    }
    else if (x == 'E')
    {
      if (A == 0 && B == 0)
      {
        //
      }
      else if (A == B)
      {
        A--;
      }
      else if (A > B)
      {
        A--;
      }
      else
      {
        B--;
      }
    }
  }
  cout << A << endl;
  cout << B << endl;
}