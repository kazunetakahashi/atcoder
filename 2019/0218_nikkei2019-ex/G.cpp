#define DEBUG 1

/**
 * File    : G.cpp
 * Author  : Kazune Takahashi
 * Created : 2/18/2019, 8:27:13 PM
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

string S;
ll X[26];

int main()
{
  cin >> S;
  fill(X, X + 26, 0);
  for (auto x : S)
  {
    X[x - 'a']++;
  }
  ll M = 0;
  for (auto i = 0; i < 26; i++)
  {
    M += X[i] - X[i] % 2;
    X[i] %= 2;
  }
  for (auto i = 0; i < 26; i++)
  {
    if (X[i] == 1)
    {
      X[i]--;
      M++;
      break;
    }
  }
  ll ans = M * M;
  for (auto i = 0; i < 26; i++)
  {
    ans += X[i];
  }
  cout << ans << endl;
}