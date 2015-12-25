#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  int Z[110];
  for (auto i = 0; i < N; i++) {
    cin >> Z[i];
  }
  for (auto i = 0; i < N; i++) {
    int X, B, C;
    if (Z[i] == 2){
      cout << 5 << endl;
      cout << "0 1 1 1 2" << endl;
    } else if (Z[i] == 3) {
      cout << 5 << endl;
      cout << "3 3 4 4 6" << endl;
    } else if (Z[i] <= 3) {
      cout << "No" << endl;
    } else if (Z[i]%4 == 0) {
      cout << 5 << endl;
      cout << "0 1 0 " << Z[i]/4 << " " << Z[i]-2 << endl;
    } else {
      X = 4 * (Z[i]/16) + Z[i]%4;
      B = (Z[i]-X)/4;
      C = Z[i]-X;
      cout << 5 << endl;
      cout << X << " " << 1 << " " << 0 << " " << B << " " << C << endl;
    }
  }
}
