#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

constexpr auto MIN = 10000;
void hoanVi(int& a, int& b);
void timDuongDi(int privot, vector<int> dinh, float** maTranKe, int n, vector<int> &kq, float& dmin, int k);
int main()
{
	ifstream fi;
	fi.open("input_5.txt", ios::in);
	int n;
	fi >> n;
	float** maTranKe = new float* [n];
	for (int i = 0; i < n; i++)
		maTranKe[i] = new float[n];
	for (int i = 0; i < n; i++) {// Khởi tạo trọng số cho ma trận ban đầu bằng 0;
		for (int j = 0; j < n; j++) {
			maTranKe[i][j] = 0;
		}
	}
	int a, b;
	float d;
	while (true)
	{
		fi >> a;
		if (a == -1)
			break;
		fi >> b;
		fi >> d;
		maTranKe[a-1][b-1] = d;
		maTranKe[b-1][a-1] = d;
	}

	// Giải thuật
	vector<int> dinh;
	vector<int> kq;
	float dmin = MIN;
	for (int k = 1; k <= n; k++) {
		for (int j = 1; j <= n; j++) {
			dinh.push_back(j);
		}
		dinh.erase(dinh.begin() + k - 1);
		timDuongDi(0, dinh, maTranKe, n, kq, dmin, k);
	}
	if (dmin == MIN)return 0;

	ofstream fo;
	fo.open("output_5.txt", ios::trunc);
	for (int i = 0; i < kq.size(); i++)
	{
		fo << kq[i] << " ";
	}
	fo << endl << dmin;

	for (int i = 0; i < kq.size(); i++)
	{
		cout << kq[i] << " ";
	}
	cout << endl << dmin;

	delete []maTranKe;
	return 0;
}

void timDuongDi(int privot, vector<int> dinh, float** maTranKe, int n, vector<int> &kq, float &dmin, int k)
{
	if (privot == n - 2) {
		vector<int> dinhTemp;
		for (int i = 0; i < dinh.size(); i++) {
			dinhTemp.push_back(dinh[i]);
		}
		dinhTemp.insert(dinhTemp.begin(), k);
		dinhTemp.push_back(k);
		int i;
		float s = 0;
		for (i = 0; i < dinhTemp.size() - 1; i++) {
			if (maTranKe[dinhTemp[i]-1][dinhTemp[i + 1]-1] > 0) {
				s += maTranKe[dinhTemp[i]-1][dinhTemp[i + 1]-1];
			}
			else break;
		}
		if (i == n && s < dmin) {
			dmin = s;
			kq.clear();
			for (int j = 0; j < dinhTemp.size(); j++) {
				kq.push_back(dinhTemp[j]);
			}
		}
	}
	else {
		for (int i = privot; i < n - 1; i++) {
			hoanVi(dinh[privot], dinh[i]);
			timDuongDi(privot + 1, dinh, maTranKe, n, kq, dmin, k);
			hoanVi(dinh[privot], dinh[i]);
		}
	}
}

void hoanVi(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}