//�ܼ򵥵�һ���⣬�Լ���A������
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
    int n, k;                        //n��ѯѡ�ε����� k�γ���Ŀ
    cin >> n >> k;
    map<string, vector<int> > data;
    string name;
    name.resize(4);
    int course, num;                 //course�γ̱�� numѡ������
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
        sort(data[name].begin(), data[name].end(), cmp1);   //���տγ̴����С��������
        for (auto it = data[name].begin(); it != data[name].end(); it++) {
            printf(" %d", *it);
        }
        printf("\n");
    }
    return 0;
}

