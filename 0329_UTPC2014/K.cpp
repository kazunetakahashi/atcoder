#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <stack>
using namespace std;

const long long C = (1 << 20);

int main() {
  int A, B, X;
  cin >> A >> B >> X;
  if (A == X) {
    cout << 0 << endl;
    return 0;
  }
  bool visited[C];
  int a[C];
  fill(visited, visited+C, false);
  a[0] = A;
  visited[A] = true;
  for (auto t=0; t<C-1; t++) {
    a[t+1] = (a[t]/2) ^ (a[t]%2 * B);
    // cerr << a[t+1] << endl;
    if (a[t+1] == X) {
      cout << t+1 << endl;
      return 0;
    }
    if (visited[a[t+1]]) {
      cout << -1 << endl;
      return 0;
    }
    visited[a[t+1]] = true;
  }
}
