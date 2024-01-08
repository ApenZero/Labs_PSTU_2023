#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n, tem, max, min;
	int* ptr = &tem;
	cout << "Lenght of subsequence" << endl;
	cin >> n;
	cout << "First number" << endl;
	cin >> *ptr;
	max = *ptr;
	min = *ptr;
	for (int i = 2; i <= n; i++) {
		cin >> *ptr;
		if (*ptr > max) {
			max = *ptr;
		}
		else if (*ptr < min) {
			min = *ptr;
		}
	}
	cout << "Max" << max << endl;
	cout << "Min" << min << endl;
	return 0;
}