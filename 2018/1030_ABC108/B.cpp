/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-10-30 08:38:50
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

int main()
{
  int X1, Y1, X2, Y2;
  cin >> X1 >> Y1 >> X2 >> Y2;
  int V1 = X2 - X1;
  int V2 = Y2 - Y1;
  int X3 = X2 - V2;
  int Y3 = Y2 + V1;
  int X4 = X3 - V1;
  int Y4 = Y3 - V2;
  cout << X3 << " " << Y3 << " " << X4 << " " << Y4 << endl;
}