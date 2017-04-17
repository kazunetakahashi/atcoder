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

int N, Q;
int A[100010], B[100010];
int h[100010];
bool visited[100010];

int main () {
  cin >> N >> Q;
  for (auto i = 0; i < Q; i++) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
  }
  h[0] = 0;
  for (auto i = 0; i < Q; i++) {
    if (A[i] == h[i]) {
      h[i+1] = B[i];
    } else if (B[i] == h[i]) {
      h[i+1] = A[i];
    } else {
      h[i+1] = h[i];
    }
    //cerr << "h[" << i+1 << "] = " << h[i+1] << endl;
  }
  fill(visited, visited+100010, false);
  visited[0] = true;
  visited[1] = true;
  for (auto i = 0; i < Q; i++) {
    swap(visited[A[i]], visited[B[i]]);
    if (0 <= h[i+1]-1 && h[i+1]-1 < N) {
      visited[h[i+1]-1] = true;
    }
    if (0 <= h[i+1]+1 && h[i+1]+1 < N) {
      visited[h[i+1]+1] = true;
    }
    for (auto j = 0; j < N; j++) {
      //cerr << (visited[j] ? "x" : ".");
    }
    //cerr << endl;
  }
  int ans = 0;
  for (auto i = 0; i < N; i++) {
    if (visited[i]) ans++;
  }
  cout << ans << endl;
}
