/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-3-4 21:05:03
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

  int N;
  string S[100010];

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> S[i];
  }
  ll cnt[26];
  fill(cnt, cnt + 26, 0);
  for (auto i = 0; i < N; i++)
  {
    cnt[S[i][0] - 'A']++;
  }
  ll c[5];
  c[0] = cnt['M' - 'A'];
  c[1] = cnt['A' - 'A'];
  c[2] = cnt['R' - 'A'];
  c[3] = cnt['C' - 'A'];
  c[4] = cnt['H' - 'A'];
  ll ans = 0;
  for (auto i = 0; i < 5; i++)
  {
    for (auto j = i+1; j < 5; j++)
    {
      for (auto k = j+1; k < 5; k++)
      {
        ans += cnt[i] * cnt[j] * cnt[k];
      }
    }
  }
  cout << ans << endl;
}