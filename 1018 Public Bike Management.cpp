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
vector<int> pre[MAXV], tmpPath, path;//前驱，临时路径，最优路径

void Dijkstra(int s);
void DFS(int v);

int main18()
{
	cin >> Cmax >> N >> Sp >> M;
	fill(G[0], G[0] + MAXV * MAXV, INF);
	for (int i = 1; i <= N; i++) {
		cin >> weight[i];
		weight[i] -= Cmax / 2;//减去最大值的一半即可根据正负判断是否需要补充或带走
	}
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		cin >> G[u][v];//必须和上一步分开写
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
	for (int i = 0; i <= N; i++) {//循环N+1次 
		int u = -1, MIN = INF;//u使d[u]最小，MIN存放该最小的d[u]
		for (int j = 0; j <= N; j++) {//找到未访问的顶点中d[]最小的
			if (vis[j] == 0 && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1) return;//说明剩下的顶点和s不连通
		vis[u] = 1;
		for (int v = 0; v <= N; v++) {
			if (vis[v] == 0 && G[u][v] != INF) {//对u的每个未访问的邻接点
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
	if (v == 0) {//递归边界，叶子节点
		tmpPath.push_back(v);
		int need = 0, remain = 0;
		for (int i = tmpPath.size() - 1; i >= 0; i--) {//必须倒着枚举//这样才能得到在起点的数量
			int id = tmpPath[i];
			if (weight[id] > 0) remain += weight[id];//点权大于0说明需要带走
			else {//否则需要补给
				if (remain > abs(weight[id])) remain -= abs(weight[id]);//当前持有量足够补给
				else {//否则需要从PBMC携带
					need += abs(weight[id]) - remain;
					remain = 0;
				}
			}
		}
		if (need < minNeed) {//需要从PBMC携带的数量更少则更新
			minNeed = need;
			minRemain = remain;
			path = tmpPath;
		}
		else if (need == minNeed && remain < minRemain) {//携带数目相同但带回数目变少也更新
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
