#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

typedef long long ll;

bool ok() {
  ll C[7];
  for (auto i=0; i<7; i++) {
    cin >> C[i];
  }
  C[0]--;
  ll M[7];
  ll x = C[0] - C[6] + C[5] - C[4] + C[3] - C[2] + C[1];
  M[0] = x;
  for (auto i=1; i<7; i++) {
    M[i] = 2 * C[i] - M[i-1];
  }
  for (auto i=0; i<7; i++) {
    cerr << "M[" << i << "] = " << M[i] << endl;
  }
  for (auto i=0; i<7; i++) {
    if (M[i] < 0) {
      return false;
    }
  }
  bool visited[7];
  fill(visited, visited+7, false);
  stack<int> S;
  S.push(0);
  while (!S.empty()) {
    int x = S.top();
    S.pop();
    if (!visited[x]) {
      visited[x] = true;
      if (M[x] > 0 && !visited[(x+1)%7]) {
        S.push((x+1)%7);
      }
      if (M[(x+6)%7] > 0 && !visited[(x+6)%7]) {
        S.push((x+6)%7);
      }
    }
  }
  for (auto i=0; i<7; i++) {
    if (!visited[i]) {
      cerr << i << " is unvisited." << endl;
    }
  }
  for (auto i=0; i<7; i++) {
    if (!visited[i] && ((M[(i+6)%7] != 0) || (M[i] != 0))) {
      return false;
    }
  }
  return true;
}

int main() {
  cout << (ok() ? "YES" : "NO") << endl;
}
