#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>

#ifdef _MSC_VER
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

string query(string url) {

#ifdef _MSC_VER
// Windowsは同梱のcurl.exeを適当なフォルダに配置してcurlコマンドを使えるようにしておくこと。
    FILE *f = _popen(("C:\\bin\\curl.exe -s -k \"" + url + "\"").c_str(), "r");
#else
// Linux,MacOS,Cygwinはパッケージ管理システムなどでインストールしてcurlコマンドを使えるようにしておくこと。
    FILE *f = popen(("curl -s -k \"" + url + "\"").c_str(), "r");
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

int main() {
    for (int itr = 0; itr < 2; itr++) {
        string token  = "xxxxxxx";
        string url    = "https://coderunner.jp/index.html?token=" + token;
        string result = query(url);
        cout << result << endl;
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
