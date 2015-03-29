#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <stack>
using namespace std;

int N = 10;
string A;
string W;

int mandc(int l, int r) {
  W = A;
  if (l+1 >= r) return 0;
  if (l+2 == r) {
    if (A[l] <= A[l+1]) return 0;
    swap(A[l], A[l+1]);
    return 1;
  }
  int m = (l+r)/2;
  int cl = mandc(l, m);
  int cr = mandc(m, r);
  int c = 0;
  int i = l, j = m;
  int k = l;
  while (i < m && j < r) {
    if (A[i] <= A[j]) {
      W[k++] = A[i++];
    } else {
      W[k++] = A[j++];
      c += m - i; 
    }
  }
  while (i<m) W[k++] = A[i++];
  while (j<r) W[k++] = A[j++];
  assert (k == r);
  copy(W.begin()+l, W.begin()+r, A.begin()+l);
  return cl + cr + c;
}

int main() {
  int T;
  cin >> T;
  for (auto i=0; i<T; i++) {
    cin >> A;
    int x = mandc(0, N);
    // cerr << "x = " << x << endl;
    cout << x%2 << endl;
  }
}
