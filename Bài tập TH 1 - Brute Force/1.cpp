#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fi;
	fi.open("input_1.txt", ios::in);
	int n;
	fi >> n;
	float* arr = new float[n];
	for (int i = 0; i < n; i++)
	{
		fi >> arr[i];
	}
	
	// Shaker sort
	bool flag = true;
	int m = 0;
	while (flag) {
		flag = false;
		m++;
		for (int j = n - 1; j >= m; j--)
		{
			if (arr[j - 1] > arr[j]) {
				float temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
				flag = true;
			}
		}
	}

	ofstream fo;
	fo.open("output_1.txt", ios::trunc);
	for (int i = 0; i < n; i++)
	{
		fo << arr[i] << " ";
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	delete arr;
	return 0;
}