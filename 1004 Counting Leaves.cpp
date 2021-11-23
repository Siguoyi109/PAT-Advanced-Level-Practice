#include<iostream>
using namespace std;
#include<queue>
queue<int>Q;
int N, M;
int tree[100][100];

bool check(int node) {     //check��������Ƿ�ΪҶ�ӽ�㣬��������һ�����ɢ����
	bool f = false;
	for (int i = 0; i < 100; i++) {
		if (tree[node][i]) {
			Q.push(i);    //��ɢ����һ��
			f = true;
		}
	}
	return f;
}

void print() {
	int start = 1;
	Q.push(start);
	//�ö���ʵ�ֲ������ 
	while (!Q.empty()) {
		int cnt = 0;
		for (int i = Q.size(); i > 0; i--) {
			int t = Q.front(); Q.pop();
			if (!check(t))
				cnt++;
		}
		if (!Q.empty())
			cout << cnt << ' ';
		else
			cout << cnt;
	}
}

int main4()
{
	cin >> N >> M;
	int c = M;
	while (c--)          //������
	{
		int root, child, d;
		cin >> root;
		cin >> d;
		while (d--)
		{
			cin >> child;
			tree[root][child]++;
		}
	}
	print();

	system("pause");
	return 0;
}