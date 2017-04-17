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
ll A[100010];
ll B[100010];
ll C[100010];
ll n[100010];
ll ans[100010];

int main () {
  cin >> N;
  for (auto i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }
  reverse(A, A+N);
  reverse(B, B+N);
  for (auto i = 0; i < N; i++) {
    C[i] = A[i]%B[i];
    if (C[i] != 0) {
      C[i] = B[i] - C[i];
    }
  }
  ans[0] = C[0];
  n[0] = 0;
  for (auto i = 0; i < N-1; i++) {
    ll temp = C[i+1] - C[i] - B[i] * n[i];
    if (temp >= 0) {
      ans[i+1] = temp;
      n[i+1] = 0;
    } else {
      ll plus = abs(temp) % B[i+1];
      ll sho = abs(temp) / B[i+1];
      if (plus == 0) {
        ans[i+1] = 0;
        n[i+1] = sho;
      } else {
        ans[i+1] = B[i+1] - plus;
        n[i+1] = sho+1;
      }
    }
  }
  ll sum = 0;
  for (auto i = 0; i < N; i++) {
    sum += ans[i];
  }
  cout << sum << endl;
}
