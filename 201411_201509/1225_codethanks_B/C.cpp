#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int V[110];
  int F[110];
  for (auto i=0; i<N; i++) {
    cin >> V[i];
  }
  for (auto i=0; i<N; i++) {
    cin >> F[i];
  }
  int res = 0;
  for (auto i=0; i<N; i++) {
    if (V[i]/2 < F[i]) res++;  
  }
  cout << res << endl;
}
