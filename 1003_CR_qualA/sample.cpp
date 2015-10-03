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

int main() {
  random_device rd;
  mt19937 mt(rd());
  string token = "D1307BDNFSM68CLQWVW9ALDW912YYWPE";
  string url;
  string result;
  while (true) {
    url = "https://coderunner.jp/index.html?token=" + token;
    result = query(url);
    cout << result << endl;
    sleep(1);
  }
  return 0;
}
