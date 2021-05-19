#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fi;
	fi.open("input_2.txt", ios::in);
	int n;
	fi >> n;
	float* arr = new float[n];
	for (int i = 0; i < n; i++)
	{
		fi >> arr[i];
	}

	// maxContSubSum
	float maxSum = 0, curSum = 0;
	int l = 0, r = 0;
	int l_t = 0;
	for (int i = 0; i < n; i++)
	{
		curSum += arr[i];
		if (curSum > maxSum) {
			maxSum = curSum;
			r = i;
			l = l_t;
		}
		else {
			if (curSum < 0) {
				l_t = i+1;
				curSum = 0;
			}
		}
	}

	ofstream fo;
	fo.open("output_2.txt", ios::trunc);
	for (int i = l; i <= r; i++)
	{
		fo << arr[i] << " ";
	}
	fo << endl << maxSum;

	for (int i = l; i <= r; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << maxSum;

	delete arr;
	return 0;
}