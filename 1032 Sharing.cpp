//数据结构经典题型：找两个链表的共同部分，代码写得非常漂亮，反复复习！
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
    // 获取两个链表的长度
    int len1 = getLength(start1);
    int len2 = getLength(start2);
    int p = start1, q = start2;  // p、q是分别指向两只链表的双指针
    // 让长度较长的那个链表的指针先走，走到剩下的链表和另一个链表长度相等（就走长了的那一部分）
    if (len1 > len2)
        for (int i = 0; i < len1 - len2; ++i)
            p = node[p].next;
    else
        for (int i = 0; i < len2 - len1; ++i)
            q = node[q].next;
    // 两个指针同时遍历两个链表，如果遇到相等地址的节点就说明遇到公共部分了，循环结束，输出p或q
    while (p != q) {
        p = node[p].next;
        q = node[q].next;
    }
    // 输出
    if (p != -1)
        printf("%05d\n", p);
    else
        cout << -1 << endl;
    return 0;
}
