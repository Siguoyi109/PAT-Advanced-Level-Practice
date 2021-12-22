//���ݽṹ�������ͣ�����������Ĺ�ͬ���֣�����д�÷ǳ�Ư����������ϰ��
# include <iostream>
using namespace std;
struct Node {
    char data;
    int next;
}node[100010];
int N;
int getLength(int start){
    int len = 0;
    for (int p = start; p != -1; p = node[p].next)
        len++;
    return len;
}

int main(){
    int start1, start2;
    cin >> start1 >> start2 >> N;
    for (int i = 0; i < N; ++i) {
        int now;
        cin >> now;
        cin >> node[now].data >> node[now].next;
    }
    // ��ȡ��������ĳ���
    int len1 = getLength(start1);
    int len2 = getLength(start2);
    int p = start1, q = start2;  // p��q�Ƿֱ�ָ����ֻ�����˫ָ��
    // �ó��Ƚϳ����Ǹ������ָ�����ߣ��ߵ�ʣ�µ��������һ����������ȣ����߳��˵���һ���֣�
    if (len1 > len2)
        for (int i = 0; i < len1 - len2; ++i)
            p = node[p].next;
    else
        for (int i = 0; i < len2 - len1; ++i)
            q = node[q].next;
    // ����ָ��ͬʱ���������������������ȵ�ַ�Ľڵ��˵���������������ˣ�ѭ�����������p��q
    while (p != q) {
        p = node[p].next;
        q = node[q].next;
    }
    // ���
    if (p != -1)
        printf("%05d\n", p);
    else
        cout << -1 << endl;
    return 0;
}
