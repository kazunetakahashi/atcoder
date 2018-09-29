/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-9-29 20:55:36
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

int N;
int v[100010];
typedef tuple<int, int> I;
vector<I> cnt[2];

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> v[i];
  }
  for (auto k = 0; k < 2; k++)
  {
    cnt[k] = vector<I>(100010);
    for (auto i = 0; i < 100010; i++)
    {
      cnt[k][i] = I(0, i);
    }
  }
  for (auto i = 0; i < N; i++)
  {
    get<0>(cnt[i % 2][v[i]])++;
  }
  int ans = N;
  for (auto k = 0; k < 2; k++)
  {
    sort(cnt[k].begin(), cnt[k].end());
    reverse(cnt[k].begin(), cnt[k].end());
  }
  for (auto k = 0; k < 2; k++)
  {
    int t_ans = N;
    int l = 1 - k;
    int k_num = get<1>(cnt[k][0]);
    t_ans -= get<0>(cnt[k][0]);
    for (auto i = 0; i < 100010; i++)
    {
      if (k_num != get<1>(cnt[l][i]))
      {
        t_ans -= get<0>(cnt[l][i]);
        break;
      }
    }
    ans = min(ans, t_ans);
  }
  cout << ans << endl;
}