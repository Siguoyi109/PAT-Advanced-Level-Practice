#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAXV 510
#define INF 1e9
int N, M, Cmax, Sp, numPath = 0, G[MAXV][MAXV], weight[MAXV];
int d[MAXV], minNeed = INF, minRemain = INF, vis[MAXV] = { 0 };
vector<int> pre[MAXV], tmpPath, path;//ǰ������ʱ·��������·��

void Dijkstra(int s);
void DFS(int v);

int main18()
{
	cin >> Cmax >> N >> Sp >> M;
	fill(G[0], G[0] + MAXV * MAXV, INF);
	for (int i = 1; i <= N; i++) {
		cin >> weight[i];
		weight[i] -= Cmax / 2;//��ȥ���ֵ��һ�뼴�ɸ��������ж��Ƿ���Ҫ��������
	}
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		cin >> G[u][v];//�������һ���ֿ�д
		G[v][u] = G[u][v];
	}
	Dijkstra(0);
	DFS(Sp);
	cout << minNeed << " ";
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i];
		if (i > 0) cout << "->";
	}
	cout << " " << minRemain;
	return 0;
}

void Dijkstra(int s) {
	fill(d, d + MAXV, INF);
	d[s] = 0;
	for (int i = 0; i <= N; i++) {//ѭ��N+1�� 
		int u = -1, MIN = INF;//uʹd[u]��С��MIN��Ÿ���С��d[u]
		for (int j = 0; j <= N; j++) {//�ҵ�δ���ʵĶ�����d[]��С��
			if (vis[j] == 0 && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1) return;//˵��ʣ�µĶ����s����ͨ
		vis[u] = 1;
		for (int v = 0; v <= N; v++) {
			if (vis[v] == 0 && G[u][v] != INF) {//��u��ÿ��δ���ʵ��ڽӵ�
				if (d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (d[u] + G[u][v] == d[v]) pre[v].push_back(u);
			}
		}
	}
}

void DFS(int v) {
	if (v == 0) {//�ݹ�߽磬Ҷ�ӽڵ�
		tmpPath.push_back(v);
		int need = 0, remain = 0;
		for (int i = tmpPath.size() - 1; i >= 0; i--) {//���뵹��ö��//�������ܵõ�����������
			int id = tmpPath[i];
			if (weight[id] > 0) remain += weight[id];//��Ȩ����0˵����Ҫ����
			else {//������Ҫ����
				if (remain > abs(weight[id])) remain -= abs(weight[id]);//��ǰ�������㹻����
				else {//������Ҫ��PBMCЯ��
					need += abs(weight[id]) - remain;
					remain = 0;
				}
			}
		}
		if (need < minNeed) {//��Ҫ��PBMCЯ�����������������
			minNeed = need;
			minRemain = remain;
			path = tmpPath;
		}
		else if (need == minNeed && remain < minRemain) {//Я����Ŀ��ͬ��������Ŀ����Ҳ����
			minRemain = remain;
			path = tmpPath;
		}
		tmpPath.pop_back();
		return;
	}
	tmpPath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++)
		DFS(pre[v][i]);
	tmpPath.pop_back();
}
