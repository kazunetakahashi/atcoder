#define DEBUG 1

/**
 * File    : A.cpp
 * Author  : Kazune Takahashi
 * Created : 3/2/2019, 2:05:44 PM
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
#include <random> // auto rd = bind(uniform_int_distribution<int>(0, 9), mt19937(10101010));
#include <chrono> // std::chrono::system_clock::time_point start_time, end_time;
// start = std::chrono::system_clock::now();
// double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time).count();
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

int N, T;

void WA()
{
  assert(false);
}

void TLE()
{
  while (true)
  {
    cout << 0 << endl;
    int x;
    cin >> x;
  }
}

void AC()
{
  cout << -1 << endl;
}

int a[50];

int X = 10;

int main()
{
  cin >> N >> T;
  fill(a, a + N, -1);
  int cnt = 0;
  int score = 0;
  int place = -1;
  for (auto i = 0; i < X; i++)
  {
    cout << i << endl;
    cin >> a[i];
    if (cnt == 0)
    {
      if (i >= 1 && a[i - 1] == a[i])
      {
        score += a[i];
      }
      if (score == 1)
      {
        // nothing
        TLE();
      }
      else if (score > 1)
      {
        WA();
      }
      if (a[i] == 1)
      {
        cnt++;
        place = i;
        cout << place << endl;
        int x;
        cin >> x;
      }
    }
    else if (cnt == 1)
    {
      if (a[i] == 1)
      {
        cnt++;
        TLE();
      }
      else
      {
        cout << place << endl;
        int x;
        cin >> x;
      }
    }
  }
  WA();
}