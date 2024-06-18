#include <string>
#include <iostream>
#include <fstream>
using namespace std;
int main() {
	int n1, n2;
	cin >> n1 >> n2;
	ifstream ReadText("F1.txt");
	fstream PrintText("F2.txt");
	int FirstCouter = 0;
	char soglasbukvi[]{ 'B','C','D','F','G','H','J','K','L','M',
		'N','P','Q','R','S','T','V','W','X','Z',
		'b','c','d','f','g','h','j','k','l','m',
		'n','p','q','r','s','t','v','w','x','z' };
	string buffer;
	int a = 0;
	int b = 0;
	int max = -1;
	int maxind = 0;
	while (getline(ReadText, buffer)) {
		if ((FirstCouter >= n1) && (FirstCouter <= n2) && (buffer[0] == 'A')) {
			PrintText << buffer << endl;
		}
	}
	bool flag = true;
	int SecondCouter = 0;
	while (getline(PrintText, buffer)) {
		a = buffer.size();
		flag = true;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < 40; j++) {
				if (buffer[i] == soglasbukvi[j]) {
					b++;
				}
			}
		}
		if (b > max) {
			max = b;
			maxind = SecondCouter;
		}
		SecondCouter++;
		b = 0;
	}
	maxind++;
	cout << maxind;
	ReadText.close();
	PrintText.close();
	return 0;
}