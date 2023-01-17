
#include "CaroMatch.h"


void CaroMatch::draw()
{
	for (int i = 0; i<GAMEPADHIGHT; i++)
	{
		for (int j = 0; j < GAMEPADWEIGHT; j++)
		{
			gamePad[i][j] = ' ';
		}
	}
}

void CaroMatch::display()
{
	cout << " ";
	for (int k = 0; k< GAMEPADWEIGHT; k++)
	{
		cout << "   " << k;
	}
	cout << endl;
	for (int i = 0; i < GAMEPADHIGHT; i++)
	{
		cout << i << "| ";
		for (int j = 0; j < GAMEPADWEIGHT; j++)
		{
			cout << gamePad[i][j] << " | ";
		}
		cout << endl << endl;
	}
}

void CaroMatch::addPlayerAToVector()
{
	int x, y;
	do
	{
		cout <<"player1"<< " input:";
		cin >> x >> y;
		cin.ignore();
	} while (((0 > x) || (GAMEPADHIGHT - 1 < x)) || ((0 > y) || (GAMEPADWEIGHT - 1 < y)));
	
	for (int i = 0; i < Data.size(); i++)
	{
		if (Data[i]->x == x && Data[i]->y == y)
		{
			cout << "O khong hop le!" << endl;
			return;
		}
	}
	Block *b = new Block();
	b->x = x;
	b->y = y;
	Data.push_back(b);
	for (int i = 0; i<GAMEPADHIGHT; i++)
	{
		for (int j = 0; j < GAMEPADWEIGHT; j++)
		{
			if (b->x == i && b->y == j)
			{
				gamePad[i][j] = 'X';
			}
		}
	}
}

void CaroMatch::addPlayerBToVector()
{
	int x, y;
	do
	{
		cout << "player2" << " input:";
		cin >> x >> y;
		cin.ignore();
	} while (((0 > x) || (GAMEPADHIGHT - 1 < x)) || ((0 > y) || (GAMEPADWEIGHT - 1 < y)));
	for (int i = 0; i< Data.size(); i++)
	{
		if (Data[i]->x == x && Data[i]->y == y)
		{
			cout << "O khong hop le!" << endl;
			return;
		}
	}
	Block *b = new Block();
	b->x = x;
	b->y = y;
	Data.push_back(b);
	for (int i = 0; i<GAMEPADHIGHT; i++)
	{
		for (int j = 0; j < GAMEPADWEIGHT; j++)
		{
			if (b->x == i && b->y == j)
			{
				gamePad[i][j] = 'O';
			}
		}
	}
}

void CaroMatch::convertData(){
	for(int i = 0; i < Data.size(); i++){
		string str = to_string(Data[i]->x) + to_string(Data[i]->y);
		sData.push_back(str);
	}
}
void CaroMatch::addReplay(string player1, string player2){
	char out[255] = "";
	int count = GetPrivateProfileSectionNames(out, 255, fileReplay) / 2;
	WritePrivateProfileString(to_string(count).c_str(), "player1", player1.c_str(), fileReplay);
	WritePrivateProfileString(to_string(count).c_str(), "player2", player2.c_str(), fileReplay);

	convertData();
	string val ="";
	for(int i = 0; i < sData.size(); i++){
		val += sData[i];
	}
	WritePrivateProfileString(to_string(count).c_str(), "data", val.c_str(), fileReplay);
}
void CaroMatch::getReplay(int id){

}

void CaroMatch::playerInput(vector<Block*> Data)
{
	if (Data.size() == 0)
	{
		addPlayerAToVector();
	}
	else if ((Data.size() - 1) % 2 == 0) {
		addPlayerBToVector();
	}
	else if ((Data.size() - 1) % 2 != 0) {
		addPlayerAToVector();
	}
	system("cls");
}

bool CaroMatch::checkWinNgang()
{
	int dong = Data[Data.size() - 1]->x;
	int cot = Data[Data.size() - 1]->y;
	char kt = gamePad[dong][cot];
	int dem = 1;
	int j = cot;
	while (j > 0)
	{
		j--;
		if (gamePad[dong][j] == kt)
		{
			dem++;
			if (dem == GAMEWONCONDITION) return true;
		}
		else break;
	}
	j = cot;
	while (j < (GAMEPADHIGHT-1))
	{
		j++;
		if (gamePad[dong][j] == kt)
		{
			dem++;
			if (dem == GAMEWONCONDITION) return true;
		}
		else break;
	}
	return false;
}

bool CaroMatch::checkWindoc()
{
	int dong = Data[Data.size() - 1]->x;
	int cot = Data[Data.size() - 1]->y;
	char kt = gamePad[dong][cot];
	int dem = 1;
	int i = dong;
	while (i > 0)
	{
		i--;
		if (gamePad[i][cot] == kt)
		{
			dem++;
			if (dem == GAMEWONCONDITION) return true;
		}
		else break;
	}
	i = dong;
	while (i < (GAMEPADWEIGHT-1))
	{
		i++;
		if (gamePad[i][cot] == kt)
		{
			dem++;
			if (dem == GAMEWONCONDITION) return true;
		}
		else break;
	}
	return false;
}
bool CaroMatch::checkWinCheo1()
{
	int dong = Data[Data.size() - 1]->x;
	int cot = Data[Data.size() - 1]->y;
	char kt = gamePad[dong][cot];
	int dem = 1;
	int i = dong;
	int j = cot;
	while (j > 0 && i > 0)
	{
		i--;
		j--;
		if (gamePad[i][j] == kt)
		{
			dem++;
			if (dem == GAMEWONCONDITION) return true;
		}
		else break;
	}
	j = cot;
	i = dong;
	while ((i < (GAMEPADHIGHT-1)) && (j < (GAMEPADWEIGHT-1)))
	{
		i++;
		j++;
		if (gamePad[i][j] == kt)
		{
			dem++;
			if (dem == GAMEWONCONDITION) return true;
		}
		else break;
	}
	return false;
}
bool CaroMatch::checkWinCheo2()
{
	int dong = Data[Data.size() - 1]->x;
	int cot = Data[Data.size() - 1]->y;
	char kt = gamePad[dong][cot];
	int dem = 1;
	int j = cot;
	int i = dong;

	while ((i > 0) && (j < (GAMEPADWEIGHT - 1)))
	{
		i--;
		j++;
		if (gamePad[i][j] == kt)
		{
			dem++;
			if (dem == GAMEWONCONDITION) return true;
		}
		else break;
	}
	j = cot;
	i = dong;
	while ((i < (GAMEPADHIGHT - 1)) && ( j > 0))
	{
		i++;
		j--;
		if (gamePad[i][j] == kt)
		{
			dem++;
			if (dem == GAMEWONCONDITION) return true;
		}
		else break;
	}

	return false;
}
bool CaroMatch::checkWin()
{
	if (checkWindoc())
	{
		return true;
	}
	else if (checkWinNgang())
	{
		return true;
	}
	else if (checkWinCheo1())
	{
		return true;
	}
	else if (checkWinCheo2())
	{
		return true;
	}
	return false;
}

bool CaroMatch::checkDraw()
{
	if(Data.size() == (GAMEPADHIGHT*GAMEPADWEIGHT)) return true;
	return false;
}

CaroMatch::CaroMatch()
{
}

CaroMatch::~CaroMatch()
{
}
