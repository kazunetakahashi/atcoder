#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
  int N;
  cin >> N;
  int a[100];
  for (auto i=0; i<N; i++) {
    cin >> a[i];
  }
  int M = -100000;
  for (auto i=0; i<N; i++) {
    int Ta = -100000;
    int Ao = -100000;
    for (auto j=0; j<N; j++) {
      if (i == j) continue;
      int l = min(i, j);
      int r = max(i, j);
      int ta = 0;
      int ao = 0;
      bool sente = true;
      for (auto k=l; k<=r; k++) {
        if (sente) {
          ta += a[k];
        } else {
          ao += a[k];
        }
        sente = !sente;
      }
      if (Ao < ao) {
        Ao = ao;
        Ta = ta;
      }
    }
    M = max(Ta, M);
  }
  cout << M << endl;
}
