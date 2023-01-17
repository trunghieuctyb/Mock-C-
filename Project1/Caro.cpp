#include "CaroMatch.cpp"
using namespace std;

int main(){
    CaroMatch * cm = new CaroMatch();
    cm->draw();
    while(1){
	    system("cls");
        cm->display();
        cm->playerInput(cm->Data);
        if (cm->checkWin()){
            int x = cm->Data.size() - 1;
            if (x % 2 == 0){
                cm->display();
                cout << "player1" << " win " << endl;	
                break;
            }
            else{
                cm->display();
                cout << "player2" << " win" << endl;
                break;
            }
        }
        if (cm->checkDraw()){
            cm->display();
            cout << "player1" << " Drawn " << "player2" << endl;
            break;
        }
					
    }
    return 0;
}