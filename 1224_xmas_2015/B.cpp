#include <iostream>
#include <algorithm>
#include <set>
#include <stack>
#include <random>
using namespace std;

int choten[200010];
int p[200010];
int q[200010];
set<int> X[200010];
bool visited[200010];

int main() {
  int N, M;
  cin >> N >> M;
  fill(choten, choten+N, N-1);
  for (auto i = 0; i < M; i++) {
    cin >> p[i] >> q[i];
    p[i]--; q[i]--;
    choten[p[i]]--;
    choten[q[i]]--;
    X[p[i]].insert(q[i]);
    X[q[i]].insert(p[i]);
  }
  for (auto i = 0; i < N; i++) {
    if (choten[i] == 0) {
      cout << "No" << endl;
      return 0;
    }    
  }
  cout << "Yes" << endl;
  for (auto i = 0; i < N; i++) {
    X[i].insert(i);
  }
  fill(visited, visited+N, false);
  random_device rd;
  mt19937 mt(rd());
  int maxc = 0;
  int maxi = 0;
  for (auto i = 0; i < N; i++) {
    if (choten[i] > maxi) {
      maxi = choten[i];
      maxc = i;
    }
  }
  visited[maxc] = true;
  int t = 0;
  auto it = X[maxc].begin();
  while (t < N && it != X[maxc].end()) {
    if (t == *it) {
      t++;
      it++;
    } else if (t < *it) {
      cout << maxc+1 << " " << t+1 << endl;
      visited[t] = true;
      t++;
    } else {
      it++;
    }
  }
  while (t < N) {
    cout << maxc+1 << " " << t+1 << endl;
    visited[t] = true;
    t++;
  }
  for (auto i = 0; i < N; i++) {
    if (!visited[i]) {
      int ans = mt()%N;
      while (!visited[ans] && X[i].find(ans) != X[i].end()) {
        ans = mt()%N;
      }
      cout << i+1 << " " << ans+1 << endl;
      visited[i] = true;
    }
  }
}
