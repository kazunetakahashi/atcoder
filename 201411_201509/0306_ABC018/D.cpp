#include <iostream>
#include <algorithm>
using namespace std;

int N, M, P, Q, R;
int table[20][20];

int main() {
  int ans = 0;
  cin >> N >> M >> P >> Q >> R;
  fill(&table[0][0], &table[0][0] + 20 * 20, 0);
  for (auto i=0; i<R; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    table[x][y] = z;
  }
  for (auto i=0; i< (1 << N); i++) {
    int girl_num = 0;
    for (auto j=0; j<N; j++) {
      if ( ((i >> j) & 1) == 1 ) girl_num++;
    }
    if (girl_num != P) continue;
    int boy_score[20];
    fill(boy_score, boy_score+20, 0);
    for (auto j=0; j<N; j++) {
      if ( ((i >> j) & 1) == 1 ) {
        for (auto k=0; k<M; k++) {
          boy_score[k] += table[j][k];
        }
      }
    }
    sort(boy_score, boy_score+M);
    reverse(boy_score, boy_score+M);
    int total_score = 0;
    for (auto j=0; j<Q; j++) {
      total_score += boy_score[j];
    }
    ans = max(ans, total_score);
  }
  cout << ans << endl;
}
