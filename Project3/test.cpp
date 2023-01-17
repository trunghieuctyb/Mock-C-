#include <iostream>
#include <windows.h>
// #include <tchar.h>
using namespace std;
const auto filePath = "D:\\FPT\\C++\\Mock\\Project3\\Replay.ini";

string a = "hieu";
int w = 7;

int main(){
    // WritePrivateProfileString(TEXT("data"), TEXT("hieu"), TEXT("pt hieu"), TEXT(filePath));
    // WritePrivateProfileString(TEXT("data"), TEXT("hieu"), TEXT("pham trung hieu"), TEXT(filePath));
    char out[255] = "";
    // cout << GetPrivateProfileString(TEXT("id"), TEXT("age"), TEXT(""), out, 32, TEXT(filePath));
    // int val = GetPrivateProfileInt(a.c_str(), "win", 0, filePath);
    // cout << val;
    GetPrivateProfileSectionNames(out, 255, filePath);
    // cout << GetPrivateProfileSection(a.c_str(), out, 255, filePath) << endl;;
    // for(LPCTSTR p = out; *p != 0; p += strlen(p) + 1){
    //     string val = p;
    //     cout << val << endl;
    //     if(val == "Chien"){
    //         cout << "Chien moi" << endl;
    //     }
    // }
    for(LPCTSTR p = out; *p != 0; p += strlen(p) + 1){
        string val = p;
        char name1[15] = "", name2[15] = "";
        GetPrivateProfileString(val.c_str(), "player1", "", name1, 15, filePath);
        GetPrivateProfileString(val.c_str(), "player2", "", name2, 15, filePath);
        cout << p << ". " << name1 << " vs " << name2 << endl;
    }
    // cout << GetPrivateProfileString("1", "data", "", out, 255, filePath) << endl;
    // cout << out;
    // int a = GetPrivateProfileSectionNames(NULL, 255, filePath);
    // WritePrivateProfileString(to_string(5).c_str(), "player2", "8", filePath);
    // WritePrivateProfileString("hieu", "win", to_string(w).c_str(), filePath);
    return 0;
}