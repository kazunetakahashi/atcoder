/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-4-14 21:58:19
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

#define DEBUG 1 // change 0 -> 1 if we need debug.

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

int H, W;
string S[20];
typedef tuple<int, int> P;
vector<vector<P>> pairs;

void dfs(vector<P> temp, vector<bool> used, int R)
{
  if (R%2 == 1)
  {
    for (auto i = 0; i < H; i++)
    {
      if (!used[i])
      {
        vector<bool> n_used = used;
        n_used[i] = true;
        vector<P> n_temp = temp;
        n_temp.push_back(P(i, i));
        dfs(n_temp, n_used, R - 1);
      }
    }
    return;
  }
  if (R == 0)
  {
    pairs.push_back(temp);
    return;
  }
  assert(R >= 2);
  int first = -1;
  for (auto i = 0; i < H; i++)
  {
    if (!used[i])
    {
      first = i;
      used[i] = true;
      break;
    }
  }
  assert(first >= 0);
  for (auto i = 0; i < H; i++)
  {
    if (!used[i])
    {
      vector<bool> n_used = used;
      n_used[i] = true;
      vector<P> n_temp = temp;
      n_temp.push_back(P(first, i));
      dfs(n_temp, n_used, R - 2);
    }
  }
}

vector<string> make_strings(vector<P>& V)
{
  vector<int> X;
  int N = V.size();
  for (auto i = 0; i < N; i++)
  {
    X.push_back(get<0>(V[i]));
  }
  for (auto i = N-1; i >= 0; i--)
  {
    X.push_back(get<1>(V[i]));
  }
  vector<string> res;
  for (auto j = 0; j < W; j++)
  {
    string str = "";
    for (auto i : X)
    {
      string t = {S[i][j]};
      str += t;
    }
    res.push_back(str);
  }
  return res;
}

vector<string> reverse_strings(const vector<string>& V)
{
  vector<string> res;
  for (auto x : V)
  {
    reverse(x.begin(), x.end());
    res.push_back(x);
  }
  return res;
}

int main()
{
  cin >> H >> W;
  for (auto i = 0; i < H; i++)
  {
    cin >> S[i];
  }
  vector<P> emp_P;
  vector<bool> emp_used = vector<bool>(H, false);
  dfs(emp_P, emp_used, H);
  #if DEBUG == 1
  cerr << "pairs.size() = " << pairs.size() << endl;
  if (pairs.size() < 5)
  {
    for (auto V : pairs)
    {
      for (auto e : V)
      {
        cerr << "[" << get<0>(e) << ", " << get<1>(e) << "] ";
      }
      cerr << endl;
    }
  }
  #endif
  for (auto e : pairs)
  {
    vector<string> V1 = make_strings(e);
    vector<string> V2 = reverse_strings(V1);
    vector<bool> used = vector<bool>(false, W);
    bool found = true;
    for (auto i = 0; i < W; i++)
    {
      if (used[i])
      {
        continue;
      }
      found = false;
      used[i] = true;
      for (auto j = i + 1; j < W; j++)
      {
        if (!used[j] && V1[i] == V2[j])
        {
          used[j] = true;
          found = true;
          break;
        }
      }
      if (!found && V1[i] == V2[i])
      {
        found = true;
      }
      if (!found)
      {
        break;
      }
    }
    if (found)
    {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}