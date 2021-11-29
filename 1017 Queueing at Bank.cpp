#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;

struct node {
    int arrive;
    int p_time;
    node(int a, int b) :arrive(a), p_time(b) {}
};
vector<node>R;
bool cmp(node x, node y) { return x.arrive < y.arrive; }
int main17()
{
    int N, M; cin >> N >> M;
    while (N--) {
        int a, b, c, d; scanf_s("%d:%d:%d %d", &a, &b, &c, &d);
        int temp = a * 3600 + b * 60 + c;
        //�ٵ����˺���
        if (temp <= 17 * 3600) R.push_back(node(temp, d * 60));
    }
    sort(R.begin(), R.end(), cmp);
    int wait = 0;
    //��¼ÿ�����ڵ�ʱ�䣬��ʼ����8:00��ʼ��������������������
    vector<int>windows(M + 2, 8 * 3600);//��д��
    int i = 0;
    for (; i < R.size(); ++i) {
        int p, minn = inf;
        for (int j = 1; j <= M; ++j){   //ѡ���ȴ�����Ĵ���
            if (windows[j] < minn) {
                minn = windows[j];
                p = j;
            }
        }
        if (R[i].arrive < windows[p]) {//��Ҫ�ȴ�
            wait += windows[p] - R[i].arrive;
            windows[p] += R[i].p_time;
        }
        else windows[p] = R[i].arrive + R[i].p_time;//����Ҫ�ȴ�
    }
    printf("%.1f\n", wait * 1.0 / 60 / R.size());
    return 0;
}