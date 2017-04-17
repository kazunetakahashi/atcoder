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

vector<int> V;

int main () {
  int t;
  cin >> t;
  V.push_back(2);
  V.push_back(2);
  V.push_back(1);
  V.push_back(2);
  V.push_back(1);
  V.push_back(2);
  V.push_back(1);
  V.push_back(1);
  V.push_back(1);
  V.push_back(3);
  V.push_back(1);
  V.push_back(1);
  
  while((int)V.size() < 200*30*50) {
    V.push_back(0);
  }
  
  int x = V.size();
  cout << x << endl;
  for (auto i = 0; i < x; i++) {
    cout << V[i];
    if (i < x-1) {
      cout << " ";
    } else {
      cout << endl;
    }
  }
  // cerr << x << endl;
}
