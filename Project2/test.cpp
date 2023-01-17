#include <iostream>
#include <windows.h>
// #include <tchar.h>
using namespace std;
const auto filePath = "D:\\FPT\\C++\\Mock\\Project2\\data.ini";

string a = "hieu";
int w = 7;

int main(){
    // WritePrivateProfileString(TEXT("data"), TEXT("hieu"), TEXT("pt hieu"), TEXT(filePath));
    // WritePrivateProfileString(TEXT("data"), TEXT("hieu"), TEXT("pham trung hieu"), TEXT(filePath));
    char out[255] = "";
    // cout << GetPrivateProfileString(TEXT("id"), TEXT("age"), TEXT(""), out, 32, TEXT(filePath));
    // int val = GetPrivateProfileInt(a.c_str(), "win", 0, filePath);
    // cout << val;
    cout << GetPrivateProfileSectionNames(out, 255, filePath) << endl;
    // cout << GetPrivateProfileSection(a.c_str(), out, 255, filePath) << endl;;
    // for(LPCTSTR p = out; *p != 0; p += strlen(p) + 1){
    //     string val = p;
    //     cout << val << endl;
    //     if(val == "Chien"){
    //         cout << "Chien moi" << endl;
    //     }
    // }

    // WritePrivateProfileString("hieu", "win", "8", filePath);
    // WritePrivateProfileString("hieu", "win", to_string(w).c_str(), filePath);
    return 0;
}