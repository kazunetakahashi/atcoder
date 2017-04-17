#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

typedef pair<int, int> kukan;
typedef tuple<int, int, int> stud; // 最初、最後、生徒名
typedef pair<int, int> stud_l; // 最後、生徒名

kukan st[100010];
int room[300010];
bool need[100010];

int main() {
  int N, M;
  cin >> N >> M;
  int s, t;
  for (auto i=0; i<M; i++) {
    cin >> s >> t;
    s--; t--;
    st[i] = make_pair(s, t);
  }
  fill(room, room+300010, 0);
  for (auto i=0; i<M; i++) {
    s = st[i].first;
    t = st[i].second;
    room[s] += 1;
    room[t+1] -= 1;
  }
  for (auto i=0; i<N-1; i++) {
    room[i+1] += room[i];
  }
  fill(need, need+N, false);
  int saborenai = 0;
  priority_queue<stud, vector<stud>, greater<stud> > Q;
  for (auto i=0; i<M; i++) {
    Q.push(make_tuple(st[i].first, st[i].second, i));
  }
  priority_queue<stud_l> PQ;
  for (auto i=0; i<N; i++) {
    while (!Q.empty() && get<0>(Q.top()) <= i) {
      PQ.push(make_pair(get<1>(Q.top()), get<2>(Q.top())));
      Q.pop();
    }
    if (room[i] == 1) {
      if (!need[PQ.top().second]) {
        need[PQ.top().second] = true;
        saborenai++;
      }
    }
  }
  cout << M-saborenai << endl;
  for (auto i=0; i<M; i++) {
    if (!need[i]) {
      cout << i+1 << endl;
    }
  }
}
