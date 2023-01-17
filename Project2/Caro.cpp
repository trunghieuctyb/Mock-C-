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
		cout << "2.Check profile : " << endl;
        cout << "3.Find opponent : " << endl;
		cout << "4.Exit" << endl;
		cout << "Select sevice>>";
		cin >> menu;
        if(menu == 1){
            cm->Data.clear();
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
                        system("pause");
                        break;
                    }
                    else{
                        cm->display();
                        cout << player2 << " win" << endl;
                        db->update(player2, "win");
                        db->update(player1, "lose");
                        system("pause");
                        break;
                    }
                }
                if (cm->checkDraw()){
                    cm->display();
                    cout << player1 << " Drawn " << player2 << endl;
                    db->update(player1, "draw");
                    db->update(player1, "draw");
                    system("pause");
                    break;
                }
            }
        }
        else if(menu == 2){
            string name;
            cout << "input name:" << endl;
            cin >> name;
            system("cls");
            db->show(name);
            system("pause");
        }
        else if(menu == 3){
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
        else if(menu == 4){
            break;
        }
        else{}
    }
    return 0;
}