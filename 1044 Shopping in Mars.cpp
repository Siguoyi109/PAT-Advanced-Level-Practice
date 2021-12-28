/*这道题其实类似于动态规划；非常好的一道题
二分查找的方法，主要解决两个问题：查找时的复杂度和子问题减少
查找复杂度通过二分查找降低，子问题减少即钻石不用单个价值来保存，而是用其前面所有钻石价值和来
保存，比如上例中，{1，2，3，4，5，6}不存储为这样，而是存储为{1，3，6，10，15，21}，当需要某
一段（如i到j)的价值时，只需要用j的价值减去第i-1个价值即可
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sum, res;
int maxN = 999999999;
int N, K;
int search(int p){
    int start = p, end = N;
    while (start < end){
        int mid = (start + end) / 2;
        if (sum[mid] - sum[p - 1] >= K)
            end = mid;
        else
            start = mid + 1;
    }
    int temp = sum[start] - sum[p - 1];
    if (temp >= K && temp <= maxN){
        if (temp < maxN){
            maxN = temp;
            res.clear();
        }
        res.push_back(p);
        res.push_back(start);
    }
    return 0;
}
int main(){
    cin >> N >> K;
    sum.resize(N + 1);
    sum[0] = 0;
    for (int i = 1; i <= N; i++){
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }
    for (int i = 1; i <= N; i++)
        search(i);
    for (int i = 0; i < res.size(); i += 2)
        cout << res[i] << "-" << res[i + 1] << endl;
    return 0;
}

