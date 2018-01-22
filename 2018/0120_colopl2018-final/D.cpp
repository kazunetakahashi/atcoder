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
#include <random> // random_device rd; mt19937 mt(rd());
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.
// insert #if<tab> by my emacs. #if DEBUG == 1 ... #end

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

class BIT { // index starts at 1.
public:
  int N;
  ll* data;

  BIT(int n) : N(n) {
    data = new ll[N+1];
    for (auto i = 1; i <= N; ++i) {
      data[i] = 0;
    }
  }

  ~BIT() {
    delete[] data;
  }

  ll sum(int i) { // [1, i]
    ll s = 0;
    while (i > 0) {
      s += data[i];
      i -= i & -i;
    }
    return s;
  }

  ll sum(int a, int b) { // [a, b)
    return sum(b - 1) - sum(a - 1);
  }

  void add(int i, ll x) {
    while (i <= N) {
      data[i] += x;
      i += i & -i;
    }
  }

  void add(int i) {
    add(i, 1);
  }
  
};

int N;
typedef tuple<int, int> board;
vector<board> V;
set<int> S;

const long long MOD = 1000000007;

long long power(long long x, long long n) {
  if (n == 0) {
    return 1;
  } else if (n%2 == 1) {
    return (x * power(x, n-1)) % MOD;
  } else {
    long long half = power(x, n/2);
    return (half * half) % MOD;
  }
}

int main () {
  cin >> N;
  int infty = 2*N + 100;
  BIT bit(infty);
  
  for (auto i = 0; i < N; ++i) {
    int A, B;
    cin >> A >> B;
    if (A > B) swap(A, B);
    V.push_back(make_tuple(A, B));
  }
  sort(V.begin(), V.end());
  ll ans = 0;
  bit.add(get<0>(V[0]));
  bit.add(get<1>(V[0]));
  for (auto i = 1; i < N; ++i) {
    ll nans = (2 * ans) % MOD;
    int A = get<1>(V[i]);
    nans += (bit.sum(A+1, infty) * power(2, i-1))%MOD;
    ans = nans;
    bit.add(get<0>(V[i]));
    bit.add(get<1>(V[i]));
  }
  cout << ans << endl;
}
