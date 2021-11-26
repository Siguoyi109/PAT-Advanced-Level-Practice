#include<iostream>
#include<algorithm>
using namespace std;

struct student {
	int id;
	int score[4];    //�ֱ��¼a��c��m��e�ķ���
}a[2100];
int ranking[10000010][4];     //ѧ�Ŷ�Ӧ�ģ���ĳһ���������Ľ��
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
	for (pos = 0; pos < 4; pos++) {   //4������
		sort(a, a + n, cmp);
		ranking[a[0].id][pos] = 1;    //��һ����Ȼ�ǵ�һ��
		//����5���˵ĵ÷ֱַ��ǣ�92 92 90 85 85 ����Ӧ������Ӧ����1 1 3 4 4
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
