#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <algorithm>
#include <random>
#include <vector>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> info;

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
  sort(seed.begin(), seed.end());
  reverse(seed.begin(), seed.end());  
  for (unsigned i=0; i<seed.size(); i++) {
    cout << get<0>(seed[i]) << " " << get<1>(seed[i]) << " "
         << get<2>(seed[i]) << endl;
  }
  return 0;
}
