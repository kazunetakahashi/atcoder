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

string P[100010];
int a[26];

int main () {
  int N, K;
  cin >> N >> K;
  for (auto i = 0; i < N; i++) {
    cin >> P[i];
  }
  fill(a, a+26, 0);
  for (auto i = 0; i < N; i++) {
    a[P[i][0] - 'A']++;
  }
  int ans = 0;
  while (true) {
    sort(a, a+26);
    reverse(a, a+26);
    bool ok = false;
    int cnt = 0;
    for (auto i = 0; i < 26; i++) {
      if (a[i] > 0) {
        a[i]--;
        cnt++;
        if (cnt == K) {
          ok = true;
          break;
        }
      }
    }
    if (ok) {
      ans++;
    } else {
      break;
    }
  }
  cout << ans << endl;
}
