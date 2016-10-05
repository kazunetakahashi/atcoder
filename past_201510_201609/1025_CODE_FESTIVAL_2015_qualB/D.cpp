#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <tuple>
#include <string>

using namespace std;

typedef pair<int, int> koma; // bango, counter

int S[100010];
int C[100010];
int ans[100010];
vector<koma> k[100010];

priority_queue<koma, vector<koma>, greater<koma> > Q;

int main() {
  int N;
  cin >> N;
  for (auto i=0; i<N; i++) {
    cin >> S[i] >> C[i];
    S[i]--;
    k[S[i]].push_back(make_pair(i, C[i]));
  }
  for (auto i=0; i<100010; i++) {
    for (auto x : k[i]) {
      Q.push(x);
    }
    if (!Q.empty()) {
      koma y = Q.top();
      Q.pop();
      y.second--;
      if (y.second == 0) {
        ans[y.first] = i+1;
      } else {
        Q.push(y);
      }
    }
  }
  for (auto i=0; i<N; i++) {
    cout << ans[i] << endl;
  }
}
