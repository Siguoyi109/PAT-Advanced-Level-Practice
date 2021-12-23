//一道非常经典的DFS题目；遍历整个图；找到所有的连通块
//1.该题是无向图的DFS遍历，计算出连通分量
//2.使用二维数组构建邻接矩阵，由于名字给的是字母，所以需要构造两个map，一个为map<string, int>, 一个为map<int, string>, 这样数字和名字可以一一对应
//3.每次访问完一条边后，将该边weight = 0，为的是去除无限递归
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
int n, k, numPerson = 1;   //n为通话数，k下界，numPerson人数（这个顺便将人名建成了一个图）
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
	for (int i = 0; i < numPerson; i++) {      //这个循环才是将连通块中所有元素遍历一遍
		if (G[nowVisit][i] > 0) {
			totalValue += G[nowVisit][i];
			G[nowVisit][i] = G[i][nowVisit] = 0;
			if (vis[i] == false) 
				DFS(i, head, numMember, totalValue);
		}
	}
}
void DFSTravel() {
	for (int i = 0; i < numPerson; i++) {   //这个for是为了找到所有的连通子块
		if (vis[i] == false) {
			int head = i, numMember = 0, totalValue = 0;//head头目，numMember成员数，totalValue总价值
			DFS(i, head, numMember, totalValue);
			if (numMember > 2 && totalValue > k) 
				ans[int2String[head]] = numMember;
		}
	}
}

int main() {
	int w;//临时权重
	string str1, str2;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {   //构建一个图
		cin >> str1 >> str2 >> w;
		int id1 = change(str1);    //这个函数其实就是给每个不重复的str赋一个下标
		int id2 = change(str2);
		weight[id1] += w;
		weight[id2] += w;
		G[id1][id2] += w;
		G[id2][id1] += w;
	}
	DFSTravel();
	cout << ans.size() << endl;
	map<string, int>::iterator i; //迭代器
	for (i = ans.begin(); i != ans.end(); i++) 
		cout << i->first << " " << i->second << endl;
	return 0;
}
