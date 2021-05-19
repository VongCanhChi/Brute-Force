#include <iostream>
#include <fstream>

using namespace std;

constexpr auto MAX = 100;;


int main()
{
	ifstream fi;
	fi.open("input_3.txt", ios::in);

	int* arr = new int[MAX]; // Cho rằng số loại mệnh giá tiền xu không quá 100.
	int k = 0;
	while (!fi.eof()) {
		fi >> arr[k];
		k++;
	}
	int n; 
	n = arr[k - 1]; // Đọc vào số tiền cần đổi.
	k--;

	// Giải thuật
	void  find(int t, int* arr, int k, int n, int* coin, int& sum, int &minnumcoin, int* lmcoin);
	int* coin = new int[k];
	int sum = 0;
	int* lmcoin = new int[k];
	find(0, arr, k, n, coin, sum, n, lmcoin);

	ofstream fo;
	fo.open("output_3.txt", ios::trunc);
	for (int i = 0; i < k; i++)
	{
		fo << arr[i] << ": " << lmcoin[i] << endl;
	}

	for (int i = 0; i < k; i++)
	{
		cout << arr[i] << ": " << lmcoin[i] << endl;
	}

	delete arr, coin, lmcoin;
	return 0;
}

void find(int t, int* arr, int k, int n, int* coin, int& sum, int &minnumcoin, int *lmcoin)
{
	if (t == k - 1) {
		for (int j = 0; j <= n / arr[t]; j++)
		{
			int tempSum = sum;
			tempSum += arr[t] * j;
			coin[t] = j;
			if (tempSum == n) {
				int numcoin = 0;
				for (int i = 0; i < k; i++)
				{
					numcoin += coin[i];
				}
				if (numcoin < minnumcoin) {
					minnumcoin = numcoin;
					for (int i = 0; i < k; i++)
					{
						lmcoin[i] = coin[i];
					}
				}
				break;
			}
			if (tempSum > n) break;
		}
	}
	else {
		for (int i = 0; i <= n / arr[t]; i++)
		{
			int t_sum = sum + arr[t] * i;
			coin[t] = i;
			find(t + 1, arr, k, n, coin, t_sum, minnumcoin, lmcoin);
		}
	}
}