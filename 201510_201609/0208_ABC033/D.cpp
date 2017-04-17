#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef complex<double> point;
const double PI = 3.14159265359;
const double epsilon = 1e-9;

ll N;
point X[2010];
ll eikaku = 0;
ll eikakupluschokkaku = 0;
vector<double> V;

void subcount(ll* cnt, double bound) {
  ll indi = 0;
  ll indj = 1;
  while (indi < N-1) {
    if (V[indj] - V[indi] < bound) {
      indj++;
    } else {
      *cnt += indj - indi - 1;
      indi++;
    }
  }
}

void count(int x) {
  V.clear();
  double temp;
  for (auto i = 0; i < N; i++) {
    if (x == i) continue;
    temp = arg(X[i]-X[x]);
    V.push_back(temp);
    V.push_back(temp+2*PI);
  }
  sort(V.begin(), V.end());
  subcount(&eikaku, PI/2 - epsilon);
  subcount(&eikakupluschokkaku, PI/2 + epsilon);
}

int main() {
  cin >> N;
  double tx, ty;
  for (auto i = 0; i < N; i++) {
    cin >> tx >> ty;
    X[i] = point(tx, ty);
  }
  for (auto i = 0; i < N; i++) {
    count(i);
  }
  ll chokkaku = eikakupluschokkaku - eikaku;
  ll donkaku = N * (N-1) * (N-2) / 2 - eikaku - chokkaku;
  cout << N * (N-1) * (N-2) / 6 - donkaku - chokkaku << " "
       << chokkaku << " " << donkaku << endl;
}
