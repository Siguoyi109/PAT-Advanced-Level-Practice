/*
����һϵ�����ִ���ÿöӲ�ҵļ�ֵ��ͬʱ������Ҫ֧���Ľ��M�����ֵ����M������Ӳ�ң���������Ψ
һ�����Ӳ�Ҷ��а�����С��ֵӲ�ҵ�һ�顣
�Ƚ�������Ӳ�Ұ��ռ۸�����
������������ָ��i��j������ָ����ָλ�õ�Ӳ�Ҽ�ֵ֮��sum==M��ֱ�����i��j����sum>M��j--����sum<M��i++��
*/
#include<iostream>
#include<vector>
#include<string.h>
#include<map>
#include<math.h>
#include<algorithm>
#include<climits>
using namespace std;
bool cmp1(int a, int b) {
    return a < b;
}
int main() {
    int N, M;
    cin >> N >> M;

    vector<int> data;
    int num;
    for (int i = 0; i < N; i++) {
        scanf_s("%d", &num);
        data.push_back(num);
    }
    sort(data.begin(), data.end(), cmp1);

    int i = 0, j = N - 1;
    while (i < j) {//<
        if (data[i] + data[j] == M) {
            printf_s("%d %d", data[i], data[j]);
            return 0;
        }
        else if (data[i] + data[j] < M)
            i++;
        else
            j--;
    }
    printf("No Solution");
    return 0;
}
/*
8 15                           4 11
1 2 8 7 2 4 11 15
*/
