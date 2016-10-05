#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

ll b[100010];
int visited[100010];
vector<int> V;
ll tail, circ;
string S;
ll A[100010];
ll B[100010];

void solvemin() {
  ll k = stoll(S);
  if (k <= tail) {
    cout << V[k]+1 << endl;
  } else {
    k -= tail;
    cout << V[tail + k%circ]+1 << endl;
  }
}

void solvelarge() {
  A[0] = 1%circ;
  for (auto i=1; i<100010; i++) {
    A[i] = (A[i-1] * (10%circ))%circ;
  }
  reverse(S.begin(), S.end());
  for (unsigned i=0; i<S.size(); i++) {
    B[i] = (S[i] - '0')%circ;
  }
  ll ans = 0;
  for (unsigned i=0; i<S.size(); i++) {
    ans += (A[i]*B[i])%circ;
    ans %= circ;
  }
  ll ttail = tail%circ;
  cout << V[tail + (ans + circ - ttail)%circ]+1 << endl;
}

int main() {
  int N, a;
  cin >> N >> a;
  a--;
  cin >> S;
  fill(visited, visited+100010, -1);
  for (auto i=0; i<N; i++) {
    cin >> b[i];
    b[i]--;
  }
  ll t = 0;
  int now = a;
  while (visited[now] < 0) {
    // cerr << "t = " << t << ", now = " << now << endl;
    visited[now] = t;
    t++;
    V.push_back(now);
    now = b[now];
  }
  tail = visited[now];
  circ = t - tail;
  // cerr << tail << " " << circ << endl;
  if (S.size() < 18) {
    solvemin();
  } else {
    solvelarge();
  }
}
