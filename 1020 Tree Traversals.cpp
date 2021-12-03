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
int post[maxn];//�������򣬺�������
int n;//�ڵ���
//��ǰ�������ĺ������пռ�Ϊ��postl��postr�����������пռ�Ϊ��midl��midr��
//create�����������������ض��������ڵ��ַ��
struct node* create(int postl, int postr, int midl, int midr)
{
	if (postl > postr)//�������г���Ϊ0��ֱ�ӷ���
	{
		return nullptr;
	}
	node* root = new node;//�½��ڵ㣬��Ŷ��������ڵ�
	root->data = post[postr];//�½ڵ���ڵ��ֵ
	int k;
	for (k = midl; k <= midr; k++)
	{
		if (mid[k] == post[postr])//��������������ҵ�mid��k��==post��L���Ľڵ�
		{
			break;
		}
	}
	int num_left = k - midl;//�������Ľڵ������
	root->lchild = create(postl, postl + num_left - 1, midl, k - 1);//�����������ĸ��ڵ��ַ����ֵ��root��ָ��
	root->rchild = create(postl + num_left, postr - 1, k + 1, midr);//�����������ĸ��ڵ�ֵ����ֵ��root��ָ��
	return root;
}
void BFS(node* root)
{
	queue<node*>q;
	q.push(root);//���ڵ����
	int flag = 0;
	while (!q.empty())
	{
		node* tmp = q.front();//ȡ������ֵ
		q.pop();
		if (flag++ == 0)cout << tmp->data;//��ӡ����Ԫ��
		else cout << " " << tmp->data;
		if (tmp->lchild != nullptr)q.push(tmp->lchild);//�������ǿ������
		if (tmp->rchild != nullptr)q.push(tmp->rchild);//��������������
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
