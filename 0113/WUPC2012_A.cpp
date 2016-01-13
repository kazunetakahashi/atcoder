#include <iostream>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  cout << ( N * (N+1) * (2 * N + 1) / 6 ) % M << endl;
}
