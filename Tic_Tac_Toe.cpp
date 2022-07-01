#include<iostream>
using namespace std;
bool win_check(char array[][3], int row, char letter)
{
	for (int i = 0; i < 3; i++)
	{
		if (array[i][0] == letter && array[i][1] == letter && array[i][2] == letter)
		{
			return true;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (array[0][i] == letter && array[1][i] == letter && array[2][i] == letter)
		{
			return true;
		}
	}
	if (array[0][0] == letter && array[1][1] == letter && array[2][2] == letter)
	{
		return true;
	}
	if (array[0][2] == letter && array[1][1] == letter && array[2][0] == letter)
	{
		return true;
	}
	return false;

}
void Print_Grid(char array[][3], int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << array[i][j] << " | ";
		}
		cout << endl;
		cout << "---------";
		cout << endl;
	}
}
int main()
{
	bool check1 = false;
	bool check2 = false;
	int count = 1;
	bool blank = false;
	bool stop = false;
	int row, col;
	char game[3][3] = { {'*','*','*'},{'*','*','*'},{'*','*','*'} };
	Print_Grid(game, 3);
	while (count<=9)
	{
		if (count % 2 != 0)
		{
			cout << "Player 1 (X)" << endl;
			while (true)
			{
				cout << "Enter the row where you want to enter(1-3) ";
				cin >> row;
				cout << "Enter the column where you want to enter(1-3) ";
				cin >> col;

				if (((row - 1) >= 0 && (row - 1) <= 2) && ((col - 1) >= 0 && (col - 1) <= 2) && game[row - 1][col - 1] == '*')
				{
					game[row - 1][col - 1] = { 'X' };
					break;
				}
				else
					cout << "Choose the right and empty location " << endl;
			}
			check1 = win_check(game, 3, 'X');
			Print_Grid(game, 3);
			if (check1)
			{
				cout << "PLAYER1(X) YOU WON !!!" << endl;
				break;
			}
		}
		else
		{
			cout << "Player 2 (O)" << endl;
			while (true)
			{
				cout << "Enter the row where you want to enter(1-3) ";
				cin >> row;
				cout << "Enter the column where you want to enter(1-3) ";
				cin >> col;
				if (((row - 1) >= 0 && (row - 1) <= 2) && ((col - 1) >= 0 && (col - 1) <= 2) && game[row - 1][col - 1] == '*')
				{
					game[row - 1][col - 1] = { 'O' };
					break;
				}
				else
					cout << "Choose the right and empty location " << endl;
			}
			check2 = win_check(game, 3, 'O');
			Print_Grid(game, 3);
			if (check2)
			{
				cout << "PLAYER2(Y) YOU WON !!!" << endl;
				break;
			}
		}
		count++;
		
	}
	if (count==10 && !check1 && !check2)
	{
		cout << "Game tied ";
	}
	system("pause");
	return 0;
}