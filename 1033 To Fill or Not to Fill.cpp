/*
    先将加油站按距离排序；从当前位置开始
    若可达范围内有更便宜的加油站，则加油量足够到达第一个比当前便宜的加油站，直接过去，到后油量正好为0；
    若可达范围内无更便宜的加油站，则在当前站加满油，去可达范围内最便宜的加油站，到后还有剩余油量。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Station {
    float p;    //价格
    float d;    //离起点的距离
};
bool cmp(Station& s1, Station& s2) {
    return s1.d < s2.d;
}
int main() {
    float cap, dest, perGas, n;
    cin >> cap >> dest >> perGas >> n;
    vector<Station> s(n + 1);
    for (int i = 0; i < n; i++)
        cin >> s[i].p >> s[i].d;
    s[n].p = 0;      
    s[n].d = dest;
    sort(s.begin(), s.end(), cmp);
    if (s[0].d != 0) {  //起点没有加油站，寸步难行
        cout << "The maximum travel distance = 0.00" << endl;
        return 0;
    }
    float cost = 0;  //总花费
    float range = cap * perGas;
    float cur = 0;  //当前加油站
    float gasLeft = 0;  //到达下个加油站后会剩的油量
    bool unReachable = false;
    while (cur < n) {
        float minP = INT_MAX;
        int next = -1;
        bool foundCheaper = false;
        for (int i = cur + 1; s[i].d <= s[cur].d + range; i++) {
            if (s[i].p < minP) {
                minP = s[i].p;
                next = i;
            }
            if (s[i].p < s[cur].p) {
                next = i;
                foundCheaper = true;
                break;
            }
        }
        if (next == -1) {  //够不到下一个加油站了
            unReachable = true;
            break;
        }
        if (foundCheaper) {
            cost += (((s[next].d - s[cur].d) / perGas - gasLeft) * s[cur].p);
            gasLeft = 0;  //加到正好能到达下一个比当前便宜的加油站，一点都不多加
        }
        else {
            cost += ((cap - gasLeft) * s[cur].p);  //加满
            gasLeft = (cap - (s[next].d - s[cur].d) / perGas);  //剩余油量
        }
        cur = next;
    }
    if (unReachable) {
        printf("The maximum travel distance = %02.2f\n", s[cur].d + range);
    }
    else {
        printf("%02.2f\n", cost);
    }
    return 0;
}

