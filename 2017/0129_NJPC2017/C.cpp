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
const ll infty = 10000000000007;

typedef pair<ll, ll> segment;

set<ll> S;
int N;
ll L;
ll x[100010];
vector<segment> reject;

int main () {
  cin >> N >> L;
  for (auto i = 0; i < N; i++) {
    cin >> x[i];
  }
  ll left = x[0] - 2 * L;
  ll right = x[0] - L;
  for (auto i = 1; i < N; i++) {
    ll kukan_left = x[i] - 2 * L;
    ll kukan_right = x[i] - L;
    if (kukan_left <= right) {
      right = kukan_right;
    } else {
      reject.push_back(segment(left, right));
      left = kukan_left;
      right = kukan_right;
    }
  }
  reject.push_back(segment(left, right));
  int M = reject.size();
  ll indi = 0;
  ll indj = 0;
  while (indi < N && indj < M) {
    cerr << indi << " " << indj << endl;
    ll need_left =  max(x[indi] - L, 0LL);
    ll need_right = x[indi];
    ll forbid_left = reject[indj].first;
    ll forbid_right = reject[indj].second;
    cerr << need_left << " " << need_right << " "
         << forbid_left << " " << forbid_right << endl;
    if (need_left < forbid_left) {
      indi++;
    } else {
      if (need_right <= forbid_right) {
        cout << "NO" << endl;
        return 0;
      } else if (need_left >= forbid_right) {
        indj++;
      } else {
        indi++;
      }
    }
  }
  cout << "YES" << endl;
}
