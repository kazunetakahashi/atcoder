#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <random>
#include <fstream>
#include <algorithm>

#ifdef _MSC_VER
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

string query(string url) {

#ifdef _MSC_VER
  // Windowsは同梱のcurl.exeを適当なフォルダに配置してcurlコマンドを使えるようにしておくこと。
  FILE *f = _popen(("C:\\bin\\curl.exe -s \"" + url + "\"").c_str(), "r");
#else
  // Linux,MacOS,Cygwinはパッケージ管理システムなどでインストールしてcurlコマンドを使えるようにしておくこと。
  FILE *f = popen(("curl -s \"" + url + "\"").c_str(), "r");
#endif

  if (f == NULL) {
    perror("error!");
  }
  char buf[1024];
  string res;
  while (!feof(f)) {
    if (fgets(buf, 1024, f) == NULL) break;
    res += (string)(buf);
  }

#ifdef _MSC_VER
  _pclose(f);
#else
  pclose(f);
#endif

  return res;
}

char X(int a) {
  return (char)('A' + a);
}

string makestr() {
  string ret = "";
  random_device rd;
  mt19937 mt(rd());
  for (auto i=0; i<50; i++) {
    ret += X(mt()%4);
  }
  return ret;
}

const int C = 10;

string words[C] =
  { "BABADDBD", "BADABB", "DDBBBACD", "ADDCAAAC", "DBCCADAB", 
    "DCBCDBAAB", "DACAAAAC", "BAAADCCC", "DBADADDB", "BABADDBD" };

int main() {
  for (auto i=0; i<C; i++) {
    string token  = "CDAL5MHV8C1SDYJLPSE1U2UYZS7C7XJX";
    string str = words[i];
    string url    = "https://game.coderunner.jp/q?str=" 
      + str + "&token=" + token;
    string result = query(url);
    cout << str << " : " << result << endl;
    
#ifdef _MSC_VER
    Sleep(1000);
#else
    sleep(1);
#endif
  }

#ifdef _MSC_VER
  system("pause");
#endif

  return 0;
}
