#define DEBUG 1

/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2/17/2019, 1:35:17 PM
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

int N, M;
ll T[200010];
ll L[200010];
ll R[200010];
set<ll> S;
typedef tuple<ll, int, ll> event;
vector<event> V;

int main()
{
  cin >> N >> M;
  for (auto i = 0; i < M; i++)
  {
    cin >> T[i] >> L[i] >> R[i];
    L[i]--;
    R[i]--;
  }
  for (auto i = 0; i < M; i++)
  {
    V.push_back(event(L[i], 0, T[i]));
    V.push_back(event(R[i], 1, T[i]));
  }
  sort(V.begin(), V.end());
  auto it = V.begin();
  ll ans = 0;
  for (auto i = 0; i < N; i++)
  {
    while (it != V.end())
    {
      int time = get<0>(*it);
      int choose = get<1>(*it);
      ll score = get<2>(*it);
      if (time == i)
      {
        if (choose == 0)
        {
          S.insert(score);
        }
        else
        {
          S.erase(S.find(score));
        }
        it++;
      }
      else
      {
        break;
      }
    }
    if (!S.empty())
    {
      auto S_it = S.end();
      S_it--;
#if DEBUG == 1
      cerr << "i = " << i << ", score = " << *S_it << endl;
#endif
      ans += *S_it;
    }
  }
  cout << ans << endl;
}