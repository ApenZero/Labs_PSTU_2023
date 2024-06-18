#include <iostream>
using namespace std;
void PrintMassiv(int* Massiv[], int columns, int lines) {
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << Massiv[i][j] << "\t";
		}
		cout << endl;
	}
}
int DeleteRows(int* Massiv[], int columns, int lines, int DeleteNumber) {
	int brokenrows = 0;
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < columns; j++) {
			if (Massiv[i][j] == DeleteNumber) {
				for (int l = 0; l < lines; l++) {
					for (int k = j; k < columns; k++) {
						Massiv[l][k] = Massiv[l][k + 1];
					}
				}
				brokenrows++;
			}
		}
	}
	return brokenrows;
}
int main() {
	int brokenrows;
	unsigned int columns;
	cin >> columns;
	unsigned int lines;
	cin >> lines;
	int DeleteNumber;
	cin >> DeleteNumber;
	int** Massiv{ new int* [lines] {} };
	for (int i = 0; i < lines; i++) {
		Massiv[i] = new int[columns] {};
	}
	for (int i = 0; i < lines; i++)
	{
		cout << "Enter data for " << (i + 1) << " row" << endl;
		for (int j = 0; j < columns; j++)
		{
			cout << (j + 1) << " line: ";
			cin >> Massiv[i][j];
		}
	}
	PrintMassiv(Massiv, columns, lines);
	brokenrows = DeleteRows(Massiv, columns, lines, DeleteNumber);
	columns = columns - brokenrows;
	PrintMassiv(Massiv, columns, lines);
	for (int i = 0; i < lines; i++)
	{
		delete[] Massiv[i];
	}
	delete[] Massiv;
	return 0;
}