#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int N;
  cin >> N;
  int K[100010];
  for (auto i = 0; i < N-1; i++) {
    cin >> K[i];
  }
  int L[100010];
  L[0] = K[0];
  L[N-1] = K[N-2];
  for (auto i = 1; i < N-1; i++) {
    L[i] = min(K[i-1], K[i]);
  }
  for (auto i = 0; i < N; i++) {
    cout << L[i];
    if (i < N-1) {
      cout << " ";
    }
  }
  cout << endl;
}
