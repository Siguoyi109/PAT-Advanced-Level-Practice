/*
    如果等待队列非空
        如果一个桌子空闲了出来
            如果当前的桌子是vip，则优先选择等待队列中的vip
            如果当前的桌子不是vip，但是可能和该桌子同时结束的另一个桌子号码较大，但是该大号桌子是vip
                如果下一个玩家是vip，则优先选择空闲桌子中是vip且号码较小的
                如果下一个玩家不是vip，则直接选择该桌子。
    如果等待队列是空的，
        如果到达了一个玩家
            如果该玩家是vip
                如果空闲桌子中存在vip桌子，则优先选择空闲桌子中是vip且号码较小的
                如果空闲桌子中无vip桌子，则优先选择空闲桌子号码较小的
            如果该玩家不是vip，则选择空闲桌子中号码较小的。
*/
/*
    1、如何判定等待队列为空？
        对于最快空闲的桌子，如果下一对到达的玩家的到达时间早于最快空闲的桌子的空闲时间，则等待队列非空
    2、如何表示一个VIP玩家已经被服务过？
        使用结构体，内部变量served，表示是否被服务过
    3、如何获取等待队列中的vip玩家？
        遍历这个等待队列，如果存在一个未被服务过的vip玩家，寻找到在等待队列中的第一个vip玩家。在这里，等待队列就是
        那些还没有被服务过且到达时间不晚于最快空闲桌子的空闲时间点的玩家。
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct person {
    int arrive, use, start;           //玩家对的到达时间，使用持续时间，开始使用时间
    bool served, vip;                //玩家对是否被服务过（F代表未使用过桌子），玩家对是否为vip
};
int cmp1(person& a, person& b) {
    return a.arrive < b.arrive;       //玩家对按到达时间顺序升序
}
int cmp2(person& a, person& b) {
    return a.start < b.start;         //服务过的玩家按开始使用时间升序
}
struct table {
    int endtime, cnt;                //桌子的结束使用时间（即何时空闲出来），桌子服务玩家对数量
    bool vip;                       //桌子是否为vip
};
vector<person> r;                   //玩家对序列，需按到达时间顺序来排序
vector<table> t;                    //桌子序列
/*
    找到index及之后的，并且到达（arrive）时间不晚于before的，未服务的，且为vip的 person-id
    如果没找到，则返回-1
*/
int findvip(int index, int before) {
    for (int i = index; i < r.size() && r[i].arrive <= before; i++) {
        if (!r[i].served && r[i].vip)
            return i;
    }
    return -1;
}
/*
    更新以personId的玩家对，和tableId的桌子的信息
    包括：
        1、将该玩家对的开始时间赋值为到达时间和可用桌子结束时间中的较大值
        2、将该玩家对的服务状态赋值为以服务过
        3、将桌子的结束时间信息更新为该玩家对的开始时间加该玩家的使用时间
        4、将该桌子服务的玩家数量加一
*/
void update(int personId, int tableId) {
    r[personId].start = max(r[personId].arrive, t[tableId].endtime);
    r[personId].served = 1;
    t[tableId].endtime = r[personId].start + r[personId].use;
    t[tableId].cnt++;
}

int main() {
    int n, m, k, tmpid;
    scanf("%d", &n);
    //初始化玩家对的信息，并排序
    for (int i = 0; i < n; i++) {
        int h, m, s, use, vip, arrive;
        scanf("%d:%d:%d %d %d", &h, &m, &s, &use, &vip);
        arrive = h * 3600 + m * 60 + s;
        use = use > 120 ? 7200 : use * 60;
        r.push_back({ arrive,use,0,0,vip > 0 });
    }
    sort(r.begin(), r.end(), cmp1);
    //初始化桌子的信息
    scanf("%d %d", &m, &k);
    for (int i = 0; i < m; i++)
        t.push_back({ 28800,0,0 });
    for (int i = 0; i < k; i++) {
        scanf("%d", &tmpid);
        t[tmpid - 1].vip = 1;
    }
    for (int i = 0; i < r.size();) {
        //找到最先空闲的桌子,如果多个桌子同时空闲，则返回桌子号最小的那个
        int minEndTime = INT_MAX, minEndIndex;
        for (int j = 0; j < m; j++) {
            if (minEndTime > t[j].endtime) {
                minEndTime = t[j].endtime;
                minEndIndex = j;
            }
        }
        //如果最先空闲的桌子空闲的太晚了，或者当前序列中的第一位玩家对达到的时间太晚了，就退出循环
        if (minEndTime >= 75600 || r[i].arrive >= 75600)
            break;
        //声明新的变量，personId为经过调整选择后最终的开始使用桌子的玩家对索引，tableId为为经过调整选择后最终的开始被使用的桌子
        int personId = i, tableId = minEndIndex;
        //如果当前的最早空闲且号最小的桌子空闲时，存在玩家对已经在等待了
        if (minEndTime >= r[i].arrive) {
            //并且当前的最早空闲且号最小的桌子是vip，寻找是vip的且未服务过的，玩家对到达时间不晚于minEndTime的玩家对索引
            if (t[tableId].vip) {
                int vipid = findvip(personId, minEndTime);
                personId = vipid != -1 ? vipid : personId;
            }
            else if (r[i].vip) { //虽然当前的最早空闲且号最小的桌子不是vip，但是还可能存在同时空闲，桌号更大的桌子是vip
                for (int j = 0; j < m; j++) {
                    if (t[j].vip && t[j].endtime <= r[personId].arrive) {
                        tableId = j;
                        break;
                    }
                }
            }
            /*
                如果当前的桌子非vip，且当前的序列的第一个玩家对非vip，顺序选择即可，换句话说，personId和tableId无需调整
            */
        }
        else {
            /*
                如果当前的最早空闲的桌子空闲时，没有玩家在等待序列中，即当一个玩家到达时，应该是至少有一个桌子是空闲的
                我们总是希望选择空闲中的桌子中桌子号最小的，如果到达了一个vip玩家对，并且存在空闲的vip桌子，我们选择空闲中的vip桌中号最小的
                在这里，我们不管是否是vip，先得到空闲中的桌子中桌子号最小的，如果当前到达的玩家对未vip，并且存在空闲的vip桌子，
                我们用空闲中的vip桌中号最小的那个桌子覆盖之前得到的tableId
            */
            for (int j = 0; j < m; j++) {           //从该行起的总共5行代码被注释掉仍能通过所有的测例，说明测例不够完善
                if (t[j].endtime <= r[personId].arrive) {
                    tableId = j;
                    break;
                }
            }
            if (r[personId].vip) {
                for (int j = 0; j < m; j++) {       //尝试寻找空闲的vip桌子并调整tableId，顺序找到即退出得到的就是号码最小的
                    if (t[j].vip && t[j].endtime <= r[personId].arrive) {
                        tableId = j;
                        break;
                    }
                }
            }
        }
        update(personId, tableId);
        //别忘了更新玩家对的遍历索引
        while (i < r.size() && r[i].served)++i;
    }
    //按要求输出被服务过的玩家对
    sort(r.begin(), r.end(), cmp2);
    for (int i = 0; i < r.size(); i++) {
        if (r[i].served) {
            int wait = r[i].start - r[i].arrive;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", r[i].arrive / 3600, r[i].arrive % 3600 / 60, r[i].arrive % 60, \
                r[i].start / 3600, r[i].start % 3600 / 60, r[i].start % 60, (int)(1.0 * wait / 60 + 0.5));
        }
    }
    for (int i = 0; i < m; i++)
        printf("%d%c", t[i].cnt, i == m - 1 ? '\n' : ' ');
    return 0;
}