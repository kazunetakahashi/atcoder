#include <iostream>
#include <cmath>
#include <set>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> V[100010];

int main() {
  int N;
  cin >> N;
  for (auto i = 0; i < N-1; i++) {
    int s, t;
    cin >> s >> t;
    s--; t--;
    V[s].push_back(t);
    V[t].push_back(s);
  }
  vector<int> W;
  bool visited[100010];
  fill(visited, visited+100010, false);
  visited[0] = true;
  for (auto root : V[0]) {
    stack<int> S;
    S.push(root);
    int cnt = 0;
    while (!S.empty()) {
      int now = S.top();
      S.pop();
      if (!visited[now]) {
        visited[now] = true;
        cnt++;
        for (auto x : V[now]) {
          if (!visited[x]) {
            S.push(x);
          }
        }
      }
    }
    W.push_back(cnt);
  }
  if (W.size() == 1) {
    cout << "A" << endl;
  } else {
    int odd = 0;
    for (auto x : W) {
      if (x%2 == 1) {
        odd++;
      }
    }
    cout << ((odd%2 == 1) ? "A" : "B") << endl;
  }
}
