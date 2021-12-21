/*
先接受第一行数据，并计算出mid；
逐个接受第二行数据temp。当数组1当前下标对应的元素小于temp时，就将其放入vector<int> ans中，否则将temp放入ans中。直到ans.size()达到mid时，输出ans[mid-1]。
若第二个数组提前遍历完毕（测试点6），遍历第一个数组的剩余元素，直到ans.size()==mid时，输出ans[mid-1]。
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int num1, num2, index = 0, mid;
    int input[200001], tem;
    vector<int> ans;
    scanf("%d", &num1);
    for (int i = 0; i < num1; i++) scanf("%d", &input[i]);
    scanf("%d", &num2);
    mid = (num1 + num2 + 1) / 2;             //中位数的位置
    for (int i = 0; i < num2; i++) {
        scanf("%d", &tem);
        while (index < num1 && input[index] <= tem) {
            ans.push_back(input[index++]);
            if (ans.size() == mid) {            //只要达到mid就输出
                cout << ans[mid - 1];
                return 0;
            }
        }
        ans.push_back(tem);
        if (ans.size() == mid) {                          //只要达到mid就输出
            cout << ans[mid - 1];
            return 0;
        }
    }
    while (index < num1) {                                //若第二个数组已经遍历完毕 仍未到达mid
        ans.push_back(input[index++]);
        if (ans.size() == mid) {
            cout << ans[mid - 1];
            return 0;
        }
    }
    return 0;
}