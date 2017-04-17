#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

ll b[100010];
int visited[100010];

int main() {
  int N, a;
  cin >> N >> a;
  ll k;
  cin >> k;
  a--;
  fill(visited, visited+100010, -1);
  for (auto i=0; i<N; i++) {
    cin >> b[i];
    b[i]--;
  }
  vector<int> V;
  ll t = 0;
  int now = a;
  while (visited[now] < 0) {
    // cerr << "t = " << t << ", now = " << now << endl;
    visited[now] = t;
    t++;
    V.push_back(now);
    now = b[now];
  }
  ll tail, circ;
  tail = visited[now];
  circ = t - tail;
  // cerr << tail << " " << circ << endl;
  if (k <= tail) {
    cout << V[k]+1 << endl;
  } else {
    k -= tail;
    cout << V[tail + k%circ]+1 << endl;
  }
}
