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
int K, L;
vector<int> V[200010];
vector<int> W[200010];
bool visited[200010];
bool visited2[200010];
int ans[200010];
set<int> S;
set<int> SS;

int main () {
  cin >> N >> K >> L;
  for (auto i = 0; i < K; i++) {
    int p, q;
    cin >> p >> q;
    p--; q--;
    V[p].push_back(q);
    V[q].push_back(p);
  }
  for (auto i = 0; i < L; i++) {
    int r, s;
    cin >> r >> s;
    r--; s--;
    W[r].push_back(s);
    W[s].push_back(r);
  }
  fill(visited, visited+200010, false);
  fill(visited2, visited2+200010, false);
  for (auto i = 0; i < N; i++) {
    if (visited[i]) continue;
    S.clear();
    stack<int> St;
    St.push(i);
    while (!St.empty()) {
      int src = St.top();
      // cerr << "src = " << src << endl;
      St.pop();
      if (!visited[src]) {
        visited[src] = true;
        S.insert(src);
        for (auto dst : V[src]) {
          if (!visited[dst]) {
            St.push(dst);
          }
        }
      }
    }
    for (auto j : S) {
      if (visited2[j]) continue;
      SS.clear();
      stack<int> SSt;
      SSt.push(j);
      while (!SSt.empty()) {
        int src = SSt.top();
        SSt.pop();
        if (!visited2[src]) {
          visited2[src] = true;
          SS.insert(src);
          for (auto dst : W[src]) {
            if (!visited2[dst] && (S.find(dst) != S.end())) {
              SSt.push(dst);
            }
          }
        }
      }
      for (auto x : SS) {
        ans[x] = (int) SS.size();
      }
    }
  }
  for (auto i = 0; i < N; i++) {
    cout << ans[i];
    if (i < N-1) {
      cout << " ";
    } else {
      cout << endl;
    }
  }
}
