#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int main() {
  int N;
  cin >> N;
  int H[100];
  for (auto i = 0; i < N; i++) {
    cin >> H[i];
  }
  int X;
  cin >> X;
  if (X < H[0]) {
    cout << 1 << endl;
    return 0;
  }
  for (auto i = 0; i < N-1; i++) {
    if (H[i] < X && X < H[i+1]) {
      cout << i+2 << endl;
      return 0;
    }
  }
  cout << N+1 << endl;
}
