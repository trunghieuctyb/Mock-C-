#include "CaroMatch.cpp"
#include "INIfile.h"
using namespace std;

int main(){
    CaroMatch * cm = new CaroMatch();
    string player1 = "", player2 = "";
    INIFile * db = new INIFile();
    int menu;
    while(1){
        cm->draw();
        system("cls");
        cout << "1.Play game : " << endl;
        cout << "2.Replay :" << endl;
		cout << "3.Check profile : " << endl;
        cout << "4.Find opponent : " << endl;
		cout << "5.Exit" << endl;
		cout << "Select sevice>>";
		cin >> menu;
        if(menu == 1){
            cm->Data.clear();
            cm->sData.clear();
            system("cls");
            do{
                cout << "input player 1 name: " << endl;
                cin >> player1;
            }while(player1 == "");
            do{
                cout << "input player 2 name: " << endl;
                cin >> player2;

            }while(player2 == "");
            db->checkName(player1);
            db->checkName(player2);
            while(1){
                system("cls");
                cm->display();
                cm->playerInput(cm->Data);
                if (cm->checkWin()){
                    int x = cm->Data.size() - 1;
                    if (x % 2 == 0){
                        cm->display();
                        cout << player1 << " win " << endl;	
                        db->update(player1, "win");
                        db->update(player2, "lose");
                        cm->addReplay(player1, player2);
                        system("pause");
                        break;
                    }
                    else{
                        cm->display();
                        cout << player2 << " win" << endl;
                        db->update(player2, "win");
                        db->update(player1, "lose");
                        cm->addReplay(player1, player2);
                        system("pause");
                        break;
                    }
                }
                if (cm->checkDraw()){
                    cm->display();
                    cout << player1 << " Drawn " << player2 << endl;
                    db->update(player1, "draw");
                    db->update(player1, "draw");
                    cm->addReplay(player1, player2);
                    system("pause");
                    break;
                }
            }
        }
        else if(menu == 2){
            int n;
            char id[255] = "";
            GetPrivateProfileSectionNames(id, 255, fileReplay);
            for(LPCTSTR p = id; *p != 0; p += strlen(p) + 1){
                string val = p;
                char name1[15] = "", name2[15] = "";
                GetPrivateProfileString(val.c_str(), "player1", "", name1, 15, fileReplay);
                GetPrivateProfileString(val.c_str(), "player2", "", name2, 15, fileReplay);
                cout << p << ". " << name1 << " vs " << name2 << endl;
            }
            cout << "Select match>>";
            cin >> n;
            char data[200] = "";
            int length = GetPrivateProfileString(to_string(n).c_str(), "data", "", data, 200, fileReplay);
            for(int i = 0; i < length; i += 2){
                int x = int(data[i] - '0');
                int y = int(data[i+1] - '0');
                if(i % 4 == 0){
                    cm->gamePad[x][y] = 'X';
                }
                else if(i % 4 == 2){
                    cm->gamePad[x][y] = 'O';
                }
                system("cls");
                cm->display();
                system("pause");
            }
            if(length % 4 == 0){
                cout << "player2" << " win" << endl;
            }
            else{
                cout << "player1" << " win" << endl;
            }
            system("pause");

        }
        else if(menu == 3){
            string name;
            cout << "input name:" << endl;
            cin >> name;
            system("cls");
            db->show(name);
            system("pause");
        }
        else if(menu == 4){
            string name;
            cout << "input name:" << endl;
            cin >> name;  
            system("cls");
            vector<string> opp = db->findWR(name);
            cout << "The list opponent have the same level: " << endl;
            for(int i = 0; i < opp.size(); i++){
                db->show(opp[i]);
            }
            system("pause");
        }
        else if(menu == 5){
            break;
        }
        else{}
    }
    return 0;
}