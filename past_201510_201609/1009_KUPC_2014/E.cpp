#include <iostream>
#include <algorithm>
using namespace std;

bool ok(int N, int M) {
  // if ((N*M)%4 != 0) return false;
  if (N > M) {
    swap(N, M);
  }
  if (N == 1) {
    return false;
  } else if (N == 2) {
    return ((M != 4) && (M%4 == 0));
  } else {
    return ((N*M)%8 == 0);
  }
}

int main() {
  int C;
  cin >> C;
  int N, M;
  for (auto i=0; i<C; i++) {
    cin >> N >> M;
    cout << (ok(N, M) ? "Possible" : "Impossible") << endl;
  }
}
