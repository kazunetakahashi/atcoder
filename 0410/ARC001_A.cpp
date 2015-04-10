#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  int A[4];
  fill(A, A+4, 0);
  for (auto i=0; i<N; i++) {
    int x = S[i] - '0' - 1;
    A[x]++;
  }
  sort(A, A+4);
  cout << A[3] << " " << A[0] << endl;
}
