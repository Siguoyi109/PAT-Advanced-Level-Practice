//һ���ǳ������DFS��Ŀ����������ͼ���ҵ����е���ͨ��
//1.����������ͼ��DFS�������������ͨ����
//2.ʹ�ö�ά���鹹���ڽӾ����������ָ�������ĸ��������Ҫ��������map��һ��Ϊmap<string, int>, һ��Ϊmap<int, string>, �������ֺ����ֿ���һһ��Ӧ
//3.ÿ�η�����һ���ߺ󣬽��ñ�weight = 0��Ϊ����ȥ�����޵ݹ�
#include <iostream>
#include <string>
#include <map>
using namespace std;
const int MAXV = 2010;

int G[MAXV][MAXV] = { 0 }, weight[MAXV] = { 0 };
bool vis[MAXV] = { false };
map<string, int> ans;
map<string, int> string2Int;
map<int, string> int2String;
int n, k, numPerson = 1;   //nΪͨ������k�½磬numPerson���������˳�㽫����������һ��ͼ��
int change(string str) {
	if (string2Int.find(str) != string2Int.end()) 
		return string2Int[str];
	else {
		string2Int[str] = numPerson;
		int2String[numPerson] = str;
		return numPerson++;
	}
}
void DFS(int nowVisit, int& head, int& numMember, int& totalValue) {
	numMember++;
	vis[nowVisit] = true;
	if (weight[nowVisit] > weight[head]) 
		head = nowVisit;
	for (int i = 0; i < numPerson; i++) {      //���ѭ�����ǽ���ͨ��������Ԫ�ر���һ��
		if (G[nowVisit][i] > 0) {
			totalValue += G[nowVisit][i];
			G[nowVisit][i] = G[i][nowVisit] = 0;
			if (vis[i] == false) 
				DFS(i, head, numMember, totalValue);
		}
	}
}
void DFSTravel() {
	for (int i = 0; i < numPerson; i++) {   //���for��Ϊ���ҵ����е���ͨ�ӿ�
		if (vis[i] == false) {
			int head = i, numMember = 0, totalValue = 0;//headͷĿ��numMember��Ա����totalValue�ܼ�ֵ
			DFS(i, head, numMember, totalValue);
			if (numMember > 2 && totalValue > k) 
				ans[int2String[head]] = numMember;
		}
	}
}

int main() {
	int w;//��ʱȨ��
	string str1, str2;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {   //����һ��ͼ
		cin >> str1 >> str2 >> w;
		int id1 = change(str1);    //���������ʵ���Ǹ�ÿ�����ظ���str��һ���±�
		int id2 = change(str2);
		weight[id1] += w;
		weight[id2] += w;
		G[id1][id2] += w;
		G[id2][id1] += w;
	}
	DFSTravel();
	cout << ans.size() << endl;
	map<string, int>::iterator i; //������
	for (i = ans.begin(); i != ans.end(); i++) 
		cout << i->first << " " << i->second << endl;
	return 0;
}
