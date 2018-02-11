/**
 * File    : A.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-2-11 18:58:37
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
#include <chrono>
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.

typedef long long ll;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const char ch[4] = {'D', 'R', 'U', 'L'};

// const int C = 1e6+10;
// const ll M = 1000000007;

typedef tuple<int, int> place;
typedef tuple<int, int> score_map;
typedef tuple<int, vector<int>, vector<int>> state; // score, move, maps

int N, K, H, W, T;
string M[100][50];
place start[100];
random_device rd;
mt19937 mt(rd());

int score(int m, vector<int> V)
{
  int x = get<0>(start[m]);
  int y = get<1>(start[m]);
  string map[50];
  for (auto i = 0; i < H; i++)
  {
    map[i] = M[m][i];
  }
  assert(map[x][y] == '@');
  map[x][y] = '.';
  int ans = 0;
  for (auto e : V)
  {
    int nx = x + dx[e];
    int ny = y + dy[e];
    if (map[nx][ny] == 'o')
    {
      ans++;
      map[nx][ny] = '.';
      x = nx;
      y = ny;
    }
    else if (map[nx][ny] == '.')
    {
      x = nx;
      y = ny;
    }
    else if (map[nx][ny] == 'x')
    {
      return 0;
    }
    else
    {
      assert(map[nx][ny] == '#');
    }
  }
  return ans;
}

state make_state(vector<int> moves)
{
  vector<score_map> V;
  for (auto i = 0; i < N; i++)
  {
    int s = score(i, moves);
    if (s > 0)
    {
      V.push_back(make_tuple(s, i));
    }
  }
  sort(V.begin(), V.end());
  reverse(V.begin(), V.end());
  int sum = 0;
  vector<int> maps;
  if ((int)V.size() < K)
  {
    return make_tuple(sum, moves, maps);
  }
  for (auto i = 0; i < K; i++)
  {
    int scored = get<0>(V[i]);
    sum += scored;
    maps.push_back(get<1>(V[i]));
  }
  return make_tuple(sum, moves, maps);
}

state make_state_longer(state st, int l)
{
  vector<int> moves = get<1>(st);
  vector<int> maps = get<2>(st);
  vector<int> scr;
  for (auto i = 0; i < l; i++)
  {
    moves.push_back(mt() % 4);
  }
  for (auto e : maps)
  {
    int s = score(e, moves);
    if (s > 0)
    {
      scr.push_back(s);
    }
  }
  int sum = 0;
  if ((int)scr.size() < K)
  {
    return make_tuple(sum, moves, maps);
  }
  for (auto i = 0; i < K; i++)
  {
    int scored = scr[i];
    sum += scored;
  }
  return make_tuple(sum, moves, maps);
}

void flush(vector<int> moves, vector<int> maps)
{
  assert((int)maps.size() == K);
  assert((int)moves.size() <= T);
  for (auto i = 0; i < K; i++)
  {
    cout << maps[i];
    if (i < K - 1)
    {
      cout << " ";
    }
    else
    {
      cout << endl;
    }
  }
  for (auto x : moves)
  {
    cout << ch[x];
  }
  cout << endl;
}

int main()
{
  auto start_time = std::chrono::system_clock::now();
  cin >> N >> K >> H >> W >> T;
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < H; j++)
    {
      cin >> M[i][j];
    }
    bool ok = false;
    for (auto j = 0; j < H; j++)
    {
      for (auto k = 0; k < W; k++)
      {
        if (M[i][j][k] == '@')
        {
          start[i] = make_tuple(j, k);
          ok = true;
          break;
        }
        if (ok)
          break;
      }
    }
  }
  random_device rd;
  vector<state> S;
  vector<state> tempS;
  mt19937 mt(rd());
  auto end_time = std::chrono::system_clock::now();
  vector<bool> checkpoint(10000, false);
  while (true)
  {
    end_time = std::chrono::system_clock::now();
    double timer = std::chrono::duration_cast<std::chrono::milliseconds>(
                       end_time - start_time)
                       .count();
    if (timer > 3950)
    {
      S = tempS;
      auto maxi = max_element(S.begin(), S.end());
      cerr << "score: " << get<0>(*maxi) << endl;
      flush(get<1>(*maxi), get<2>(*maxi));
      return 0;
    }
    else if (timer < 300)
    {
      vector<int> move;
      for (auto i = 0; i < 100; i++)
      {
        move.push_back(mt() % 4);
      }
      auto s = make_state(move);
      if (get<0>(s) > 0)
      {
        tempS.push_back(s);
      }
    }
    else
    {
      int ind = (timer - 300) / 20;
      // cerr << ind << endl;
      if (!checkpoint[ind])
      {
        checkpoint[ind] = true;
        if ((int)tempS.size() >= 40)
        {
          S = tempS;
          tempS.clear();
          sort(S.begin(), S.end());
          reverse(S.begin(), S.end());
          unsigned int l = S.size() / 4;
          cerr << "l = " << l << endl;
          while (l < S.size())
          {
            S.erase(S.begin() + l);
          }
        }
      }
      int l = S.size();
      state st = S[mt() % l];
      state nst = make_state_longer(st, 10);
      if (get<0>(nst) > 0)
      {
        tempS.push_back(nst);
      }
    }
  }
}