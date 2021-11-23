#include<iostream>
using namespace std;
#include<queue>
queue<int>Q;
int N, M;
int tree[100][100];

bool check(int node) {     //check函数检查是否为叶子结点，并负责下一层的扩散工作
	bool f = false;
	for (int i = 0; i < 100; i++) {
		if (tree[node][i]) {
			Q.push(i);    //扩散到下一层
			f = true;
		}
	}
	return f;
}

void print() {
	int start = 1;
	Q.push(start);
	//用队列实现层序遍历 
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
	while (c--)          //构建树
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