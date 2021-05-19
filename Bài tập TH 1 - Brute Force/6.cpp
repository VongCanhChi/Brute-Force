#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
using namespace std;

struct ITEM {
	int w;
	int cost;
};
int computeMaxCost(vector <ITEM> lItem, vector<int>& lItemSelected, int W);

int main()
{
	ifstream fi;
	fi.open("input_6.txt", ios::in);
	int W;
	fi >> W;
	int n;
	fi >> n;
	vector <ITEM> lItem;
	ITEM temp;
	for (int i = 0; i < n; i++)
	{
		fi >> temp.w;
		fi >> temp.cost;
		lItem.push_back(temp);
	}
	vector<int> lItemSelected;
	int maxCost = computeMaxCost(lItem, lItemSelected, W);

	ofstream fo;
	fo.open("output_6.txt", ios::trunc);
	for (int i = 0; i < lItemSelected.size(); i++)
	{
		fo << lItemSelected[i] << " ";
	}
	fo << endl << maxCost;

	for (int i = 0; i < lItemSelected.size(); i++)
	{
		cout << lItemSelected[i] << " ";
	}
	cout << endl << maxCost;

	return 0;
}

int computeMaxCost(vector <ITEM> lItem, vector<int> &lItemSelected, int W) {
	int n = lItem.size();
	int maxCost = 0;
	for (int k = 1; k < pow(2, n); k++) {
		int t = k;
		int subWei = 0, subCost = 0;
		for (int j = 0; j < n; j++) {
			if (t & 1 == 1) {
				subWei += lItem[j].w;
				subCost += lItem[j].cost;
			}
			t = t >> 1;
		}
		if (subWei <= W && subCost > maxCost) {
			maxCost = subCost;
			t = k;
			lItemSelected.clear();
			for (int j = 0; j < n; j++) {
				if (t & 1 == 1) {
					lItemSelected.push_back(j);
				}
				t = t >> 1;
			}
		}
	}
	return maxCost;
}