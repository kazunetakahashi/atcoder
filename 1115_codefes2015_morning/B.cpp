#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <tuple>
#include <string>

using namespace std;
typedef long long ll;

string S;
int N;
int table[110][110][110];

int kaisu(int S1, int S2, int T1) {
  if (table[S1][S2][T1] != -1) {
    return table[S1][S2][T1];
  }
  if (S1 == S2 || T1 == N) {
    return table[S1][S2][T1] = S2-S1 + N-T1;
  }
  if (S[S1] == S[T1]) {
    return table[S1][S2][T1] = kaisu(S1+1, S2, T1+1);
  }
  return table[S1][S2][T1] = min(kaisu(S1+1, S2, T1)+1,
                                 kaisu(S1, S2, T1+1)+1);//
}

int main() {
  cin >> N;
  cin >> S;
  fill(&table[0][0][0], &table[0][0][0]+110*110*110, -1);
  int ans = 1000;
  for (auto i=0; i<N-1; i++) {
    ans = min(ans, kaisu(0, i+1, i+1));
  }
  cout << ans << endl;
}
