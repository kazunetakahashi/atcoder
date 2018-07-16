/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-7-16 14:04:12
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
int M;
string S;
vector<string> V;
vector<string> W;

void make_V()
{
  int a = 0;
  int b = 0;
  int start = 0;
  for (auto i = 0; i < M; i++)
  {
    if (S[i] == 'a')
    {
      a++;
    }
    else
    {
      b++;
    }
    if (a == b)
    {
      a = b = 0;
      V.push_back(S.substr(start, i + 1 - start));
      start = i + 1;
    }
  }
}

vector<int> make_num(string str)
{
  vector<int> num;
  int a = 0;
  int b = 0;
  for (auto c : str)
  {
    if (c == 'a')
    {
      num.push_back(a);
      a++;
    }
    else
    {
      num.push_back(b);
      b++;
    }
  }
  return num;
}

string calc_a(string str)
{
  vector<int> num = make_num(str);
  string res = "";
  bool is_a = true;
  int search = -1;
  for (auto i = 0; i < (int)str.size(); i++)
  {
    if (is_a && str[i] == 'a')
    {
      res += "a";
      search = num[i];
      is_a = false;
    }
    else if ((!is_a) && str[i] == 'b')
    {
      if (num[i] == search)
      {
        res += "b";
        is_a = true;
      }
    }
  }
  return res;
}

string calc_b(string str)
{
  vector<int> num = make_num(str);
  vector<string> X;
  for (auto k = 0; k <= (int)str.size() / 2; k++)
  {
    string temp = "";
    for (auto i = 0; i < (int)str.size(); i++)
    {
      if (num[i] >= k)
      {
        string s{str[i]};
        temp += s;
      }
    }
    X.push_back(temp);
  }
  return *max_element(X.begin(), X.end());
}

int main()
{
  cin >> N >> S;
  M = 2 * N;
  make_V();
  for (auto str : V)
  {
    if (str[0] == 'a')
    {
      W.push_back(calc_a(str));
    }
    else
    {
      W.push_back(calc_b(str));
    }
  }
  reverse(W.begin(), W.end());
  string ans = "";
  for (auto str : W)
  {
    if (ans < str + ans)
    {
      ans = str + ans;
    }
  }
  cout << ans << endl;
}