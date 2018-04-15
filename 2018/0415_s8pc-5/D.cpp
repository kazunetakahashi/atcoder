/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-4-15 20:17:27
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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

typedef tuple<int, int> P;
int H, W;
int C;
bool F[50][50];
bool swapped = false;

P say(P p)
{
  if (swapped)
  {
    cout << get<1>(p)+1 << " " << get<0>(p)+1 << endl;
    int x, y;
    cin >> x >> y;
    return P(y-1, x-1);
  } else {
    cout << get<0>(p)+1 << " " << get<1>(p)+1 << endl;
    int x, y;
    cin >> x >> y;
    return P(x-1, y-1);
  }
}

int nokori()
{
  int res = H * W - 2;
  if (H == 1 && W > 2)
  {
    res -= 1;
  }
  else if (H > 1)
  {
    res -= 2;
  }
  return res;
}

void init()
{
  C = nokori();
  cerr << C << endl;
  if (H == 1 && W == 2)
  {
    cout << "First" << endl;
  }
  else if (C % 2 == 1)
  {
    cout << "First" << endl;
  }
  else
  {
    cout << "Second" << endl;
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    F[x][y] = true;
  }
}

bool solve()
{
  if (F[H-1][W-2] || (H > 1 && F[H-2][W-1]))
  {
    say(P(H - 1, W - 1));
    return true;
  }
  else
  {
    for (auto i = 0; i < H; i++)
    {
      for (auto j = 0; j < W; j++)
      {
        if ((i == H-2 && j == W-1) || (i == H-1 && j == W-2))
        {
          continue;
        }
        if (!F[i][j])
        {
          for (auto k = 0; k < 4; k++)
          {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (0 <= nx && nx < H && 0 <= ny && ny < W && F[nx][ny])
            {
              P p = say(P(i, j));
              F[i][j] = true;
              F[get<0>(p)][get<1>(p)] = true;
              return false;
            }
          }
        }
      }
    }
  }
  assert(false);
  return true;
}

int main()
{
  cin >> H >> W;
  if (H > W)
  {
    swapped = true;
    swap(H, W);
  }
  fill(&F[0][0], &F[0][0] + 50 * 50, false);
  F[0][0] = true;
  init();
  while (!solve())
  {
    //
  }
}