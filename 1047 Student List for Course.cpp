//����ÿ��ѧ��ѡ�Ŀγ̣�Ҫ�����ÿ�ſγ̶�Ӧ��ѡ��ѧ��������
//�Ƚϼ򵥣��Լ�����ac������map<int, vector<string>> data 
#include<iostream>
#include<vector>
#include<string.h>
#include<map>
#include<math.h>
#include<algorithm>
#include<climits>
using namespace std;
bool cmp1(string a, string b) {
    return a < b;
}
int main() {
    int N, K;
    cin >> N >> K;
    map< int, vector<string> > data;
    string name;
    name.resize(4);
    int num, course;
    for (int i = 0; i < N; i++) {
        scanf("%s %d", &name[0], &num);
        for (int j = 0; j < num; j++) {
            scanf("%d", &course);
            data[course].push_back(name);
        }
    }
    for (int i = 1; i <= K; i++) {
        sort(data[i].begin(), data[i].end(), cmp1);
        printf("%d %d\n", i, data[i].size());
        for (int j = 0; j < data[i].size(); j++) 
            printf("%s\n", data[i][j].c_str());
    }
    return 0;
}
