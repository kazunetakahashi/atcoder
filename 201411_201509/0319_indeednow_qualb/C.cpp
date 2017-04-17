#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> tree[100010];
  for (auto i=0; i<N-1; i++) {
    int a, b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  priority_queue<int> Q;
  Q.push(-1);
  bool visited[100010];
  fill(visited, visited+100010, false);
  vector<int> ans;
  while (!Q.empty()) {
    int v = -1 * Q.top();
    Q.pop();
    if (!visited[v]) {
      visited[v] = true;
      ans.push_back(v);
      for (auto i=0; i<tree[v].size(); i++) {
        int dst = tree[v][i];
        Q.push(-1 * dst);
      }
    }
  }
  for (auto i=0; i<ans.size(); i++) {
    cout << ans[i];
    if (i != ans.size()-1) cout << " ";
  }
  cout << endl;
}
