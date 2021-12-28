/*一道关于树的前序后序遍历的题，柳神果然是柳神；反复复习
充分利用镜像BST的特点：
    左子树的值小于当前节点，右子树的值大于等于当前节点；
    BST的先序遍历，只要是值小于根节点root的都是左子树上的点，否则就是右子树上的点。
    据此可以判断左右两子树的根节点，并递归的遍历左右两子树；
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
    if (i - j != 1) return;                  //正常情况下i-j应等于1!!!(若不符合先序遍历 那么post的长度就会小于n)
    getPost(root + 1, j);                   //遍历左子树
    getPost(i, tail);                       //遍历右子树
    post.push_back(pre[root]);              //后序遍历 最后将根节点入栈
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

