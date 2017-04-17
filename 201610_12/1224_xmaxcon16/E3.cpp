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

int A[30][50];
int ans[50];
typedef pair<int, int> score;

void solve() {
  int ans_kari[50];
  for (auto j = 0; j < 50; j++) {
    int cnt[4];
    fill(cnt, cnt+4, 0);
    for (auto i = 0; i < 30; i++) {
      cnt[A[i][j]]++;
    }
    int maxi = 0;
    int ind = 0;
    for (auto i = 0; i < 4; i++) {
      if (maxi < cnt[i]) {
        maxi = cnt[i];
        ind = i;
      }
    }
    ans_kari[j] = ind;
  }
  vector<score> V;
  for (auto i = 0; i < 30; i++) {
    int s = 0;
    for (auto j = 0; j < 50; j++) {
      if (A[i][j] == ans_kari[j]) s++;
    }
    V.push_back(make_pair(s, i));
  }
  sort(V.begin(), V.end());
  reverse(V.begin(), V.end());
  set<int> S;
  for (auto i = 0; i < 10; i++) {
    S.insert(V[i].second);
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
