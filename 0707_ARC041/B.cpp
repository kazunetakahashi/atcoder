#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dx[4] = {0, 0, -1};
int dy[4] = {1, -1, 0};

int main() {
  int N, M;
  cin >> N >> M;
  int b[510][510];
  int a[510][510];
  fill(&a[0][0], &a[0][0]+510*510, 0);
  string str;
  for (auto i=0; i<N; i++) {
    cin >> str;
    for (auto j=0; j<M; j++) {
      b[i][j] = str[j] - '0';
    }
  }
  for (auto i=1; i<N-1; i++) {
    for (auto j=1; j<M-1; j++) {
      a[i][j] = b[i-1][j];
      for (auto k=0; k<3; k++) {
        int nx = i-1 + dx[k];
        int ny = j + dy[k];
        if (0 <= nx) {
          a[i][j] -= a[nx][ny];
        }
      }
    }
  }
  for (auto i=0; i<N; i++) {
    for (auto j=0; j<M; j++) {
      cout << a[i][j];
    }
    cout << endl;
  }
}
