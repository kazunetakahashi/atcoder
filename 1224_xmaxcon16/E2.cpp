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

typedef tuple<int, int, int> sim;

int A[30][50];
int ans[50];

void solve() {
  priority_queue<sim, vector<sim>, greater<sim> > Q;
  for (auto i = 0; i < 30; i++) {
    for (auto j = i+1; j < 30; j++) {
      int cnt = 0;
      for (auto k = 0; k < 50; k++) {
        if (A[i][k] == A[j][k]) {
          cnt++;
        }
      }
      Q.push(make_tuple(cnt, i, j));
    }
  }
  set<int> S;
  while ((int)S.size() < 20) {
    sim x = Q.top();
    int indx = get<1>(x);
    int indy = get<2>(x);
    Q.pop();
    S.insert(indx);
    S.insert(indy);
  }
  for (auto i = 0; i < 50; i++) {
    int count[4];
    fill(count, count+4, 0);
    for (auto x : S) {
      count[A[x][i]]++;
    }
    int maxi = 0;
    int ind = 0;
    for (auto j = 0; j < 4; j++) {
      if (maxi < count[j]) {
        maxi = count[j];
        ind = j;
      }
    }
    ans[i] = ind;
  }
}

int main () {
  for (auto t = 0; t < 200; t++) {
    for (auto i = 0; i < 30; i++) {
      for (auto j = 0; j < 50; j++) {
        cin >> A[i][j];
      }
    }
    solve();
    for (auto i = 0; i < 50; i++) {
      cout << ans[i];
      if (i < 49) {
        cout << " ";
      } else {
        cout << endl;
      }
    }
  }
}
