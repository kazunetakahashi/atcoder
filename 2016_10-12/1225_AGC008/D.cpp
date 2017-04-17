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

typedef pair<int, int> pass;

const int infty = 1000000000;

int N;
int M;
int x[510];
queue<int> Q;
queue<int> R;
int ans[300000];

int main () {
  cin >> N;
  set<int> S;
  for (auto i = 0; i < N; i++) {
    cin >> x[i];
    x[i]--;
    if (S.find(x[i]) != S.end()) {
      cout << "No" << endl;
      return 0;
    }
    S.insert(x[i]);
  }
  M = N*N;
  fill(ans, ans+M, infty);
  for (auto i = 0; i < N; i++) {
    ans[x[i]] = i;
  }
  vector<pass> V;
  for (auto i = 0; i < N; i++) {
    V.push_back(make_pair(x[i], i));
  }
  sort(V.begin(), V.end());
  // cerr << "Q" << endl;
  for (auto i = 0; i < N; i++) {
    for (auto j = 0; j < V[i].second; j++) {
      // cerr << V[i].second << endl;
      Q.push(V[i].second);
    }
  }
  for (auto i = 0; i < M; i++) {
    if (ans[i] == infty) {
      if (!Q.empty()) {
        int now = Q.front();
        if (i > x[now]) {
          cout << "No" << endl;
          return 0;
        }
        ans[i] = now;
        Q.pop();
      } else if (!R.empty()) {
        int now = R.front();
        ans[i] = now;
        R.pop();        
      } else {
        cout << "No" << endl;
        return 0;        
      }
    } else {
      // cerr << "R" << endl;
      for (auto j = 0; j < N-ans[i]-1; j++) {
        // cerr << ans[i] << endl;
        R.push(ans[i]);
      }
    }
  }
  cout << "Yes" << endl;
  for (auto i = 0; i < M; i++) {
    cout << ans[i]+1;
    if (i < M-1) {
      cout << " ";
    } else {
      cout << endl;
    }
  }
}
