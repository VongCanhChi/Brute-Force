#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;
constexpr auto PI = 3.14;

struct POINT {
	int x;
	int y;
};

int main()
{
	ifstream fi;
	fi.open("input_4.txt", ios::in);
	int n;
	fi >> n;

	vector <POINT> S;
	POINT temp;
	for (int i = 0; i < n; i++)
	{
		fi >> temp.x;
		fi >> temp.y;
		S.push_back(temp);
	}

	// Giải thuật
	float computeAngle(POINT from, POINT to);
	POINT findNextExtremePoint(vector <POINT> S, POINT cur, float& curAngle);
	vector <POINT> computeConvexHull(vector <POINT> S);

	vector<POINT> P;
	P = computeConvexHull(S);

	ofstream fo;
	fo.open("output_4.txt", ios::trunc);
	for (int i = 0; i < P.size(); i++)
	{
		fo << "(" << P[i].x << "," << P[i].y << ") ";
	}

	for (int i = 0; i < P.size(); i++)
	{
		cout << "(" << P[i].x << "," << P[i].y << ") ";
	}

	return 0;
}

float computeAngle(POINT from, POINT to)
{
	float angle = atan2 ((to.y - from.y),(to.x - from.x));
	if (angle < 0) {
		angle += 2 * PI;
	}
	return angle;
}

POINT findNextExtremePoint(vector <POINT> S, POINT cur, float& curAngle)
{
	float minAngle = 2 * PI;
	for (int i = 0; i < S.size(); i++) {
		if (S[i].x == cur.x && S[i].y == cur.y) {
			S.erase(S.begin() + i);
			break;
		}
	}
	POINT next;
	float angle;
	for (int i = 0; i < S.size(); i++)
	{
		angle = computeAngle(cur, S[i]);
		if (angle < minAngle && angle >= curAngle) {
			next.x = S[i].x;
			next.y = S[i].y;
			minAngle = angle;
		}
	}
	curAngle = minAngle;
	S.push_back(cur);
	return next;
}

vector <POINT> computeConvexHull(vector <POINT> S)
{
	vector <POINT> convexHull;
	POINT first;
	first.y = 1000;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].y < first.y) {
			first.x = S[i].x;
			first.y = S[i].y;
		}
	}
	convexHull.push_back(first);
	float curAngle = 0;
	POINT cur = first;
	POINT next;
	while (true) {
		next = findNextExtremePoint(S, cur, curAngle);
		if (first.x == next.x && first.y == next.y) break;
		convexHull.push_back(next);
		cur = next;
	}
	return convexHull;
}