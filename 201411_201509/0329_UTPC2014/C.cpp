#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <stack>
using namespace std;

const int C = 100010;

int main() {
  vector<int> T[C];
  int visited[C];
  fill(visited, visited+C, -1);
  int n;
  cin >> n;
  for (auto i=0; i<n; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    T[a].push_back(b);
    T[b].push_back(a);
  }
  int loop;
  stack<pair<int, int> > S;
  S.push(make_pair(0, 0));
  while (!S.empty()) {
    int src = S.top().first;
    int cost = S.top().second;
    S.pop();
    if (visited[src] == -1) {
      visited[src] = cost;
      for (auto i=0; i<T[src].size(); i++) {
        int dst = T[src][i];
        S.push(make_pair(dst, cost+1));
      }
    } else {
      if (cost - visited[src] > 2) {
        loop = cost - visited[src];
      }
    }
  }
  cout << ((n == loop) ? 2 : 1) << " ";
  cout << ((loop %2 == 0) ? n : n-1) << endl;
}
