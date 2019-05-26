#define DEBUG 1

/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-26 22:16:32
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
ll ans = 0;
ll s[100010];

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> s[i];
  }
  for (auto t = 1; t <= N - 1; t += 2)
  {
    if ((N - 1) % t == 0)
    {
      int d = (N - 1) / t;
      ll t = 0;
      for (auto i = 0; i < N; i += d)
      {
        t += s[i];
      }
      ans = max(ans, t);
    }
  }
  for (auto d = 1; d < N; d++)
  {
    ll t = 0;
    set<int> S;
    int mini = 0;
    int maxi = N - 1;
    while (mini < N && maxi >= 0 && mini != maxi && S.find(mini) == S.end() && S.find(maxi) == S.end())
    {
      t += s[mini];
      t += s[maxi];
      S.insert(mini);
      S.insert(maxi);
      ans = max(ans, t);
      mini += d;
      maxi -= d;
    }
  }
  cout << ans << endl;
}