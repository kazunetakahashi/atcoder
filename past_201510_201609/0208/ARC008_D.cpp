#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef long long ll;

const int C = 330;
const int C2 = C*C;

ll N;
int M;
ll p[100010];
double a[100010];
double b[100010];

struct oishikunaru {
  double a;
  double b;

  oishikunaru() {
  }
  
  oishikunaru(double ta, double tb) {
    a = ta;
    b = tb;
  }
};

oishikunaru operator * (const oishikunaru& left, const oishikunaru& right) {
  return oishikunaru(left.a * right.a, right.a * left.b + right.b);
}

oishikunaru conv[C][C];
oishikunaru skip[C];

set<ll> S;
map<ll, int> X;

double koushin(int ind, double a, double b) {
  conv[ind/C][ind%C] = oishikunaru(a, b);
  oishikunaru ans(1, 0);
  for (auto i = 0; i < C; i++) {
    ans = ans * conv[ind/C][i];
  }
  skip[ind/C] = ans;
  ans.a = 1, ans.b = 0;
  for (auto i = 0; i < C; i++) {
    ans = ans * skip[i];
  }
  return ans.a + ans.b;
}

int main() {
  cin >> N >> M;
  for (auto i = 0; i < M; i++) {
    cin >> p[i] >> a[i] >> b[i];
  }
  for (auto i = 0; i < M; i++) {
    S.insert(p[i]);
  }
  int ind = 0;
  for (auto x : S) {
    X[x] = ind++;
  }
  oishikunaru unit(1, 0);
  fill(&conv[0][0], &conv[0][0]+C2, unit);
  fill(skip, skip+C, unit);
  double mini = 1;
  double maxi = 1;
  for (auto i = 0; i < M; i++) {
    double temp = koushin(X[p[i]], a[i], b[i]);
    mini = min(mini, temp);
    maxi = max(maxi, temp);
  }
  cout << fixed << setprecision(10) << mini << endl;
  cout << fixed << setprecision(10) << maxi << endl;
}
