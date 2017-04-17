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
vector<int> A;
vector<int> B;
string S;

int main () {
  cin >> N;
  for (auto i = 0; i < N; i++) {
    int t;
    cin >> t;
    A.push_back(t);
  }
  cin >> S;
  int a = 0;
  int b = 0;
  for (auto x : S) {
    if (x == 'M') {
      a++;
    } else {
      b++;
    }
  }
  multiset<int> set;
  for (auto i = 0; i < a; i++) {
    set.insert(A[i]);
  }
  for (auto i = a; i < N; i++) {
    set.insert(A[i]);
    int t = *max_element(set.begin(), set.end());
    B.push_back(t);
    set.erase(set.find(A[i-a]));
  }
  set.clear();
  for (auto i = 0; i < b; i++) {
    set.insert(B[i]);
  }
  vector<int> C;
  for (auto i = b; i < N-a; i++) {
    set.insert(B[i]);
    int t = *min_element(set.begin(), set.end());
    C.push_back(t);
    set.erase(set.find(B[i-b]));
  }
  cout << C[0] << endl;
}
