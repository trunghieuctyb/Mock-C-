/*
    class DatabaseManager
        insertPlayer();
        getWin();
        getLose();
        getDraw();
        show();
        getPersent();
        updateMatch();
*/
#pragma once
#include <windows.h>
#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

const auto filePath = "D:\\FPT\\C++\\Mock\\Project2\\data.ini";

class INIFile{   
    public:
        void checkName(string name){
            char out[255] = "";
            GetPrivateProfileSectionNames(out, 255, filePath);
            for(LPCTSTR p = out; *p != 0; p += strlen(p) + 1){
                string val = p;
                if(val == name){
                    return;
                }
            }
            WritePrivateProfileString(name.c_str(), "win", "0", filePath);
            WritePrivateProfileString(name.c_str(), "lose", "0", filePath);
            WritePrivateProfileString(name.c_str(), "draw", "0", filePath);
            WritePrivateProfileString(name.c_str(), "winrate", "0", filePath);
        }
        int getWin(string name){
            return GetPrivateProfileInt(name.c_str(), "win", 0, filePath);
        }
        int getLose(string name){
            return GetPrivateProfileInt(name.c_str(), "lose", 0, filePath);
        }
        int getDraw(string name){
            return GetPrivateProfileInt(name.c_str(), "draw", 0, filePath);
        }
        int getWR(string name){
            return GetPrivateProfileInt(name.c_str(), "winrate", 0, filePath);
        }
        void winRate(string name){
            int WR = (getWin(name)*100) / (getWin(name) + getLose(name) + getDraw(name));
            WritePrivateProfileString(name.c_str(), "winrate", to_string(WR).c_str(), filePath);
        }
        void show(string name){
            cout << "Player: " << name << endl;
            cout <<"Win: "<<getWin(name)<<"  "<<"Lose: "<<getLose(name)<<" "<<"Draw: "<<getDraw(name);
            cout <<" "<< "Win Rate: "<<getWR(name)<<endl;
        }
        void update(string name, string key){
            char wr[255] = "";
            if(getWin(name)==0 && getLose(name)==0 && getDraw(name)==0){
                WritePrivateProfileString(name.c_str(), key.c_str(), "1", filePath);
            }
            else{
                int val = GetPrivateProfileInt(name.c_str(), key.c_str(), 0, filePath) + 1;
                WritePrivateProfileString(name.c_str(), key.c_str(), to_string(val).c_str(), filePath);
            }
            winRate(name);
        }

        vector<string> findWR(string name){
            char out[255] = "";
            vector<int> aWR;
            vector<string> opponent;
            GetPrivateProfileSectionNames(out, 255, filePath);
            for(LPCTSTR p = out; *p != 0; p += strlen(p) + 1){
                string val = p;
                if(val != name){
                    int a = getWR(val) - getWR(name);
                    aWR.push_back(a);
                }
            }
            sort(aWR.begin(), aWR.end());
            int wr = aWR[0] + getWR(name);
            for(LPCTSTR p = out; *p != 0; p += strlen(p) + 1){
                string val = p;
                if(val != name){
                    if(getWR(val) == wr){
                        opponent.push_back(val);
                    }
                }
            }
            return opponent;
        }
};