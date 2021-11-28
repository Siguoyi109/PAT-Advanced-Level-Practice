#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const int N = 1000, M = 24 * 60, minuteOfAMonth = 31 * M + 10;
struct record {
    int minute;
    string formatTime;
    string state;
};
bool cmp(record a, record b) {
    return a.minute < b.minute;
}
map<string, vector<record>> records;
double sum[minuteOfAMonth];
int money[25];
int main16() {
    int n;
    for (int i = 0; i < 24; i++)  cin >> money[i];
    //��ӡһ��ʱ�������¼ÿһ���ӵĻ�����
    for (int i = 1; i < minuteOfAMonth; i++)sum[i] = sum[i - 1] + money[(i - 1) % M / 60] / 100.0;
    cin >> n;
    int month, day, hour, minute;
    char name[25], state[10], formatTime[25];
    for (int i = 0; i < n; i++) {
        scanf("%s %d:%d:%d:%d %s", name, &month, &day, &hour, &minute, state);
        int minutes = (day - 1) * M + 60 * hour + minute;
        //��������Ǹ�string��ֵ������ѧһ�£�
        sprintf(formatTime, "%02d:%02d:%02d", day, hour, minute);
        records[name].push_back({ minutes,formatTime,state });
    }
    //����a�����Ͼ��Ǹ��������������õ�������д��
    for (auto a : records) {
        double total = 0;
        string name = a.first;
        auto person = a.second;
        sort(person.begin(), person.end(), cmp);
        for (int i = 0; i + 1 < person.size(); i++) {
            auto a = person[i], b = person[i + 1];
            if (a.state == "on-line" && b.state == "off-line") {
                if (!total) {
                    printf("%s %02d\n", name.c_str(), month);
                }
                double charge = sum[b.minute] - sum[a.minute];
                printf("%s %s %d $%.2lf\n", a.formatTime.c_str(), b.formatTime.c_str(), b.minute - a.minute, charge);
                total += charge;
            }
        }
        if (total)printf("Total amount: $%.2lf\n", total);
    }
}