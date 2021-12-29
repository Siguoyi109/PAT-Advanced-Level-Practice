/* 动态规划：最长有序子序列的变种题；转换方法实在太漂亮了
重新声明一个数组num，将Eva喜欢的颜色编号，按照先后顺序重新赋值，比如{2 3 1 5 6}，num[2]=1，num[3]=2，num[1]=3……
在接受原色带时，剔除Eva不喜欢的颜色，并将喜欢的颜色重新编号：
此时问题便转换为LIS问题，并可用动态规划求解。时间复杂度O(n^2);
*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main() {
    int num[201], data[10000];
    int n, m, l;                            //n涉及到的颜色数 mEva喜欢的颜色数目 l原色带的长度
    int id, index = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        scanf("%d", &id);
        num[id] = i;                        //为颜色出现的先后顺序编号
    }
    cin >> l;
    for (int i = 0; i < l; i++) {
        scanf("%d", &id);
        if (num[id] > 0) {                    //只保留Eva喜欢的颜色
            data[index++] = num[id];
        }
    }
    int dp[10000], maxLen = 0;
    for (int i = 0; i < index; i++) {         //原色带处理完之后 长度为index
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (data[i] >= data[j])
                dp[i] = max(dp[i], dp[j] + 1);//动态方程
        }
        maxLen = max(maxLen, dp[i]);        //记录最大值
    }
    cout << maxLen;
    return 0;
}
