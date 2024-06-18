#include <iostream>
using namespace std;
int desk[8][8];
int resultN = 1;
void showBoard()
{
	for (int a = 0; a < 8; a++)
	{
		for (int b = 0; b < 8; b++)
		{
			cout << ((board[a][b]) ? "Q " : ". ");
		}
		cout << endl;
	}
}
bool checkQueen(int a, int b)
{
	for (int i = 0; i < a; i++)
	{
		if (board[i][b] == 1)
		{
			return false;
		}
	}
	for (int i = 1; i <= a && b - i >= 0; i++)
	{
		if (board[a - i][b - i] == 1)
		{
			return false;
		}
	}
	for (int i = 1; i <= a && b + i < SIZE; i++)
	{
		if (board[a - i][b + i] == 1)
		{
			return false;
		}
	}
	return true;
}
void setQueen(int a)
{
	if (a == 8)
	{
		showBoard();
		cout << resultN++ << endl << endl;
		return;
	}
	for (int i = 0; i < 8; i++)
	{
		if (checkQueen(a, i))
		{
			board[a][i] = 1;
			setQueen(a + 1);
			board[a][i] = 0;
		}
	}
	return;
}
int main()
{
	setlocale(LC_ALL, "ru_RU");
	setQueen(0);
	return 0;
}