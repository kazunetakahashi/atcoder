#define DEBUG 1

/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-11 21:19:22
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

int N;
string S[10010];

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> S[i];
  }
  int ans = 0;
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < (int)S[i].size() - 1; j++)
    {
      if (S[i][j] == 'A' && S[i][j + 1] == 'B')
      {
        ans++;
      }
    }
  }
  int A = 0;
  int B = 0;
  int AB = 0;
  for (auto i = 0; i < N; i++)
  {
    if (S[i][0] == 'B' && S[i][S[i].size() - 1] == 'A')
    {
      AB++;
    }
    else if (S[i][0] == 'B')
    {
      B++;
    }
    else if (S[i][S[i].size() - 1] == 'A')
    {
      A++;
    }
  }
#if DEBUG == 1
  cerr << "ans = " << ans << ", A = " << A << ", B = " << B << ", AB = " << AB << endl;
#endif
  if (AB > 0)
  {
    ans += AB - 1;
    if (A > 0)
    {
      ans++;
      A--;
    }
    if (B > 0)
    {
      ans++;
      B--;
    }
  }
#if DEBUG == 1
  cerr << "ans = " << ans << ", A = " << A << ", B = " << B << ", AB = " << AB << endl;
#endif
  ans += min(A, B);
  cout << ans << endl;
}