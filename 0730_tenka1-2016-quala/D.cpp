#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

int dx[2][4] = { {1, 0, -1, 0}, {0, 1, 0, -1} };

int main() {
  int N;
  cin >> N;
  vector<int> V[100];
  for (auto i = 0; i < N-1; i++) {
    char v, w;
    cin >> v >> w;
    int x = v - 'A';
    int y = w - 'A';
    V[x].push_back(y);
    V[y].push_back(x);
  }
  stack<int> S;
  S.push(0);
  vector<bool> visited(N, false);
  int cood[2][100];
  cood[0][0] = 0;
  cood[1][0] = 0;
  int nagasa = (1 << 29);
  int childnum[100];
  int from[100];
  from[0] = -1;
  while (!S.empty()) {
    int now = S.top();
    S.pop();
    if (!visited[now]) {
      visited[now] = true;
      int ind = 0;
      for (auto x : V[now]) {
        if (from[now] != -1 && ind == (from[now]+2)%4) ind++;
        if (visited[x]) continue;
        for (auto j = 0; j < 2; j++) {
          cood[j][x] = cood[j][now] + dx[j][ind] * nagasa;
        }
        from[x] = ind;
        S.push(x);
        ind++;
      }
      childnum[now] = ind;
      nagasa = (nagasa >> 1);
    }
  }
  map<int, int> M[2];
  int real[2][100];
  for (auto k = 0; k < 2; k++) {
    set<int> temp;
    for (auto i = 0; i < N; i++) {
      temp.insert(cood[k][i]);
    }
    int ind = 0;
    for (auto x : temp) {
      M[k][x] = 2 * ind++;
    }
    for (auto i = 0; i < N; i++) {
      real[k][i] = M[k][cood[k][i]];
    }    
  }
  char ans[100][100];
  fill(&ans[0][0], &ans[0][0]+100*100, '.');
  for (auto i = 0; i < N; i++) {
    ans[real[0][i]][real[1][i]] = 'A' + i;
  }
  for (auto i = 0; i < N; i++) {
    int x = real[0][i];
    int y = real[1][i];
    for (auto j = 0; j < childnum[i]; j++) {
      if (from[i] != -1 && j == (from[i]+2)%4) continue;
      for (auto l = 1; true; l++) {
        int nx = x + dx[0][j] * l;
        int ny = y + dx[1][j] * l;
        int ch = ((j % 2 == 0) ? '|' : '-');
        if (0 <= nx && nx < 100 && 0 <= ny && ny < 100) {
          if (ans[nx][ny] == '.') {
            ans[nx][ny] = ch;
          } else {
            break;
          }
        } else {
          break;
        }
      } 
    }
  }
  cout << "100 100" << endl;
  for (auto i = 0; i < 100; i++) {
    for (auto j = 0; j < 100; j++) {
      cout << ans[i][j];
    }
    cout << endl;
  }
}
