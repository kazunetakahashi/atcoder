#define DEBUG 1

/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-28 15:35:36
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

void Yes()
{
  cout << "Yes" << endl;
  exit(0);
}

void No()
{
  cout << "No" << endl;
  exit(0);
}

int N, M;
vector<int> V[100010];
int parent[100010];
int start = -1;
int goal = -1;

bool dfs(int s)
{
  for (auto x : V[s])
  {
    if (x != parent[s])
    {
      if (x == start)
      {
        return false;
      }
      else if (x == goal)
      {
        return true;
      }
      parent[x] = s;
      if (!dfs(x))
      {
        return false;
      }
    }
  }
  return true;
}

int main()
{
  cin >> N >> M;
  for (auto i = 0; i < M; i++)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }
  for (auto i = 0; i < N; i++)
  {
    int s = V[i].size();
    if (s % 2 == 1)
    {
      No();
    }
  }
  for (auto i = 0; i < N; i++)
  {
    int s = V[i].size();
    if (s % 2 >= 6)
    {
      Yes();
    }
  }
  int four = 0;
  for (auto i = 0; i < N; i++)
  {
    int s = V[i].size();
    if (s == 4)
    {
      four++;
    }
  }
  if (four >= 3)
  {
    Yes();
  }
  else if (four == 2)
  {
    for (auto i = 0; i < N; i++)
    {
      if ((int)V[i].size() == 4)
      {
        if (start == -1)
        {
          start = i;
        }
        else
        {
          goal = i;
          break;
        }
      }
    }
    fill(parent, parent + N, -1);
    if (!dfs(start))
    {
      Yes();
    }
    else
    {
      No();
    }
  }
  else
  {
    No();
  }
}