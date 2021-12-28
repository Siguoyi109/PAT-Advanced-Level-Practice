/*һ����������ǰ�����������⣬�����Ȼ�����񣻷�����ϰ
������þ���BST���ص㣺
    ��������ֵС�ڵ�ǰ�ڵ㣬��������ֵ���ڵ��ڵ�ǰ�ڵ㣻
    BST�����������ֻҪ��ֵС�ڸ��ڵ�root�Ķ����������ϵĵ㣬��������������ϵĵ㡣
    �ݴ˿����ж������������ĸ��ڵ㣬���ݹ�ı���������������
*/
#include<iostream>
#include<vector>
using namespace std;
bool isMirror;
vector<int> pre, post;
void getPost(int root, int tail) {
    if (root > tail) return;
    int i = root + 1, j = tail;
    if (isMirror == false) {
        while (i <= tail && pre[i] < pre[root]) i++;
        while (j > root && pre[j] >= pre[root]) j--;
    }
    else {
        while (i <= tail && pre[i] >= pre[root]) i++;
        while (j > root && pre[j] < pre[root]) j--;
    }
    if (i - j != 1) return;                  //���������i-jӦ����1!!!(��������������� ��ôpost�ĳ��Ⱦͻ�С��n)
    getPost(root + 1, j);                   //����������
    getPost(i, tail);                       //����������
    post.push_back(pre[root]);              //������� ��󽫸��ڵ���ջ
}
int main() {
    int n;
    cin >> n;
    int num;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        pre.push_back(num);
    }
    getPost(0, n - 1);
    if (post.size() != n) {
        isMirror = true;
        post.clear();
        getPost(0, n - 1);
    }
    if (post.size() != n) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl << post[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << post[i];

    return 0;
}

