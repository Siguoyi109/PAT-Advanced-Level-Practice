#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

bool visited[500];
int graph[500][500], cost[500][500];                        //graph存放每条路的用时 cost存放每条路的花费
int dis[500];
vector<int> path[500];                                      //存放所有节点的所有最短路径
vector<int> temPath, finalPath;                             //temPath临时的最终路径 finalPath最终路径
int n, m, s, d;                                             //n城市数目 m路数目 s起点 d终点
int minCost = INT_MAX;
void dfs(int end, int co) {
    temPath.push_back(end);
    if (end == s) {                                           //已经从终点到达起点（倒着进行DFS）
        if (co < minCost) {                                   //更新最少花费 以及最终路径
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
    temPath.pop_back();                                     //记得弹出已完全遍历过的节点
}
int main() {
    int a, b;
    cin >> n >> m >> s >> d;
    if (s == d) {                                             //起点即为终点
        cout << s << ' ' << 0 << ' ' << 0;
        return 0;
    }
    fill(graph[0], graph[0] + 500 * 500, INT_MAX);
    fill(dis, dis + 500, INT_MAX);
    int dis_, cost_;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d%d", &a, &b, &dis_, &cost_);
        graph[a][b] = graph[b][a] = dis_;
        cost[a][b] = cost[b][a] = cost_;                    //注意是无向图cost[a][b] = cost[b][a]
    }
    dis[s] = 0;                                             //起点先设置dis为0
    for (int i = 0; i < n; i++) {
        int minDis = INT_MAX, u = -1;
        for (int j = 0; j < n; j++) {
            if (visited[j] == false && dis[j] < minDis) {
                u = j;
                minDis = dis[j];
            }
        }
        if (u == -1) break;
        visited[u] = true;                            //赋值号别写成==
        for (int v = 0; v < n; v++) {
            if (visited[v] == false && graph[u][v] < INT_MAX) {
                if (dis[v] > dis[u] + graph[u][v]) {
                    dis[v] = dis[u] + graph[u][v];
                    path[v].clear();
                    path[v].push_back(u);
                }
                else if (dis[v] == dis[u] + graph[u][v])   //保存多条最短路径
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