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

string XX(int a) {
  string ret = "";
  ret += X(a);
  return ret;
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

string words[3] = { "CBBDBBDACAAAAC",
		    "DDADBCADCBCDBAABCCDCDDDBBBACDADBACC", "A" };

int main() {
  int hairetsu[3] = {0, 1, 2};
  // words[2] = XX(i);
  for (auto i=0; i<4; i++) {
    words[2] = XX(i);
    do {
      string token  = "CDAL5MHV8C1SDYJLPSE1U2UYZS7C7XJX";
      string str = "";
      for (auto i=0; i<3; i++) {
	str += words[hairetsu[i]];
      }
      string url    = "https://game.coderunner.jp/q?str=" 
	+ str + "&token=" + token;
      string result = query(url);
      cout << str << " : " << result << endl;
    
#ifdef _MSC_VER
      Sleep(1000);
#else
      sleep(1);
#endif
    } while (next_permutation(hairetsu, hairetsu+3));
  }

#ifdef _MSC_VER
  system("pause");
#endif

  return 0;
}
