#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  long long N, K;
  cin >> N >> K;
  vector<int> V;
  vector<int> W;
  cerr << "N = " << N << ", K = " << K << endl;
  for (auto i = 1; i <= N; i++) {
    V.push_back(i);
  }
  long long q;
  long long nokori = N;
  long long r = N;
  while (true) {
    q = r/K;
    r = r%K * (--nokori);
    if (r != 0) {
      W.push_back(*(V.begin()+q));
      // cerr << *(V.begin()+q) << endl;
      V.erase(V.begin()+q);
    } else {
      W.push_back(*(V.begin()+(q-1)));
      V.erase(V.begin()+(q-1));
      reverse(V.begin(), V.end());
      for (auto x : V) {
        W.push_back(x);
      }
      break;
    }
  }
  for (auto x : W) {
    cout << x << endl;
  }
}
