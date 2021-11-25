#include<iostream>
using namespace std;
#include<map>
#include<iomanip>   //错误点在于，输出的那个个数，没有减去0这项；
class MyCompare {
public:
	bool operator()(int v1, int v2)const {
		return v1 > v2;
	}
};
map<int, double, MyCompare>s1, s2, s3;
int main9()
{
	int x, y, zhi1, zhi2;
	double xi1, xi2;
	cin >> x;
	for (int i = 0; i < x; i++)
	{
		cin >> zhi1 >> xi1;
		s1[zhi1] = xi1;
	}
	cin >> y;
	for (int i = 0; i < y; i++)
	{
		cin >> zhi2 >> xi2;
		s2[zhi2] = xi2;
	}
	for (map<int, double, MyCompare>::iterator it1 = s1.begin(); it1 != s1.end(); it1++)
		for (map<int, double, MyCompare>::iterator it2 = s2.begin(); it2 != s2.end(); it2++)
			s3[it1->first + it2->first] += it1->second * it2->second;
	for (map<int, double, MyCompare>::iterator it3 = s3.begin(); it3 != s3.end(); it3++)
		if (it3->second == 0)  s3.erase(it3->first);
	cout << s3.size();
	for (map<int, double, MyCompare>::iterator it3 = s3.begin(); it3 != s3.end(); it3++)
		cout << " " << it3->first << " " << setiosflags(ios::fixed) << setprecision(1) << it3->second;
	system("pause");
	return 0;
}