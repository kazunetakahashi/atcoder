#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
  int L, H;
  cin >> L >> H;
  int N;
  cin >> N;
  int A[100];
  for (auto i=0; i<N; i++) {
    cin >> A[i];
  }
  for (auto i=0; i<N; i++) {
    if (A[i] < L) {
      cout << L-A[i] << endl;
    } else if (A[i] > H) {
      cout << -1 << endl;
    } else {
      cout << 0 << endl;
    }
  }
}
