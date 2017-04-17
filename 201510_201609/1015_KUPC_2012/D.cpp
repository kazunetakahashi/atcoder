#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> kenryoku;

int main() {
  int N, M;
  cin >> N >> M;
  vector<kenryoku> V;
  for (auto i=0; i<M; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    V.push_back(make_pair(a, b));
  }
  sort(V.begin(), V.end());
  queue<kenryoku> Q;
  for (auto i=0; i<M; i++) {
    Q.push(V[i]);
  }
  int now = 0;
  int ans = 0;
  priority_queue<int> PQ;
  while (now < N) {
    while (!Q.empty() && Q.front().first <= now) {
      PQ.push(Q.front().second);
      Q.pop();
    }
    if (PQ.empty() || PQ.top() < now) {
      cout << "Impossible" << endl;
      return 0;
    } else {
      now = PQ.top()+1;
      ans++;
    }
  }
  if (now == N) {
    cout << ans << endl;
  } else {
    cout << "Impossible" << endl;
  }
}
