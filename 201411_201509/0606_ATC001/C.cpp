#include <iostream>
#include <complex>
#include <vector>
using namespace std;

const int N = (1 << 18); // 最大次数
const double PI = acos(-1);
typedef complex<double> comp;

vector<comp> dft(vector<comp> f, int n, bool doesinv) {
  if (n == 1) return f;
  vector<comp> f0, f1;
  for (auto i=0; i<n/2; i++) {
    f0.push_back(f[2*i]);
    f1.push_back(f[2*i+1]);
  }
  f0 = dft(f0, n/2, doesinv);
  f1 = dft(f1, n/2, doesinv);
  comp zeta;
  if (!doesinv) {
    zeta = comp(cos(2 * PI/n), sin(2 * PI/n));
  } else {
    zeta = comp(cos(2 * PI/n), -1 * sin(2 * PI/n));
  }
  comp pow_zeta = comp(1, 0);
  for (auto i=0; i<n; i++) {
    f[i] = f0[i % (n/2)] + pow_zeta * f1[i % (n/2)];
    pow_zeta = pow_zeta * zeta;
  }
  return f;
}

vector<comp> multiply(vector<comp> g, vector<comp> h) {
  vector<comp> gg = dft(g, N, false);
  vector<comp> hh = dft(h, N, false);
  vector<comp> ff = vector<comp>(N);
  for (auto i=0; i<N; i++) {
    ff[i] = gg[i] * hh[i];
  }
  vector<comp> ans = dft(ff, N, true);
  for (auto i=0; i<N; i++) {
    ans[i] = ans[i] / comp(N, 0);
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<comp> f = vector<comp>(N, comp(0, 0));
  vector<comp> g = vector<comp>(N, comp(0, 0));
  int a, b;
  for (auto i=0; i<n; i++) {
    cin >> a >> b;
    f[i] = comp(a, 0);
    g[i] = comp(b, 0);
  }
  vector<comp> h = multiply(f, g);
  cout << 0 << endl;
  for (auto i=0; i<(2 * n - 1); i++) {
    cout << llround(h[i].real()) << endl;
  }
}
