#define DEBUG 1

/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 4/13/2019, 9:08:24 PM
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

int main()
{
  cin >> N >> K >> S;
  bool one = true;
  int t = 0;
  for (auto i = 0; i < N; i++)
  {
    if (S[i] == '0' && one)
    {
      V.push_back(t);
      one = false;
      t = 1;
    }
    else if (S[i] == '1' && one)
    {
      t++;
    }
    else if (S[i] == '0' && !one)
    {
      t++;
    }
    else
    {
      V.push_back(t);
      one = true;
      t = 1;
    }
  }
  V.push_back(t);
  if (!one)
  {
    V.push_back(0);
  }
#if DEBUG == 1
  for (auto x : V)
  {
    cerr << x << " ";
  }
  cerr << endl;
#endif
  vector<int> imos(V.size() + 1, 0);
  for (auto i = 0; i < N; i++)
  {
    imos[i + 1] = imos[i] + V[i];
  }
#if DEBUG == 1
  for (auto x : imos)
  {
    cerr << x << " ";
  }
  cerr << endl;
#endif
  int seg = min(2 * K + 1, (int)V.size());
  int ans = 0;
  for (auto i = 0; i + seg <= (int)V.size(); i++)
  {
    ans = max(ans, imos[i + seg] - imos[i]);
  }
  cout << ans << endl;
}