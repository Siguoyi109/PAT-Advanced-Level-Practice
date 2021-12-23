/*
    �Ƚ�����վ���������򣻴ӵ�ǰλ�ÿ�ʼ
    ���ɴﷶΧ���и����˵ļ���վ����������㹻�����һ���ȵ�ǰ���˵ļ���վ��ֱ�ӹ�ȥ��������������Ϊ0��
    ���ɴﷶΧ���޸����˵ļ���վ�����ڵ�ǰվ�����ͣ�ȥ�ɴﷶΧ������˵ļ���վ��������ʣ��������
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Station {
    float p;    //�۸�
    float d;    //�����ľ���
};
bool cmp(Station& s1, Station& s2) {
    return s1.d < s2.d;
}
int main() {
    float cap, dest, perGas, n;
    cin >> cap >> dest >> perGas >> n;
    vector<Station> s(n + 1);
    for (int i = 0; i < n; i++)
        cin >> s[i].p >> s[i].d;
    s[n].p = 0;      
    s[n].d = dest;
    sort(s.begin(), s.end(), cmp);
    if (s[0].d != 0) {  //���û�м���վ���粽����
        cout << "The maximum travel distance = 0.00" << endl;
        return 0;
    }
    float cost = 0;  //�ܻ���
    float range = cap * perGas;
    float cur = 0;  //��ǰ����վ
    float gasLeft = 0;  //�����¸�����վ���ʣ������
    bool unReachable = false;
    while (cur < n) {
        float minP = INT_MAX;
        int next = -1;
        bool foundCheaper = false;
        for (int i = cur + 1; s[i].d <= s[cur].d + range; i++) {
            if (s[i].p < minP) {
                minP = s[i].p;
                next = i;
            }
            if (s[i].p < s[cur].p) {
                next = i;
                foundCheaper = true;
                break;
            }
        }
        if (next == -1) {  //��������һ������վ��
            unReachable = true;
            break;
        }
        if (foundCheaper) {
            cost += (((s[next].d - s[cur].d) / perGas - gasLeft) * s[cur].p);
            gasLeft = 0;  //�ӵ������ܵ�����һ���ȵ�ǰ���˵ļ���վ��һ�㶼�����
        }
        else {
            cost += ((cap - gasLeft) * s[cur].p);  //����
            gasLeft = (cap - (s[next].d - s[cur].d) / perGas);  //ʣ������
        }
        cur = next;
    }
    if (unReachable) {
        printf("The maximum travel distance = %02.2f\n", s[cur].d + range);
    }
    else {
        printf("%02.2f\n", cost);
    }
    return 0;
}

