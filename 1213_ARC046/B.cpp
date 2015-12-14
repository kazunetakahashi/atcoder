#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int A, B;
  cin >> A >> B;
  if (N <= A) {
    cout << "Takahashi" << endl;
  } else if (A == B) {
    cout << ((N%(A+1) != 0) ? "Takahashi" : "Aoki") << endl;
  } else {
    cout << ((A > B) ? "Takahashi" : "Aoki") << endl;
  }
}
