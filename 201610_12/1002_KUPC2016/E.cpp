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
bool visited[110][110];

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

  bool ok = false;
  for (auto i = 0; i < H; i++) {
    for (auto j = 0; j < W; j++) {
      if (F[i][j]) {
        St.push(make_tuple(i, j, make_tuple(i, j)));
        ok = true;
        break;
      }
    }
    if (ok) break;
  }
  fill(&visited[110][110], &visited[110][110], false);
  fill(&need[110][110], &need[110][110], false);
  while (!St.empty()) {
    int x = get<0>(St.top());
    int y = get<1>(St.top());
    point root = get<2>(St.top());
    St.pop();
    if (!visited[x][y]) {
      visited[x][y] = true;
      for (auto k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (!valid(nx, ny)) {
          int rootx = get<0>(root);
          int rooty = get<1>(root);
          need[rootx][rooty] = true;
        } else if (visited[nx][ny]) {
          // 
        } else if (F[nx][ny]) {
          St.push(make_tuple(nx, ny, make_tuple(nx, ny)));
        } else {
          St.push(make_tuple(nx, ny, root));          
        }
      }
    }
  }
  int ans = 0;
  for (auto i = 0; i < H; i++) {
    for (auto j = 0; j < W; j++) {
      if (need[i][j]) ans++;
    }
  }
  cout << ans << endl;
}
