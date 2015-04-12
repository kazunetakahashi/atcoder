#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  bool visited[1000];
  fill(visited, visited+1000, false);
  int N;
  cin >> N;
  int a, b;
  cin >> a >> b;
  int K;
  cin >> K;
  int P[1000];
  for (auto i=0; i<K; i++) {
    cin >> P[i];
  }
  visited[a] = visited[b] = true;
  for (auto i=0; i<K; i++) {
    if (visited[P[i]]) {
      cout << "NO" << endl;
      return 0;
    } else {
      visited[P[i]] = true;
    }
  }
  cout << "YES" << endl;
}
