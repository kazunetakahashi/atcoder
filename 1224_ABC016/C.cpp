#include <iostream>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int F[20][20];
  fill(&F[0][0], &F[0][0]+20*20, 10000);
  for (auto i=0; i<M; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    F[a][b] = 1;
    F[b][a] = 1;
  }
  for (int i=0; i<N; i++) {
    F[i][i] = 0;
  }
  for (int k=0; k<N; k++) {
    for (int i=0; i<N; i++) {
      for (int j=0; j<N; j++) {
        F[i][j] = min(F[i][k]+F[k][j], F[i][j]); 
      }
    }
  }
  for (int i=0; i<N; i++) {
    int ans = 0;
    for (int j=0; j<N; j++) {
      ans += ( (F[i][j] == 2) ? 1 : 0 );
    }
    cout << ans << endl;
  }
}
