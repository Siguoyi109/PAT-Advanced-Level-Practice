#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct node {
	int data;
	node* lchild;
	node* rchild;
};
const int maxn = 50;
int pre[maxn];
int mid[maxn];
int post[maxn];//先序，中序，后序数组
int n;//节点数
//当前二叉树的后序序列空间为【postl，postr】，中序序列空间为【midl，midr】
//create函数用来建树，返回二叉树根节点地址；
struct node* create(int postl, int postr, int midl, int midr)
{
	if (postl > postr)//后序序列长度为0，直接返回
	{
		return nullptr;
	}
	node* root = new node;//新建节点，存放二叉树根节点
	root->data = post[postr];//新节点根节点的值
	int k;
	for (k = midl; k <= midr; k++)
	{
		if (mid[k] == post[postr])//中序遍历序列中找到mid【k】==post【L】的节点
		{
			break;
		}
	}
	int num_left = k - midl;//左子树的节点个数，
	root->lchild = create(postl, postl + num_left - 1, midl, k - 1);//返回左子树的根节点地址，赋值给root左指针
	root->rchild = create(postl + num_left, postr - 1, k + 1, midr);//返回又子树的根节点值，赋值给root右指针
	return root;
}
void BFS(node* root)
{
	queue<node*>q;
	q.push(root);//根节点入队
	int flag = 0;
	while (!q.empty())
	{
		node* tmp = q.front();//取出队首值
		q.pop();
		if (flag++ == 0)cout << tmp->data;//打印队首元素
		else cout << " " << tmp->data;
		if (tmp->lchild != nullptr)q.push(tmp->lchild);//左子树非空则入队
		if (tmp->rchild != nullptr)q.push(tmp->rchild);//右子树非则空入队
	}

}
int main20()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> post[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> mid[i];
	}
	node* root = create(0, n - 1, 0, n - 1);
	BFS(root);
	system("pause");
	return 0;
}
