#include <iostream>
using namespace std;

int infty = (1 << 30);

int main() {
  int T;
  cin >> T;
  for (auto i=0; i<T; i++) {
    int N;
    cin >> N;
    int a[40][40];
    for (auto i=0; i<N; i++) {
      for (auto j=0; j<N; j++) {
        cin >> a[i][j];
        if (a[i][j] == -1) {
          a[i][j] = infty;
        }
      }
    }
    bool ans = true;
    for (auto k=0; k<N; k++) {
      for (auto i=0; i<N; i++) {
        for (auto j=0; j<N; j++) {
          if (i == j) {
            if (a[i][i] != 0) {
              ans = false;
              goto EXIT;
            }
          } else if ((k != i) && (k != j)) {
            if (a[i][k] < infty && a[k][j] < infty &&
                a[i][j] > a[i][k] + a[k][j]) {
              ans = false;
              goto EXIT;
            }
          }
        }
      }
    }
 EXIT:
    cout << (ans ? "YES" : "NO") << endl;
  }
}
