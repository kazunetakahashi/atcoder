#include <iostream>
#include <string>
#include <stack>
#include <cassert>
using namespace std;

int H, W;
string S[110];

typedef pair<int, int> point;

int main() {
  cin >> H >> W;
  for (auto i = 0; i < H; i++) {
    cin >> S[i];
    S[i] = S[i] + "#";
  }
  S[H] = "";
  for (auto i = 0; i < W+1; i++) {
    S[H] = S[H] + "#";
  }
  stack<point> P;
  for (auto i = 0; i < H+1; i++) {
    for (auto j = 0; j < W+1; j++) {
      if (S[i][j] == '#') {
        if (i-1 >= 0 && S[i-1][j] == '.') P.push(make_pair(i-1, j));
        if (j-1 >= 0 && S[i][j-1] == '.') P.push(make_pair(i, j-1));
        if (i-1 >= 0 && j-1 >= 0 && S[i-1][j-1] == '.')
          P.push(make_pair(i-1, j-1));
      }
    }
  }
  while (!P.empty()) {
    int x = P.top().first;
    int y = P.top().second;
    P.pop();
    if (S[x][y] == '.') {
      if (S[x+1][y] == '#' && S[x][y+1] == '#' && S[x+1][y+1] == '#') {
        S[x][y] = 'L';
      } else if (S[x+1][y] == 'L' || S[x][y+1] == 'L' || S[x+1][y+1] == 'L') {
        S[x][y] = '#';
      } else {
        goto EXIT;
      }
      if (x-1 >= 0 && S[x-1][y] == '.') P.push(make_pair(x-1, y));
      if (y-1 >= 0 && S[x][y-1] == '.') P.push(make_pair(x, y-1));
      if (x-1 >= 0 && y-1 >= 0 && S[x-1][y-1] == '.')
        P.push(make_pair(x-1, y-1));
    }
  EXIT:
    continue;
  }
  /*for (auto i = 0; i < H+1; i++) {
    cerr << S[i] << endl;
    }*/
  assert(S[0][0] != '.');
  if (S[0][0] == 'L') {
    cout << "Second" << endl;
  } else {
    cout << "First" << endl;
  }
}
