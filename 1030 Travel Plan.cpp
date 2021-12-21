#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

bool visited[500];
int graph[500][500], cost[500][500];                        //graph���ÿ��·����ʱ cost���ÿ��·�Ļ���
int dis[500];
vector<int> path[500];                                      //������нڵ���������·��
vector<int> temPath, finalPath;                             //temPath��ʱ������·�� finalPath����·��
int n, m, s, d;                                             //n������Ŀ m·��Ŀ s��� d�յ�
int minCost = INT_MAX;
void dfs(int end, int co) {
    temPath.push_back(end);
    if (end == s) {                                           //�Ѿ����յ㵽����㣨���Ž���DFS��
        if (co < minCost) {                                   //�������ٻ��� �Լ�����·��
            finalPath = temPath;
            minCost = co;
        }
    }
    else {
        for (int i = 0; i < path[end].size(); i++) {
            int e = path[end][i];
            dfs(e, co + cost[end][e]);
        }
    }
    temPath.pop_back();                                     //�ǵõ�������ȫ�������Ľڵ�
}
int main() {
    int a, b;
    cin >> n >> m >> s >> d;
    if (s == d) {                                             //��㼴Ϊ�յ�
        cout << s << ' ' << 0 << ' ' << 0;
        return 0;
    }
    fill(graph[0], graph[0] + 500 * 500, INT_MAX);
    fill(dis, dis + 500, INT_MAX);
    int dis_, cost_;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d%d", &a, &b, &dis_, &cost_);
        graph[a][b] = graph[b][a] = dis_;
        cost[a][b] = cost[b][a] = cost_;                    //ע��������ͼcost[a][b] = cost[b][a]
    }
    dis[s] = 0;                                             //���������disΪ0
    for (int i = 0; i < n; i++) {
        int minDis = INT_MAX, u = -1;
        for (int j = 0; j < n; j++) {
            if (visited[j] == false && dis[j] < minDis) {
                u = j;
                minDis = dis[j];
            }
        }
        if (u == -1) break;
        visited[u] = true;                            //��ֵ�ű�д��==
        for (int v = 0; v < n; v++) {
            if (visited[v] == false && graph[u][v] < INT_MAX) {
                if (dis[v] > dis[u] + graph[u][v]) {
                    dis[v] = dis[u] + graph[u][v];
                    path[v].clear();
                    path[v].push_back(u);
                }
                else if (dis[v] == dis[u] + graph[u][v])   //����������·��
                    path[v].push_back(u);
            }
        }
    }
    dfs(d, 0);
    for (int i = finalPath.size() - 1; i >= 0; i--) 
        printf("%d ", finalPath[i]);
    printf("%d %d", dis[d], minCost);
    return 0;
}