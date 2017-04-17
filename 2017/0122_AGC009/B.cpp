#include <iostream>
#include <iomanip> // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple> // get<n>(xxx)
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set> // S.insert(M);
// if (S.find(key) != S.end()) { }
// for (auto it=S.begin(); it != S.end(); it++) { }
// auto it = S.lower_bound(M);
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;

typedef long long ll;

//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};

// const int C ;
// const int M = 1000000007;

int N;
int a[100010];
int ans[100010];
vector<int> V[100010];

int calc(int root) {
  if (ans[root] >= 0) return ans[root];
  if (V[root].empty()) {
    return ans[root] = 0;
  }
  vector<int> T;
  for (auto x : V[root]) {
    T.push_back(calc(x));
    // cerr << "calc(" << x << ") = " << calc(x) << endl;
  }
  sort(T.begin(), T.end());
  reverse(T.begin(), T.end());
  int M = T.size();
  for (auto i = 0; i < M; i++) {
    T[i] += i+1;
  }
  return ans[root] = *max_element(T.begin(), T.end());
}

int main () {
  cin >> N;
  a[0] = -1;
  for (auto i = 1; i < N; i++) {
    cin >> a[i];
    a[i]--;
    V[a[i]].push_back(i);
  }
  fill(ans, ans+N, -1);
  cout << calc(0) << endl;
}
