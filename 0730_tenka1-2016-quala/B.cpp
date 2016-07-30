#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <tuple>
#include <iomanip>
#include <queue>
#include <stack>
#include <map>
#include <complex>

using namespace std;

vector<int> children[1010];
vector<int> grand[1010];
bool visited[1010];

void make_grand(int now) {
  if (!grand[now].empty()) return;
  for (auto x : children[now]) {
    make_grand(x);
    for (auto y : grand[x]) {
      grand[now].push_back(y);
    }
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  int P[1010];
  P[0] = -1;
  for (auto i = 1; i <= N-1; i++) {
    cin >> P[i];
    children[P[i]].push_back(i);
  }
  int B[1010];
  int C[1010];
  int need[1010];
  for (auto i = 0; i < M; i++) {
    cin >> B[i] >> C[i];
    need[B[i]] = C[i];
  }
  fill(visited, visited+1010, false);
  for (auto i = 0; i < M; i++) {
    grand[B[i]].push_back(B[i]);
  }
  make_grand(0);
  queue<int> QQ;
  for (auto x : children[0]) {
    //    cerr << x << endl;
    QQ.push(x);
  }
  int ans = 0;
  while(!QQ.empty()) {
    int mini = 1000000;
    int now = QQ.front();
    QQ.pop();
    /*
    cerr << "now = " << now << " : ";
    for (auto x : grand[now]) {
      cerr << x << " ";
    }
    cerr << endl;
    */
    if (grand[now].empty()) continue;
    for (auto x : grand[now]) {
      mini = min(need[x], mini);
    }
    // cerr << "mini = " << mini << endl;
    ans += mini;
    for (auto x : grand[now]) {
      need[x] -= mini;
    }
    for (auto x : children[now]) {
      QQ.push(x);
    }
  }
  cout << ans << endl;
}
