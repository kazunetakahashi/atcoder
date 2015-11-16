#include <iostream>
#include <algorithm>
#include <tuple>
#include <map>
#include <vector>
using namespace std;

int N;
int L[100010];
int P[100010];
int Q;
int H[100010];
vector<int> V[100010];

int memo_depth[100010];

int depth(int i) {
  if (memo_depth[i] != -1) {
    return memo_depth[i];
  }
  if (P[i] == -1) {
    return memo_depth[i] = L[i];
  }
  return memo_depth[i] = L[i] + depth(P[i]);
}

int main() {
  cin >> N;
  for (auto i=0; i<N; i++) {
    cin >> L[i];
  }
  for (auto i=1; i<N; i++) {
    cin >> P[i];
    P[i]--;
    V[P[i]].push_back(i);
  }
  P[0] = -1;
  cin >> Q;
  for (auto i=0; i<Q; i++) {
    cin >> H[i];
  }
  fill(memo_depth, memo_depth+100010, -1);
  map<int, vector<int> > M;
  for (auto i=0; i<N; i++) {
    int d = depth(i);
    // cerr << "depth(" << i << ") = " << d << endl;
    M[-1*d].push_back(i);
  }
  int rel = 0;
  map<int, int> ans;
  for (auto x : M) {
    ans[-1*(x.first)] = rel;
    cerr << "ans[" << -1*(x.first) << "] = " << rel << endl;
    for (auto y : x.second) {
      rel -= (int)(V[y].size());
      cerr << rel << endl;
    }
    rel += (int)(x.second.size());
    cerr << rel << endl;
  }
  for (auto i=0; i<Q; i++) {
    if (ans.find(H[i]) != ans.end()) {
      cout << ans[H[i]] << endl;
    } else {
      cout << -1 << endl;
    }
  }
}
