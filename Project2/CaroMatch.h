#pragma once
#include <Windows.h>
#include <cstdlib>
#include <iostream>
#include <vector>

#define GAMEPADHIGHT 10
#define GAMEPADWEIGHT 10
#define GAMEWONCONDITION 4
using namespace std;
class CaroMatch{
public:
	char player1[15];
	char player2[15];

	struct Block{
		int x;
		int y;
	};
	char gamePad[GAMEPADWEIGHT][GAMEPADWEIGHT];
	vector <Block*> Data;

public:

	void draw();
	void display();
	void addPlayerAToVector();
	void addPlayerBToVector();
	void playerInput(vector <Block*> Data);
	bool checkWinNgang();
	bool checkWindoc();
	bool checkWinCheo1();
	bool checkWinCheo2();
	bool checkWin();
	bool checkDraw();
	CaroMatch();
	~CaroMatch();
};

