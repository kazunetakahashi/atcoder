#include <iostream>
#include <iomanip> // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple> // get<n>(xxx)
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set> // S.insert(M);
// if (S.find(key) != S.end()) { }
// for (auto it=S.begin(); it != S.end(); it++) { }
// auto it = S.lower_bound(M);
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;

typedef long long ll;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// const int C ;
// const int M = 1000000007;

int H, W;
string S[110];
bool F[110][110];
bool need[110][110];

bool valid(int x, int y) {
  return (0 <= x && x < H && 0 <= y && y < W);
}

bool is_minus_one() {
  for (auto i = 0; i < H; i++) {
    if (S[i][0] == 'X' || S[i][W-1] == 'X') return true;
  }
  for (auto i = 0; i < W; i++) {
    if (S[0][i] == 'X' || S[H-1][i] == 'X') return true;
  }
  return false;
}

typedef tuple<int, int> point;
typedef tuple<int, int, point> state;

stack<state> St;
stack<point> SS;
bool visited[110][110];

void SS_stack() {
  for (auto i = 0; i < H; i++) {
    if (!F[i][0]) SS.push(make_tuple(i, 0));
  }
  for (auto i = 0; i < H; i++) {
    if (!F[i][W-1]) SS.push(make_tuple(i, W-1));
  }
  for (auto i = 0; i < W; i++) {
    if (!F[0][i]) SS.push(make_tuple(0, i));
  }
  for (auto i = 0; i < W; i++) {
    if (!F[H-1][i]) SS.push(make_tuple(H-1, i));
  }
}

void hashi_need() {
  for (auto i = 0; i < H; i++) {
    if (F[i][0]) need[i][0] = true;
  }
  for (auto i = 0; i < H; i++) {
    if (F[i][W-1]) need[i][W-1] = true;
  }
  for (auto i = 0; i < W; i++) {
    if (F[0][i]) need[0][i] = true;
  }
  for (auto i = 0; i < W; i++) {
    if (F[H-1][i]) need[H-1][i] = true;
  }
}


int main () {
  cin >> H >> W;
  for (auto i = 0; i < H; i++) {
    cin >> S[i];
  }
  if (is_minus_one()) {
    cout << "-1" << endl;
    return 0;
  }
  fill(&F[0][0], &F[0][0]+110*110, false);
  for (auto i = 0; i < H; i++) {
    for (auto j = 0; j < W; j++) {
      if (S[i][j] == '.') continue;
      for (auto k = 0; k < 4; k++) {        
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (valid(nx, ny) && S[nx][ny] == '.') {
          F[nx][ny] = true;
        }
      }
    }
  }
  for (auto i = 0; i < H; i++) {
    for (auto j = 0; j < W; j++) {
      cerr << (F[i][j] ? '#' : '.');
    }
    cerr << endl;
  }
  SS_stack();
  fill(&visited[110][110], &visited[110][110], false);
  while (!SS.empty()) {
    int x = get<0>(SS.top());
    int y = get<1>(SS.top());
    SS.pop();
    if (!visited[x][y]) {
      visited[x][y] = true;
      for (auto k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (!valid(nx, ny)) {
          //
        } else if (visited[nx][ny]) {
          // 
        } else if (!F[nx][ny]) {
          SS.push(make_tuple(nx, ny));          
        }
      }
    }
  }
  for (auto i = 0; i < H; i++) {
    for (auto j = 0; j < W; j++) {
      cerr << (visited[i][j] ? 'V' : '.');
    }
    cerr << endl;
  }
  fill(&need[110][110], &need[110][110], false);
  for (auto i = 0; i < H; i++) {
    for (auto j = 0; j < W; j++) {
      if (visited[i][j]) {
        for (auto k = 0; k < 4; k++) {
          int nx = i + dx[k];
          int ny = j + dy[k];
          if (valid(nx, ny) && F[nx][ny]) {
            need[nx][ny] = true;
          }
        }
      }
    }
  }
  hashi_need();
  for (auto i = 0; i < H; i++) {
    for (auto j = 0; j < W; j++) {
      cerr << (need[i][j] ? 'N' : '.');
    }
    cerr << endl;
  }
  int ans = 0;
  for (auto i = 0; i < H; i++) {
    for (auto j = 0; j < W; j++) {
      if (need[i][j]) ans++;
    }
  }
  cout << ans << endl;
}
