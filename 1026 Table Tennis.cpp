/*
    ����ȴ����зǿ�
        ���һ�����ӿ����˳���
            �����ǰ��������vip��������ѡ��ȴ������е�vip
            �����ǰ�����Ӳ���vip�����ǿ��ܺ͸�����ͬʱ��������һ�����Ӻ���ϴ󣬵��Ǹô��������vip
                �����һ�������vip��������ѡ�������������vip�Һ����С��
                �����һ����Ҳ���vip����ֱ��ѡ������ӡ�
    ����ȴ������ǿյģ�
        ���������һ�����
            ����������vip
                ������������д���vip���ӣ�������ѡ�������������vip�Һ����С��
                ���������������vip���ӣ�������ѡ��������Ӻ����С��
            �������Ҳ���vip����ѡ����������к����С�ġ�
*/
/*
    1������ж��ȴ�����Ϊ�գ�
        ���������е����ӣ������һ�Ե������ҵĵ���ʱ�����������е����ӵĿ���ʱ�䣬��ȴ����зǿ�
    2����α�ʾһ��VIP����Ѿ����������
        ʹ�ýṹ�壬�ڲ�����served����ʾ�Ƿ񱻷����
    3����λ�ȡ�ȴ������е�vip��ң�
        ��������ȴ����У��������һ��δ���������vip��ң�Ѱ�ҵ��ڵȴ������еĵ�һ��vip��ҡ�������ȴ����о���
        ��Щ��û�б�������ҵ���ʱ�䲻�������������ӵĿ���ʱ������ҡ�
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct person {
    int arrive, use, start;           //��ҶԵĵ���ʱ�䣬ʹ�ó���ʱ�䣬��ʼʹ��ʱ��
    bool served, vip;                //��Ҷ��Ƿ񱻷������F����δʹ�ù����ӣ�����Ҷ��Ƿ�Ϊvip
};
int cmp1(person& a, person& b) {
    return a.arrive < b.arrive;       //��Ҷ԰�����ʱ��˳������
}
int cmp2(person& a, person& b) {
    return a.start < b.start;         //���������Ұ���ʼʹ��ʱ������
}
struct table {
    int endtime, cnt;                //���ӵĽ���ʹ��ʱ�䣨����ʱ���г����������ӷ�����Ҷ�����
    bool vip;                       //�����Ƿ�Ϊvip
};
vector<person> r;                   //��Ҷ����У��谴����ʱ��˳��������
vector<table> t;                    //��������
/*
    �ҵ�index��֮��ģ����ҵ��arrive��ʱ�䲻����before�ģ�δ����ģ���Ϊvip�� person-id
    ���û�ҵ����򷵻�-1
*/
int findvip(int index, int before) {
    for (int i = index; i < r.size() && r[i].arrive <= before; i++) {
        if (!r[i].served && r[i].vip)
            return i;
    }
    return -1;
}
/*
    ������personId����Ҷԣ���tableId�����ӵ���Ϣ
    ������
        1��������ҶԵĿ�ʼʱ�丳ֵΪ����ʱ��Ϳ������ӽ���ʱ���еĽϴ�ֵ
        2��������ҶԵķ���״̬��ֵΪ�Է����
        3�������ӵĽ���ʱ����Ϣ����Ϊ����ҶԵĿ�ʼʱ��Ӹ���ҵ�ʹ��ʱ��
        4���������ӷ�������������һ
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
    //��ʼ����ҶԵ���Ϣ��������
    for (int i = 0; i < n; i++) {
        int h, m, s, use, vip, arrive;
        scanf("%d:%d:%d %d %d", &h, &m, &s, &use, &vip);
        arrive = h * 3600 + m * 60 + s;
        use = use > 120 ? 7200 : use * 60;
        r.push_back({ arrive,use,0,0,vip > 0 });
    }
    sort(r.begin(), r.end(), cmp1);
    //��ʼ�����ӵ���Ϣ
    scanf("%d %d", &m, &k);
    for (int i = 0; i < m; i++)
        t.push_back({ 28800,0,0 });
    for (int i = 0; i < k; i++) {
        scanf("%d", &tmpid);
        t[tmpid - 1].vip = 1;
    }
    for (int i = 0; i < r.size();) {
        //�ҵ����ȿ��е�����,����������ͬʱ���У��򷵻����Ӻ���С���Ǹ�
        int minEndTime = INT_MAX, minEndIndex;
        for (int j = 0; j < m; j++) {
            if (minEndTime > t[j].endtime) {
                minEndTime = t[j].endtime;
                minEndIndex = j;
            }
        }
        //������ȿ��е����ӿ��е�̫���ˣ����ߵ�ǰ�����еĵ�һλ��ҶԴﵽ��ʱ��̫���ˣ����˳�ѭ��
        if (minEndTime >= 75600 || r[i].arrive >= 75600)
            break;
        //�����µı�����personIdΪ��������ѡ������յĿ�ʼʹ�����ӵ���Ҷ�������tableIdΪΪ��������ѡ������յĿ�ʼ��ʹ�õ�����
        int personId = i, tableId = minEndIndex;
        //�����ǰ����������Һ���С�����ӿ���ʱ��������Ҷ��Ѿ��ڵȴ���
        if (minEndTime >= r[i].arrive) {
            //���ҵ�ǰ����������Һ���С��������vip��Ѱ����vip����δ������ģ���ҶԵ���ʱ�䲻����minEndTime����Ҷ�����
            if (t[tableId].vip) {
                int vipid = findvip(personId, minEndTime);
                personId = vipid != -1 ? vipid : personId;
            }
            else if (r[i].vip) { //��Ȼ��ǰ����������Һ���С�����Ӳ���vip�����ǻ����ܴ���ͬʱ���У����Ÿ����������vip
                for (int j = 0; j < m; j++) {
                    if (t[j].vip && t[j].endtime <= r[personId].arrive) {
                        tableId = j;
                        break;
                    }
                }
            }
            /*
                �����ǰ�����ӷ�vip���ҵ�ǰ�����еĵ�һ����ҶԷ�vip��˳��ѡ�񼴿ɣ����仰˵��personId��tableId�������
            */
        }
        else {
            /*
                �����ǰ��������е����ӿ���ʱ��û������ڵȴ������У�����һ����ҵ���ʱ��Ӧ����������һ�������ǿ��е�
                ��������ϣ��ѡ������е����������Ӻ���С�ģ����������һ��vip��Ҷԣ����Ҵ��ڿ��е�vip���ӣ�����ѡ������е�vip���к���С��
                ��������ǲ����Ƿ���vip���ȵõ������е����������Ӻ���С�ģ������ǰ�������Ҷ�δvip�����Ҵ��ڿ��е�vip���ӣ�
                �����ÿ����е�vip���к���С���Ǹ����Ӹ���֮ǰ�õ���tableId
            */
            for (int j = 0; j < m; j++) {           //�Ӹ�������ܹ�5�д��뱻ע�͵�����ͨ�����еĲ�����˵��������������
                if (t[j].endtime <= r[personId].arrive) {
                    tableId = j;
                    break;
                }
            }
            if (r[personId].vip) {
                for (int j = 0; j < m; j++) {       //����Ѱ�ҿ��е�vip���Ӳ�����tableId��˳���ҵ����˳��õ��ľ��Ǻ�����С��
                    if (t[j].vip && t[j].endtime <= r[personId].arrive) {
                        tableId = j;
                        break;
                    }
                }
            }
        }
        update(personId, tableId);
        //�����˸�����ҶԵı�������
        while (i < r.size() && r[i].served)++i;
    }
    //��Ҫ����������������Ҷ�
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