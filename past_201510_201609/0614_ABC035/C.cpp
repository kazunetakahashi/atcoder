#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  int l[200010];
  int r[200010];
  for (auto i = 0; i < Q; i++) {
    cin >> l[i] >> r[i];
    l[i]--;
    r[i]--;
  }
  int imos[200010];
  fill(imos, imos+200010, 0);
  for (auto i = 0; i < Q; i++) {
    imos[l[i]]++;
    imos[r[i]+1]--;
  }
  for (auto i = 0; i < N; i++) {
    imos[i+1] += imos[i];
  }
  /*
  for (auto i = 0; i < N; i++) {
    cerr << imos[i];
  }
  cerr << endl;
  */
  for (auto i = 0; i < N; i++) {
    cout << imos[i]%2;
  }
  cout << endl;
}
