#include <iostream>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int P[110];
  for (auto i=0; i<N; i++) {
    cin >> P[i];
  }
  int sum = 0;
  for (auto i=0; i<M; i++) {
    int s;
    cin >> s;
    s--;
    sum += P[s];
  }
  cout << sum << endl;
}
