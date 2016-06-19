#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  int L[110], R[110], T[110];
  for (auto i = 0; i < Q; i++) {
    cin >> L[i] >> R[i] >> T[i];
    L[i]--; R[i]--;
  }
  int a[110];
  fill(a, a+N, 0);
  for (auto i = 0; i < Q; i++) {
    for (auto j = L[i]; j <= R[i]; j++) {
      a[j] = T[i];
    }
  }
  for (auto i = 0; i < N; i++) {
    cout << a[i] << endl;
  }
}
