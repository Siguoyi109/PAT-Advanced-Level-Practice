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
    //��ʱֹ��
    if (visited[cur]) return;
    visited[cur] = 1;//�������㱻����
    //ͳ���ж��ٸ���ͨ���������Բ���Ҫά������
    for (int i : v[cur]) {//������ǰ��������ھ�
        dfs(i);
    }
}
void dfs2(int cur, int depth) {
    if (visited[cur]) return;
    visited[cur] = 1;//����ѷ���
    if (depth > maxdis) {
        maxdis = depth; //����������
        farthest_point.clear(); //������ٸ���
        farthest_point.emplace_back(cur); //�����Զ�㼯��֮�������Ž�ȥ
    }
    else if (depth == maxdis) {//ͬ����ȾͲ���Ҫ��յ㼯��ֻ��Ҫ���������ȼӽ�ȥ�Ϳ�����
        farthest_point.emplace_back(cur);
    }
    for (int i : v[cur]) {//���ʵ�ǰ�����ھ�
        dfs2(i, depth + 1);
    }
}
int main21() {
    int N, i, j, k;
    cin >> N;
    //N����������ҪN-1���߽�����ȫ���������������Դ�1��N
    for (i = 1; i < N; i++) {
        cin >> j >> k;
        v[j].emplace_back(k);
        v[k].emplace_back(j);
    }
    //���ж�
    for (int i = 1; i <= N; i++)visited[i] = 0;
    int cnt = 0;
    //ע��������Ҫͳ���ж��ٸ���ͨ����
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            cnt++;
            dfs(i);
        }
    }
    if (cnt > 1) {//�����������ɻ���
        cout << "Error: " << cnt << " components";
    }
    else {//��������ͼֻ���ҵ�һ����ͨ�ĵ㼯��������
        for (int i = 1; i <= N; i++)visited[i] = 0;
        dfs2(1, 0);  //��һ��dfs2&&�����һ��������DFS
        for (int each : farthest_point) final_answer.insert(each);
        //����һ��dfs2��ȫ����ת�Ƶ�final_answer�У�������������ݣ�������һ��dfs2
        farthest_point.clear();
        maxdis = 0;
        for (int i = 1; i <= N; i++)visited[i] = 0;
        dfs2(*final_answer.begin(), 0);//�ڶ���dfs2&&ȡ��������ָ�룬����Ҫ��*
        //�ڶ���dfs2���õ��������Ҳȫ������final_answer��
        for (int each : farthest_point) final_answer.insert(each);

        for (int each : final_answer) { cout << each << '\n'; }
    }
    //����dfs2֮��ͻ��ҵ�������ҵ�һ����Ϊ��������ҵ��������ȵ��յ�
    //������Щ�����յ�Ϊ��㣬�ٽ���һ��dfs�Ϳ����ҵ�������

    return 0;
}
