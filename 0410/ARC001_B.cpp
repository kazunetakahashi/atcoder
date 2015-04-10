#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

const int dx[6] = {1, 5, 10, -1, -5, -10};

int main() {
  int A, B;
  cin >> A >> B;
  int X[50];
  fill(X, X+50, -1);
  queue< pair<int, int> > Q; // dist, point
  Q.push(make_pair(0, A));
  while (!Q.empty()) {
    int dist = Q.front().first;
    int x = Q.front().second;
    Q.pop();
    if (X[x] == -1) {
      X[x] = dist;
      if (x == B) {
        cout << X[x] << endl;
        return 0;
      }
      int ndist = dist + 1;
      for (auto i=0; i<6; i++) {
        int nx = dx[i] + x;
        if (0 <= nx && nx <= 40 && X[nx] == -1) {
          Q.push(make_pair(ndist, nx));
        }
      }
    }
  }
}
