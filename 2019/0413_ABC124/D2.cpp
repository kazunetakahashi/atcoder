#define DEBUG 1

/**
 * File    : D2.cpp
 * Author  : Kazune Takahashi
 * Created : 5/23/2019, 11:22:03 PM
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

int N, K;
string S;
vector<int> V;
vector<int> W;

int main()
{
  cin >> N >> K >> S;
  int now = 1;
  int cnt = 0;
  for (auto i = 0; i < N; i++)
  {
    if (S[i] == ('0' + now))
    {
      cnt++;
    }
    else
    {
      V.push_back(cnt);
      cnt = 1;
      now = 1 - now;
    }
  }
  if (cnt > 0)
  {
    V.push_back(cnt);
  }
  if (V.size() % 2 == 0)
  {
    V.push_back(0);
  }
  W = vector<int>(V.size() + 1, 0);
  for (auto i = 0; i < (int)V.size(); i++)
  {
    W[i + 1] = W[i] + V[i];
  }
  int ans = 0;
  for (auto i = 0; i < (int)W.size(); i += 2)
  {
    int start = i;
    int goal = min(i + 2 * K + 1, (int)W.size() - 1);
    ans = max(ans, W[goal] - W[start]);
  }
  cout << ans << endl;
}