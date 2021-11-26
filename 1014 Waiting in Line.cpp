#include<iostream>
#include<queue>
using namespace std;

struct Customer {
	int cost_time, start_time, end_time;
}customer[1001];
int main14()
{   // n�����ڣ�ÿ�����ڵ����ߣ������m���ˣ�k���ͻ�����q���ͻ���֪����ɶʱ�򱻷������
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	// ���п�ʼ����ʱ�䣬��������ʱ��
	int open_time = 8 * 60, close_time = 17 * 60;
	// n�����ڣ���1��ʼ
	queue<Customer>windows[21];
	// ����k���˻��ѵ�ʱ��
	for (int i = 1; i <= k; i++)
		cin >> customer[i].cost_time;
	// �Ŷ�
	for (int i = 1; i <= k; i++) {
		// ���������� n * m����
		if (i <= n * m) {
			// ��˳�򰤸����ڣ��˿�id�ʹ���id����1��ʼ
			int window = (i - 1) % n + 1;
			// ǰn���ˣ�һ��һ������
			if (i <= n) {
				// ��ʼʱ�������п�ʼ����ʱ��
				customer[i].start_time = open_time;
				// ���Ľ���ʱ�������Ŀ�ʼ��+���ķ���ʱ��
				customer[i].end_time = open_time + customer[i].cost_time;
			}
			else {
				//����һ��last_customer����һ���Ŷӵ��˾�������Ӷ�β���Ǹ���
				Customer last_customer = windows[window].back();
				// ���Ŀ�ʼʱ������һ���˵Ľ���ʱ��
				customer[i].start_time = last_customer.end_time;
				// ���Ľ���ʱ�������Ŀ�ʼ��+���ķ���ʱ��
				customer[i].end_time = customer[i].start_time + customer[i].cost_time;
			}
			// �ŵ���Ӧ����
			windows[window].push(customer[i]);
		}
		// ���������
		else {
			// ����һ���������뿪һ���ˣ����ǿ�ÿ������ǰ�Ǹ������е�һ���˵��뿪ʱ��
			int window = 1;
			for (int j = 2; j <= n; j++) {
				// ���ǵ�һ�����뿪�ĸ��磬��ѡ��������ڣ���ʵ�����ҵ������뿪���Ǹ���
				if (windows[j].front().end_time < windows[window].front().end_time)
					window = j;
			}
			// ������ڵ�һ���˳���
			windows[window].pop();
			Customer last_customer = windows[window].back();
			// ���Ŀ�ʼʱ������һ���˵Ľ���ʱ��
			customer[i].start_time = last_customer.end_time;
			// ���Ľ���ʱ�������Ŀ�ʼ��+���ķ���ʱ��
			customer[i].end_time = customer[i].start_time + customer[i].cost_time;
			//���
			windows[window].push(customer[i]);
		}
	}
	// q������Ҫ��ѯ�Լ�ʲôʱ���ܽ���
	int id;
	while (q-- > 0) {
		cin >> id;
		// ��ʼ����ʱ�䳬�������й���ʱ�䣬�޷�����
		if (customer[id].start_time >= close_time)
			cout << "Sorry" << endl;
		else
			printf("%02d:%02d\n", customer[id].end_time / 60, customer[id].end_time % 60);
	}
	return 0;
}