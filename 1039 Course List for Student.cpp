//很简单的一道题，自己就A出来了
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

bool cmp1(int a, int b) {
    return a < b;
}
int main() {
    int n, k;                        //n查询选课的人数 k课程数目
    cin >> n >> k;
    map<string, vector<int> > data;
    string name;
    name.resize(4);
    int course, num;                 //course课程编号 num选课人数
    for (int i = 0; i < k; i++) {
        cin >> course >> num;
        for (int j = 0; j < num; j++) {
            cin >> name;
            data[name].push_back(course);
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> name;
        cout << name;
        cout << data[name].size();
        sort(data[name].begin(), data[name].end(), cmp1);   //按照课程代码从小到大排序
        for (auto it = data[name].begin(); it != data[name].end(); it++) {
            printf(" %d", *it);
        }
        printf("\n");
    }
    return 0;
}

