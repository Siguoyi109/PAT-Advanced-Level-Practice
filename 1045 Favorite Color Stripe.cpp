/* ��̬�滮������������еı����⣻ת������ʵ��̫Ư����
��������һ������num����Evaϲ������ɫ��ţ������Ⱥ�˳�����¸�ֵ������{2 3 1 5 6}��num[2]=1��num[3]=2��num[1]=3����
�ڽ���ԭɫ��ʱ���޳�Eva��ϲ������ɫ������ϲ������ɫ���±�ţ�
��ʱ�����ת��ΪLIS���⣬�����ö�̬�滮��⡣ʱ�临�Ӷ�O(n^2);
*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main() {
    int num[201], data[10000];
    int n, m, l;                            //n�漰������ɫ�� mEvaϲ������ɫ��Ŀ lԭɫ���ĳ���
    int id, index = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        scanf("%d", &id);
        num[id] = i;                        //Ϊ��ɫ���ֵ��Ⱥ�˳����
    }
    cin >> l;
    for (int i = 0; i < l; i++) {
        scanf("%d", &id);
        if (num[id] > 0) {                    //ֻ����Evaϲ������ɫ
            data[index++] = num[id];
        }
    }
    int dp[10000], maxLen = 0;
    for (int i = 0; i < index; i++) {         //ԭɫ��������֮�� ����Ϊindex
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (data[i] >= data[j])
                dp[i] = max(dp[i], dp[j] + 1);//��̬����
        }
        maxLen = max(maxLen, dp[i]);        //��¼���ֵ
    }
    cout << maxLen;
    return 0;
}
