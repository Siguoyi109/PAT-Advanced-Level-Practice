#include<iostream>
#include<string.h>
using namespace std;

int n, m, k;
int count1[1000][1000];
int visited[1000];
void dfs(int index) {
	visited[index] = 1;
	for (int i = 0; i < n; i++) {
		if (count1[index][i] != 0) {
			if (visited[i] == 0) {
				visited[i] = 1;
				dfs(i);
			}
		}
	}
}
int main13()
{
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		count1[from-1][to-1] = 1;
		count1[to-1][from-1] = 1;
	}
	for (int i = 0; i < k; i++) {
		int cnt = 0;
		int index;
		cin >> index;
		index = index - 1;
		memset(visited, 0, sizeof(visited));
		visited[index] = 1;
		for (int j = 0; j < n; j++) {
			if (visited[j] == 0) {
				dfs(j);
				cnt++;
			}
		}
		cout << cnt - 1 << endl;
	}
}
