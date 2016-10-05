#include <iostream>
#include <algorithm>
using namespace std;

int N;
int Q;
int P[2510];
int T[2510];

int imos[60][60];

int sum(int i, int j, int k, int l) {
  return imos[k][l] - imos[k][j-1] - imos[i-1][l] + imos[i-1][j-1];
}

int main() {
  cin >> N;
  fill(&imos[0][0], &imos[0][0]+N*N, 0);
  for (auto i = 1; i <= N; i++) {
    for (auto j = 1; j <= N; j++) {
      cin >> imos[i][j];
    }
  }
  cin >> Q;
  for (auto i = 0; i < Q; i++) {
    cin >> P[i];
  }
  for (auto i = 1; i <= N; i++) {
    for (auto j = 1; j <= N; j++) {
      imos[i][j] += imos[i][j-1];
    }
  }
  for (auto i = 1; i <= N; i++) {
    for (auto j = 1; j <= N; j++) {
      imos[i][j] += imos[i-1][j];
    }
  }
  fill(T, T+2510, 0);
  int size;
  for (auto i = 1; i <= N; i++) {
    for (auto j = 1; j <= N; j++) {
      for (auto k = i; k <= N; k++) {
        for (auto l = j; l <= N; l++) {
          size = (k-i+1) * (l-j+1);
          // cerr << i << " " << j << " " << k << " " << l << endl;
          T[size] = max(T[size], sum(i, j, k, l));
        }
      }
    }
  }
  for (auto i = 0; i < N*N; i++) {
    T[i+1] = max(T[i+1], T[i]);
  }
  for (auto i = 0; i < Q; i++) {
    cout << T[P[i]] << endl;
  }
}
