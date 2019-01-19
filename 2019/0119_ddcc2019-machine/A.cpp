/**
 * File    : A.cpp
 * Author  : Kazune Takahashi
 * Created : 1/19/2019, 1:34:27 PM
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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

ll XST, YST, XA, YA, XB, YB, XE, YE;
ll XP, XSP, XAS, XDS, YP, YSP, YAS, YDS, AS, BS, ES;

const double PI = 3.141593;

void flush()
{
  cout << XP << ","
       << XP << ","
       << XSP << ","
       << XAS << ","
       << XDS << ","
       << YP << ","
       << YSP << ","
       << YAS << ","
       << YDS << ","
       << AS << ","
       << BS << ","
       << ES << endl;
}

typedef tuple<ll, ll> P;
set<P> S;

int main()
{
  cerr << 51 * 51 * PI * 44 / 3 / 1000 << endl;
  cin >> XST >> YST >> XA >> YA >> XB >> YB >> XE >> YE;
  XAS = XDS = YAS = YDS = 1000;
  XSP = YSP = 500;
  for (auto i = 0; i < 100; i++)
  {
    ll x, y;
    XP = XA;
    YP = YA;
    AS = BS = ES = 0;
    flush();
    XP = XA;
    YP = YA;
    AS = BS = ES = 0;
    AS = 1333;
    flush();
    XP = XB + 2;
    YP = YB + 2;
    AS = BS = ES = 0;
    flush();
    XP = XB;
    YP = YB;
    AS = BS = ES = 0;
    BS = 1333;
    flush();
    XP = XE;
    YP = YE;
    AS = BS = ES = 0;
    flush();
    XP = XB;
    YP = YB;
    AS = BS = ES = 0;
    ES = 2666;
    flush();
  }
}