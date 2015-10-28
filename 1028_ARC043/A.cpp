#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int N;
  double A, B;
  cin >> N >> A >> B;
  int S[100010];
  double M = 0;
  int alpha = -1;
  int beta = (1 << 30);
  for (auto i=0; i<N; i++) {
    cin >> S[i];
    M += S[i];
    alpha = max(alpha, S[i]);
    beta = min(beta, S[i]);
  }
  M /= N;
  if (alpha == beta) {
    cout << -1 << endl;
    return 0;
  }
  double P = B/(alpha-beta);
  double Q = A - P * M;
  cout << fixed << setprecision(10) << P << " " << Q << endl;
}
