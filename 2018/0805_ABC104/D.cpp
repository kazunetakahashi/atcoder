/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-8-5 21:32:38
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

string S;

// const int C = 1e6+10;
const ll M = 1000000007;
ll ans = 0;
ll cnt_A = 0;
ll cnt_AB = 0;

void A()
{
  cnt_A++;
}

void B()
{
  cnt_AB += cnt_A;
  cnt_AB %= M;
}

void C()
{
  ans += cnt_AB;
  ans %= M;
}

int main()
{
  cin >> S;
  for (auto x : S)
  {
    if (x == '?')
    {
      C();
      B();
      A();
    }
    if (x == 'A')
    {
      A();
    }
    if (x == 'B')
    {
      B();
    }
    if (x == 'C')
    {
      C();
    }
    cerr << cnt_A << " " << cnt_AB << " " << ans << endl;
  }
  cout << ans << endl;
}