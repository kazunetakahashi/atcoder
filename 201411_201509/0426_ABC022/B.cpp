#include <iostream>
#include <algorithm>
using namespace std;

bool visited[100010];

int main() {
  int N;
  cin >> N;
  fill(visited, visited+100010, false);
  for (auto i=0; i<N; i++) {
    int A;
    cin >> A;
    visited[A] = true;
  }
  int cnt = 0;
  for (auto i=0; i<100010; i++) {
    if (visited[i]) cnt++;
  }
  cout << N-cnt << endl;
}
