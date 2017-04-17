#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <algorithm>
#include <random>
#include <vector>
#include <tuple>
#include <cmath>
#include <iomanip>

using namespace std;

typedef tuple<int, int, int> info;
typedef tuple<double, int, int> kaku;

string query(string url) {
  FILE *f = popen(("curl -s -k \"" + url + "\"").c_str(), "r");
  if (f == NULL) {
    perror("error!");
  }
  char buf[1024];
  string res;
  while (!feof(f)) {
    if (fgets(buf, 1024, f) == NULL) break;
    res += (string)(buf);
  }
  pclose(f);
  return res;
}

string vert(vector<int> V) {
  string res = "";
  for (unsigned i=0; i<V.size(); i++) {
    res += to_string(V[i]);
    if (i != V.size()-1) {
      res += ",";
    }
  }
  return res;
}

string vert_ch(vector<int> V) {
  string res = "";
  for (unsigned i=0; i<V.size(); i++) {
    res += to_string(V[i]);
    if (i != V.size()-1) {
      res += " ";
    }
  }
  return res;
}

int main() {
  random_device rd;
  mt19937 mt(rd());
  string token = "D1307BDNFSM68CLQWVW9ALDW912YYWPE";
  string url;
  string result;
  vector<int> V;
  int score;
  vector<info> seed;
  while (cin >> score) {
    int x, y;
    cin >> x >> y;
    seed.push_back(make_tuple(score, x, y));
  }
  for (unsigned i=0; i<seed.size(); i++) {
    vector<int> x = vector<int>(4);
    double a, b, c, d, e;
    a= get<0>(seed[i]);
    x[0] = get<1>(seed[i]);
    x[1] = get<2>(seed[i]);
    cout << "======= i = " << i << " =======" << endl;
    cout << "0 " << a << " " << x[0] << " " << x[1] << endl;
    for (unsigned j=i+1; j<seed.size(); j++) {
      x[2] = get<1>(seed[j]);
      x[3] = get<2>(seed[j]);
      if (x[0] == x[2] || x[0] == x[3] || x[1] == x[2] || x[1] == x[3]) {
        continue;
      }
      b = get<0>(seed[j]);
      string choten = vert(x);
      url = "https://game.coderunner.jp/query?token=" + token + "&v=" + choten;
      result = query(url);
      sleep(1);
      if (result == "0") {
        continue;
      }
      c = stoi(result);
      url = "https://game.coderunner.jp/query?token=" + token + "&v=" + to_string(x[1]) + "," + to_string(x[3]);
      result = query(url);
      d = stoi(result);
      sleep(1);
      url = "https://game.coderunner.jp/query?token=" + token + "&v=" + to_string(x[2]) + "," + to_string(x[0]);
      result = query(url);
      e = stoi(result); 
      sleep(1);
      double cos1 = (a*a + c*c - d*d) / (2*a*c);
      double cos2 = (b*b + c*c - e*e) / (2*b*c);
      cos1 = min(cos1, 1.0);
      cos2 = min(cos2, 1.0);
      cos1 = max(cos1, -1.0);
      cos2 = max(cos2, -1.0);
      double sin1 = sqrt(1 - cos1 * cos1);
      double sin2 = sqrt(1 - cos2 * cos2);
      double cos1minus2 = cos1 * cos2 + sin1 * sin2;
      cout << fixed << setprecision(10) << 1.0 - cos1minus2 << " " << b << " " << x[2] << " " << x[3] << endl;
    }
  }
  return 0;
}
