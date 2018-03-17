/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-3-17 22:01:10
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
ll a[1010];
ll maxi;
vector<bool> ans;
vector<int> res;

void flush()
{
  while (ans.size() > 1)
  {
    int M = ans.size();
    for (auto i = 0; i < M - 2; i++)
    {
      if (!ans[i] && !ans[i+1] && !ans[i+2])
      {
        res.push_back(i + 1);
        ans.erase(ans.begin() + i);
        ans.erase(ans.begin() + i);
        goto EXIT;
      }
    }
    if (!ans[0])
    {
      res.push_back(0);
      ans.erase(ans.begin());
      goto EXIT;
    }
    if (!ans[ans.size() - 1])
    {
      res.push_back(ans.size() - 1);
      ans.erase(ans.begin() + ans.size() - 1);
      goto EXIT;
    }
    assert(ans.size() >= 3 && ans[0] && !ans[1] && ans[2]);
    res.push_back(1);
    ans.erase(ans.begin());
    ans.erase(ans.begin());
  EXIT:
    continue;
  }
  cout << maxi << endl;
  cout << res.size() << endl;
  for (auto x : res)
  {
    cout << x + 1 << endl;
  }
}

int main()
{
  cin >> N;
  ans = vector<bool>(N, false);
  for (auto i = 0; i < N; i++)
  {
    cin >> a[i];
  }
  maxi = 0;
  int maxi_k = 0;
  for (auto k = 0; k < 2; k++)
  {
    ll temp = 0;
    for (auto i = k; i < N; i += 2)
    {
      if (a[i] >= 0)
      {
        temp += a[i];
      }
    }
    if (maxi < temp)
    {
      maxi = temp;
      maxi_k = k;
    }
  }
  for (auto i = maxi_k; i < N; i += 2)
  {
    if (a[i] >= 0)
    {
      ans[i] = true;
    }
#if DEBUG == 1
    cerr << "ans[" << i << "] = " << ans[i] << endl;
#endif
  }
  flush();
}