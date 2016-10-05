#include <iostream>
using namespace std;

int main() {
  int N, T, E;
  cin >> N >> T >> E;
  int x[110];
  for (auto i=0; i<N; i++) {
    cin >> x[i];
  }
  int below = T-E;
  int above = T+E;
  for (auto i=0; i<N; i++) {
    int now = 0;
    while (now <= above) {
      now += x[i];
      if (below <= now && now <= above) {
        cout << i+1 << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
}
