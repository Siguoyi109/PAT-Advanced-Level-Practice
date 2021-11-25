#include<iostream>
using namespace std;
int get_max(int x, int y, int z){
	if (x >= y && x >= z)
		return 1;
	if (y >= x && y >= z)
		return 2;
	if (z >= x && z >= y)
		return 3;
}
int main11()
{
	double w, t, l;
	double ans = 1.0;
	int cond;
	while (cin >> w >> t >> l){
		cond = get_max(w, t, l);
		switch (cond){
		case 1: cout << "W "; ans *= w; break;
		case 2: cout << "T "; ans *= t; break;
		case 3: cout << "L "; ans *= l; break;
		}
	}
	ans *= 0.65;
	ans -= 1;
	ans *= 2;
	printf("%.2f\n", ans);
	return 0;
}