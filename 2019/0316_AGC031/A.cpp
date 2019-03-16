#define DEBUG 1

/**
 * File    : A.cpp
 * Author  : Kazune Takahashi
 * Created : 3/16/2019, 8:47:07 PM
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
const ll M = 1000000007;

ll N;
string S;
ll cnt[26];

int main()
{
  cin >> N >> S;
  fill(cnt, cnt + 26, 1);
  for (auto x : S)
  {
    cnt[x - 'a']++;
  }
  ll ans = 1;
  for (auto i = 0; i < 26; i++)
  {
    ans *= cnt[i];
    ans %= M;
  }
  ans += M - 1;
  ans %= M;
  cout << ans << endl;
}