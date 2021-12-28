/*�������ʵ�����ڶ�̬�滮���ǳ��õ�һ����
���ֲ��ҵķ�������Ҫ����������⣺����ʱ�ĸ��ӶȺ����������
���Ҹ��Ӷ�ͨ�����ֲ��ҽ��ͣ���������ټ���ʯ���õ�����ֵ�����棬��������ǰ��������ʯ��ֵ����
���棬���������У�{1��2��3��4��5��6}���洢Ϊ���������Ǵ洢Ϊ{1��3��6��10��15��21}������Ҫĳ
һ�Σ���i��j)�ļ�ֵʱ��ֻ��Ҫ��j�ļ�ֵ��ȥ��i-1����ֵ����
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

