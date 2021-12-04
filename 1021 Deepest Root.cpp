#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> v[10001];
int visited[10001];
vector<int>farthest_point;
int maxdis = 0;
set<int>final_answer;
void dfs(int cur) {
    //及时止损
    if (visited[cur]) return;
    visited[cur] = 1;//标记这个点被访问
    //统计有多少个连通分量，所以不需要维护变量
    for (int i : v[cur]) {//遍历当前点的所有邻居
        dfs(i);
    }
}
void dfs2(int cur, int depth) {
    if (visited[cur]) return;
    visited[cur] = 1;//标记已访问
    if (depth > maxdis) {
        maxdis = depth; //更新最大深度
        farthest_point.clear(); //先清空再更新
        farthest_point.emplace_back(cur); //清空最远点集合之后将这个点放进去
    }
    else if (depth == maxdis) {//同等深度就不需要清空点集，只需要把这个等深度加进去就可以了
        farthest_point.emplace_back(cur);
    }
    for (int i : v[cur]) {//访问当前结点的邻居
        dfs2(i, depth + 1);
    }
}
int main21() {
    int N, i, j, k;
    cin >> N;
    //N个点最少需要N-1条边将他们全部连接起来，所以从1到N
    for (i = 1; i < N; i++) {
        cin >> j >> k;
        v[j].emplace_back(k);
        v[k].emplace_back(j);
    }
    //先判断
    for (int i = 1; i <= N; i++)visited[i] = 0;
    int cnt = 0;
    //注意这里是要统计有多少个连通分量
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            cnt++;
            dfs(i);
        }
    }
    if (cnt > 1) {//不是树，即成环了
        cout << "Error: " << cnt << " components";
    }
    else {//遍历整个图只能找到一个连通的点集，即是树
        for (int i = 1; i <= N; i++)visited[i] = 0;
        dfs2(1, 0);  //第一次dfs2&&随便找一个起点进行DFS
        for (int each : farthest_point) final_answer.insert(each);
        //将第一次dfs2中全部点转移到final_answer中，并清空最深数据，进行下一次dfs2
        farthest_point.clear();
        maxdis = 0;
        for (int i = 1; i <= N; i++)visited[i] = 0;
        dfs2(*final_answer.begin(), 0);//第二次dfs2&&取出来的是指针，所以要加*
        //第二次dfs2所得到的最深点也全部放入final_answer中
        for (int each : farthest_point) final_answer.insert(each);

        for (int each : final_answer) { cout << each << '\n'; }
    }
    //经过dfs2之后就会找到以随便找的一个点为起点所能找到的最大深度的终点
    //再以这些最深终点为起点，再进行一次dfs就可以找到最大深度

    return 0;
}
