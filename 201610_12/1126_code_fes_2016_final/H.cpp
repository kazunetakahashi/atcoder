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
int A[200010];
int M;
int X[200010];
int score[200010][2];

int main () {
  cin >> N;
  for (auto i = 0; i < N-1; i++) {
    cin >> A[i];
  }
  cin >> M;
  for (auto j = 0; j < M; j++) {
    cin >> X[j];
  }
  if (M > 1) return 0;
  A[N-1] = X[0];
  score[2][0] = A[0];
  score[2][1] = A[1];
  for (auto i = 2; i < N; i++) {
    for (auto j = 0; j < 2; j++) {
      
    }
  }
}
