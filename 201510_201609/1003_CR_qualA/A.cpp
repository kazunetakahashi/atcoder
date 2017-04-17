#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <algorithm>
#include <random>
#include <vector>

using namespace std;

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
  while (true) {
    string choten;
    V.clear();
    int x = mt()%1000;
    int y = mt()%1000;
    V.push_back(x);
    V.push_back(y);
    choten = vert(V);
    url = "https://game.coderunner.jp/query?token=" + token + "&v=" + choten;
    result = query(url);
    cout << result + " " + vert_ch(V) << endl;
    sleep(1);
  }
  return 0;
}
