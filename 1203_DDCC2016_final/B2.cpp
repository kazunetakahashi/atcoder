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

double R;
int N;
int M;
double cuts[1010];

double cut(int i) {
  if (i <= 0 || i >= N) return 0;
  double k = (R - (2 * R * i) / N);
  return 2 * sqrt(R * R - k * k);
}

double res(int i) {
  if (i <= 0 || i >= N) return 0;
  return cuts[i];
}

int main () {
  cin >> R >> N >> M;
  for (auto i = 0; i < N; i++) {
    cuts[i] = cut(i);
  }
  double ans = 0;
  for (auto i = 0; i <= (N+1)/2; i++) {
    ans += cut(i);
  }
  cout << fixed << setprecision(12) << ans << endl;
}
