#include<iostream>
using namespace std;
#include<cstring>         //memset��Ҫ�����ͷ�ļ�
#define inf 0x3f3f3f3f
int num_city, num_road, begin_city, end_city, city1, city2, road;
int num_team[505], map_city[505][505], num_shortest_paths[505], max_num_team[505];
int visited_city[505], shortest_path[505];
void dijkstra() 
{
	memset(visited_city, 0, sizeof(visited_city));    //��ʼ�����г���Ϊû�߹�
	visited_city[begin_city] = 1;       //�����м����߹��ĳ���
	num_shortest_paths[begin_city] = 1;        //�����е��Լ������·��ֻ��һ��
	max_num_team[begin_city] = num_team[begin_city];     //�����е��Լ�������Ԯ�������������Լ��ľ�Ԯ����
	for (int i = 0; i < num_city; i++)
	{
		shortest_path[i] = map_city[begin_city][i];     //��ʼ�������е��������е����·��
		if (shortest_path[i] != inf && i != begin_city)     //���i����ֱ�ӵ��������еĻ����赽i�����·������Ϊ1��
		{                                                   //��i������Ԯ����Ϊ�����Լ��ģ�
			num_shortest_paths[i] = 1;
			max_num_team[i] = max_num_team[begin_city] + num_team[i];
		}
	}
	for (int i = 0; i < num_city; i++)     //���ѭ��ÿ�μ���һ����
	{
		int temp = inf;
		int add_city=begin_city;     //������������Ϊ�����渳ֵ���жϱ��õ�
		for (int j = 0; j < num_city; j++)        //���ѭ�����ҵ�û�߹���·����̵ĵ�
			if (!visited_city[j] && temp > shortest_path[j]) 
			{ 
				temp = shortest_path[j]; 
				add_city = j;
			}
		visited_city[add_city] = 1;     //�����߹��ĳ��еļ���
		for (int j = 0; j < num_city; j++)
		{    //��������û���߹��ĵ�����·��
			if (!visited_city[j] && (shortest_path[add_city] + map_city[add_city][j] < shortest_path[j]))
			{
				shortest_path[j] = shortest_path[add_city] + map_city[add_city][j];//�������·��
				num_shortest_paths[j] = num_shortest_paths[add_city];//�������·������Ϊ����õ�����·������
				max_num_team[j] = max_num_team[add_city] + num_team[j]; //������������
			}
			else if(!visited_city[j] && (shortest_path[add_city] + map_city[add_city][j]) == shortest_path[j])
				//�������õ�����·������
			{
				num_shortest_paths[j] += num_shortest_paths[add_city];
				if (max_num_team[add_city] + num_team[j] > max_num_team[j])
					max_num_team[j] = max_num_team[add_city] + num_team[j];
			}

		}
	}
}

int main3()
{
	memset(map_city, inf, sizeof(map_city));    //��ʼ��ȫΪ��ͨ
	cin >> num_city >> num_road >> begin_city >> end_city;
	for (int i = 0; i < num_city; i++)      //���е�����Ϊ0
		map_city[i][i] = 0;
	for (int i = 0; i < num_city; i++)
		cin >> num_team[i];
	for (int i = 0; i < num_road; i++)      //����ͼ��·Ϊ˫���
	{
		cin >> city1 >> city2 >> road;
		map_city[city1][city2] = road;
		map_city[city2][city1] = road;
	}
	dijkstra();
	
	cout << num_shortest_paths[end_city]<<" "<< max_num_team[end_city] << endl;
	system("pause");
	return 0;
}