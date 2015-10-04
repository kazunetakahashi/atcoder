#include <iostream>
#include <cmath>
using namespace std;

int main () {
  int N;
  cin >> N;
  double sum = 0;
  int L = 0;
  for (auto i=0; i<N; i++) {
    int A;
    cin >> A;
    if (A != 0) {
      sum += A;
      L++;
    }
  }
  cout << ceil(sum/L) << endl;
}
