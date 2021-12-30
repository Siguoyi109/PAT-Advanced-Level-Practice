/*
给出一系列数字代表每枚硬币的价值，同时给出需要支付的金额M。求价值等于M的两个硬币，若方案不唯
一，输出硬币对中包含最小价值硬币的一组。
先将所给的硬币按照价格排序；
声明左右两个指针i，j。若两指针所指位置的硬币价值之和sum==M，直接输出i和j；若sum>M，j--；若sum<M，i++；
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
