#include<iostream>
#include<algorithm>
using namespace std;

struct student {
	int id;
	int score[4];    //分别记录a、c、m、e的分数
}a[2100];
int ranking[10000010][4];     //学号对应的，按某一类来排名的结果
int pos;
char s[4][2] = { "a","c","m","e" };
bool cmp(student x, student y){
	return x.score[pos] > y.score[pos];
}
int main12()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i].id >> a[i].score[1] >> a[i].score[2] >> a[i].score[3];
		a[i].score[0] = (a[i].score[1] + a[i].score[2] + a[i].score[3]) / 3;
	}
	for (pos = 0; pos < 4; pos++) {   //4次排序
		sort(a, a + n, cmp);
		ranking[a[0].id][pos] = 1;    //第一个当然是第一了
		//比如5个人的得分分别是：92 92 90 85 85 ，对应的排名应该是1 1 3 4 4
		for (int i = 1; i < n; i++) {
			if (a[i].score[pos] == a[i - 1].score[pos])
				ranking[a[i].id][pos] = ranking[a[i - 1].id][pos];
			else
				ranking[a[i].id][pos] = i + 1;
		}
	}
	int t;
	for (int i = 0; i < m; i++) {
		cin >> t;
		if (ranking[t][0] == 0)
			cout << "N/A" << endl;
		else {
			int k = 0;
			for (int j = 0; j < 4; j++)
				if (ranking[t][j] < ranking[t][k])   k = j;
			cout << ranking[t][k] << " " << s[k] << endl;
		}
	}
	system("pause");
	return 0;
}
