#include<iostream>
#include<queue>
using namespace std;

struct Customer {
	int cost_time, start_time, end_time;
}customer[1001];
int main14()
{   // n个窗口，每个窗口到黄线，最多排m个人，k个客户，有q个客户想知道他啥时候被服务结束
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	// 银行开始服务时间，结束服务时间
	int open_time = 8 * 60, close_time = 17 * 60;
	// n个窗口，从1开始
	queue<Customer>windows[21];
	// 读入k个人花费的时间
	for (int i = 1; i <= k; i++)
		cin >> customer[i].cost_time;
	// 排队
	for (int i = 1; i <= k; i++) {
		// 黄线内能排 n * m个人
		if (i <= n * m) {
			// 按顺序挨个窗口，顾客id和窗口id都从1开始
			int window = (i - 1) % n + 1;
			// 前n个人，一人一个窗口
			if (i <= n) {
				// 开始时间是银行开始服务时间
				customer[i].start_time = open_time;
				// 他的结束时间是他的开始加+他的服务时间
				customer[i].end_time = open_time + customer[i].cost_time;
			}
			else {
				//创立一个last_customer，上一个排队的人就是这个队队尾的那个人
				Customer last_customer = windows[window].back();
				// 他的开始时间是上一个人的结束时间
				customer[i].start_time = last_customer.end_time;
				// 他的结束时间是他的开始加+他的服务时间
				customer[i].end_time = customer[i].start_time + customer[i].cost_time;
			}
			// 排到对应窗口
			windows[window].push(customer[i]);
		}
		// 黄线外的人
		else {
			// 看哪一个窗口先离开一个人，就是看每个窗口前那个队伍中第一个人的离开时间
			int window = 1;
			for (int j = 2; j <= n; j++) {
				// 除非第一个人离开的更早，才选择这个窗口；其实就是找到最早离开的那个人
				if (windows[j].front().end_time < windows[window].front().end_time)
					window = j;
			}
			// 这个窗口第一个人出队
			windows[window].pop();
			Customer last_customer = windows[window].back();
			// 他的开始时间是上一个人的结束时间
			customer[i].start_time = last_customer.end_time;
			// 他的结束时间是他的开始加+他的服务时间
			customer[i].end_time = customer[i].start_time + customer[i].cost_time;
			//入队
			windows[window].push(customer[i]);
		}
	}
	// q个人想要查询自己什么时间能结束
	int id;
	while (q-- > 0) {
		cin >> id;
		// 开始服务时间超过了银行关门时间，无法服务
		if (customer[id].start_time >= close_time)
			cout << "Sorry" << endl;
		else
			printf("%02d:%02d\n", customer[id].end_time / 60, customer[id].end_time % 60);
	}
	return 0;
}