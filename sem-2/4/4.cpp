#include<iostream>
using namespace std;
int main() {
	srand(time(NULL));
	int arr[100];
	int n, tmp;
	int suma = 0;
	int range_min = 0;
	int range_max = 9;
	int min = 9999;
	cout << "Enter the number of elements in the array (less than 100)" << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % (range_max - range_min + 1) + range_min;
		suma = suma + arr[i];
		if (arr[i] < min) {
			min = arr[i];
		}
		cout << arr[i] << " ";
	}
	cout << endl << "min value = " << min << endl;
	for (int i = 0; i < n; i++) {
		if (arr[i] == min) {
			for (int j = i; j < n - 1; j++) {
				arr[j] = arr[j + 1];
			}
			i--;
			n--;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		arr[n - i + 2] = arr[n - i - 1];
	}
	arr[0] = suma / n;
	arr[1] = suma / n;
	arr[2] = suma / n;
	n += 3;
	cout << "average value = " << (arr[0]) << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
