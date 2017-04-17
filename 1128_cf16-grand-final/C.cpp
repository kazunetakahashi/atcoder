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
int b[100010];

int count(int k) {
  int ans = 0;
  while (k != 0) {
    if ((k & 1) == 1) {
      ans++;
    }
    k = (k >> 1);
  }
  return ans;
}

int main () {
  cin >> N;
  for (auto i = 0; i < N; i++) {
    cin >> a[i];
    b[i] = (a[i] ^ (a[i] - 1));
    // cerr << b[i] << endl;
  }
  int x = 0;
  for (auto i = 0; i < N; i++) {
    x = x ^ a[i];
  }
  vector<int> V;
  if (x == 0) {
    cout << 0 << endl;
    return 0;
  }
  while (x != 0) {
    V.push_back(x & 1);
    x = (x >> 1);
  }
  bool visited[100];
  fill(visited, visited+100, true);
  int need = 0;
  for (auto i = 0; i < (int)V.size()-1; i++) {
    if (V[i+1] != V[i]) {
      need++;
      visited[i] = false;
    }
  }
  if (!V.empty()) {
    visited[(int)V.size()-1] = false;
    need++;
  }
  for (auto i = 0; i < N; i++) {
    visited[count(b[i])-1] = true;
  }
  for (auto i = 0; i < 100; i++) {
    if (!visited[i]) {
      cout << "-1" << endl;
      return 0;
    }
  }
  cout << need << endl;
  return 0;
}
