#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void drawRow(char type1, char type2, char type3);

int main()
{
	char tileTypes[3][3], temp;
	bool gamecomplete = false, yourturn = true, playerwon;
	int xtarget, ytarget;
	srand(time(NULL));
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tileTypes[i][j] = '_';
		}
	}
	
	while (!gamecomplete)
	{
		system("cls");

		//Draw the game
		cout << endl << endl;
		for (int i = 0; i < 3; i++)
		{
			drawRow(tileTypes[i][0], tileTypes[i][1], tileTypes[i][2]);
		}
		cout << endl << endl;

		//Win checking
		if ((tileTypes[0][0] == 'x' && tileTypes[0][1] == 'x' && tileTypes[0][2] == 'x') ||
			(tileTypes[1][0] == 'x' && tileTypes[1][1] == 'x' && tileTypes[1][2] == 'x') ||
			(tileTypes[2][0] == 'x' && tileTypes[2][1] == 'x' && tileTypes[2][2] == 'x') ||

			(tileTypes[0][0] == 'x' && tileTypes[1][0] == 'x' && tileTypes[2][0] == 'x') ||
			(tileTypes[0][1] == 'x' && tileTypes[1][1] == 'x' && tileTypes[2][1] == 'x') ||
			(tileTypes[0][2] == 'x' && tileTypes[1][2] == 'x' && tileTypes[2][2] == 'x') ||

			(tileTypes[0][0] == 'x' && tileTypes[1][1] == 'x' && tileTypes[2][2] == 'x') ||
			(tileTypes[0][2] == 'x' && tileTypes[1][1] == 'x' && tileTypes[2][0] == 'x'))
		{
			gamecomplete = true;
			playerwon = true;
			break;
		}
		if ((tileTypes[0][0] == 'o' && tileTypes[0][1] == 'o' && tileTypes[0][2] == 'o') ||
			(tileTypes[1][0] == 'o' && tileTypes[1][1] == 'o' && tileTypes[1][2] == 'o') ||
			(tileTypes[2][0] == 'o' && tileTypes[2][1] == 'o' && tileTypes[2][2] == 'o') ||

			(tileTypes[0][0] == 'o' && tileTypes[1][0] == 'o' && tileTypes[2][0] == 'o') ||
			(tileTypes[0][1] == 'o' && tileTypes[1][1] == 'o' && tileTypes[2][1] == 'o') ||
			(tileTypes[0][2] == 'o' && tileTypes[1][2] == 'o' && tileTypes[2][2] == 'o') ||

			(tileTypes[0][0] == 'o' && tileTypes[1][1] == 'o' && tileTypes[2][2] == 'o') ||
			(tileTypes[0][2] == 'o' && tileTypes[1][1] == 'o' && tileTypes[2][0] == 'o'))
		{
			gamecomplete = true;
			playerwon = false;
			break;
		}
		//Player controls
		if (yourturn)
		{
			cout << "Enter the column to target: ";
			xtarget = _getch() - '0';
			cout << xtarget << endl;

			cout << "Enter the row to target:    ";
			ytarget = _getch() - '0';
			cout << ytarget << endl;

			xtarget--;
			ytarget--;

			while (tileTypes[ytarget][xtarget] != '_')
			{
				cout << "That tile is already occupied." << endl << "Enter the column to target: ";
				xtarget = _getch() - '0';
				cout << xtarget << endl;

				cout << "Enter the row to target:    ";
				ytarget = _getch() - '0';
				cout << ytarget << endl;

				xtarget--;
				ytarget--;
			}

			tileTypes[ytarget][xtarget] = 'x';
			yourturn = false;
		}
		//AI controls
		else
		{
			cout << "Opponent is choosing tile..." << endl;

			do {
				xtarget = rand() % 3;
				ytarget = rand() % 3;
			} while (tileTypes[ytarget][xtarget] != '_');

			cout << "Opponent targets " << xtarget + 1 << ", " << ytarget + 1 << endl << "(any key to continue)";

			tileTypes[ytarget][xtarget] = 'o';
			temp = _getch();

			yourturn = true;
		}
	}
	system("pause");
    return 0;
}

	

void drawRow(char type1, char type2, char type3)
{
	string tiles[3][3];

	switch (type1)
	{
	case('x'):
		tiles[0][0] = "X   X";
		tiles[0][1] = "  X  ";
		tiles[0][2] = "X   X";
		break;
	case('o'):
		tiles[0][0] = " OOO ";
		tiles[0][1] = "O   O";
		tiles[0][2] = " OOO ";
		break;
	case('_'):
		tiles[0][0] = "     ";
		tiles[0][1] = "     ";
		tiles[0][2] = "     ";
	}
	switch (type2)
	{
	case('x'):
		tiles[1][0] = "X   X";
		tiles[1][1] = "  X  ";
		tiles[1][2] = "X   X";
		break;
	case('o'):
		tiles[1][0] = " OOO ";
		tiles[1][1] = "O   O";
		tiles[1][2] = " OOO ";
		break;
	case('_'):
		tiles[1][0] = "     ";
		tiles[1][1] = "     ";
		tiles[1][2] = "     ";
	}
	switch (type3)
	{
	case('x'):
		tiles[2][0] = "X   X";
		tiles[2][1] = "  X  ";
		tiles[2][2] = "X   X";
		break;
	case('o'):
		tiles[2][0] = " OOO ";
		tiles[2][1] = "O   O";
		tiles[2][2] = " OOO ";
		break;
	case('_'):
		tiles[2][0] = "     ";
		tiles[2][1] = "     ";
		tiles[2][2] = "     ";
	}

	cout << "     /-----\\ /-----\\ /-----\\" << endl; //Tile Drawing
	cout << "     |" << tiles[0][0] << "| |" << tiles[1][0] << "| |" << tiles[2][0] << "|" << endl;
	cout << "     |" << tiles[0][1] << "| |" << tiles[1][1] << "| |" << tiles[2][1] << "|" << endl;
	cout << "     |" << tiles[0][2] << "| |" << tiles[1][2] << "| |" << tiles[2][2] << "|" << endl;
	cout << "     \\-----/ \\-----/ \\-----/" << endl;
}