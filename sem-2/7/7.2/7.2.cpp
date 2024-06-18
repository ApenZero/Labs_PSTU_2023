#include <iostream>
using namespace std;
void ConversionToTernarySystem(int k, ...) {
	int* p = &k;
	int InvertedArray[100];
	int couter = 0;
	int d = 0;
	for (; k != 0; k--) {
		int s = *(p += 2);
		while (s > 0) {
			d = s % 3;
			s = s / 3;
			InvertedArray[couter] = d;
			couter += 1;
		}
		for (int i = couter - 1; i >= 0; i--) {
			cout << InvertedArray[i];
		}
		cout << endl;
		couter = 0;
	}
}
int main() {
	ConversionToTernarySystem(3, 11, 22, 33);
	cout << endl;
	ConversionToTernarySystem(4, 11, 22, 33, 44);
	cout << endl;
	ConversionToTernarySystem(7, 11, 22, 33, 44, 55, 66, 77);
	return 0;
}
/*
102
211
1020

102
211
1020
1122

102
211
1020
1122
2001
2110
2212
*/