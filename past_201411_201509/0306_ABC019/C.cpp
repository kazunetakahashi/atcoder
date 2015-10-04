#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main() {
  int N;
  int a[100010];
  cin >> N;
  set<int> S;
  for (auto i=0; i<N; i++) {
    cin >> a[i];
    a[i] /= (a[i] & -a[i]);
    S.insert(a[i]);
  }
  cout << S.size() << endl;
}
