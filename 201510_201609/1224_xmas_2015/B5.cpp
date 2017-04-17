#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
using namespace std;

set< pair< int, int> > S;
queue<int> A;
set<int> B;
queue<int> Q;
vector< pair<int, int> > V;

int main() {
  int N, M;
  cin >> N >> M;
  int p, q;
  for (auto i = 0; i < M; i++) {
    cin >> p >> q;
    p--; q--;
    S.insert(make_pair(p, q));
    S.insert(make_pair(q, p));
  }
  A.push(0);
  for (auto i = 1; i < N; i++) {
    B.insert(i);
  }
  while (!A.empty()) {
    int x = A.front();
    A.pop();
    for (auto it = B.begin(); it != B.end(); ) {
      if (S.find(make_pair(x, *it)) == S.end()) {
        V.push_back(make_pair(x, *it));
        A.push(*it);
        it = B.erase(it);
      } else {
        it++;
      }      
    }
  }
  if ((int)V.size() != N-1) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
    for (auto x : V) {
      cout << x.first+1 << " " << x.second+1 << endl;
    }
  }
}
