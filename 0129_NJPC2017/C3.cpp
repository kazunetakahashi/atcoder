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

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C ;
// const ll M = 1000000007;

int N;
ll L;
ll x[100010];

int main () {
  cin >> N >> L;
  for (auto i = 0; i < N; i++) {
    cin >> x[i];
  }
  if (N == 1) {
    cout << "YES" << endl;
    return 0;
  }
  for (auto i = 1; i < N; i++) {
    if (x[i] - x[i-1] == L) {
      cout << "NO" << endl;
      return 0;   
    }
  }
  int place = 0;
  int left = 0;
  for (auto right = 0; right < N-1; right++) {
    if (x[right+1] - x[right] < L) {
      // cerr << right << " and " << right+1 << endl;
      continue;
    } else {
      if (x[right] - x[left] >= L) {
        // cerr << right << " and " << left << " : " << x[right] - x[left] << endl;
        cout << "NO" << endl;
        return 0;
      } else {
        place = max(place + 2 * L, x[right] + L);
        // cerr << "place = " << place << endl;
        if (place >= x[right+1]) {
          // cerr << "place >= " << "x[" << right+1 << "] = " << x[right+1] << endl;
          cout << "NO" << endl;
          return 0;
        } else {
          // cerr << "left = " << right << endl;
          left = right+1;
        }
      }      
    }
  }
  if (x[N-1] - x[left] >= L) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
}
