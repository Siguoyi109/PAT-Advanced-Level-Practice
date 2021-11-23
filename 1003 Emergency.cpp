#include<iostream>
using namespace std;
#include<cstring>         //memset需要用这个头文件
#define inf 0x3f3f3f3f
int num_city, num_road, begin_city, end_city, city1, city2, road;
int num_team[505], map_city[505][505], num_shortest_paths[505], max_num_team[505];
int visited_city[505], shortest_path[505];
void dijkstra() 
{
	memset(visited_city, 0, sizeof(visited_city));    //初始化所有城市为没走过
	visited_city[begin_city] = 1;       //起点城市加入走过的城市
	num_shortest_paths[begin_city] = 1;        //起点城市到自己的最短路径只有一条
	max_num_team[begin_city] = num_team[begin_city];     //起点城市到自己，最大救援队数量等于他自己的救援队数
	for (int i = 0; i < num_city; i++)
	{
		shortest_path[i] = map_city[begin_city][i];     //初始化起点城市到其他城市的最短路径
		if (shortest_path[i] != inf && i != begin_city)     //如果i可以直接到达起点城市的话，设到i的最短路径数量为1；
		{                                                   //到i的最大救援队数为起点加自己的；
			num_shortest_paths[i] = 1;
			max_num_team[i] = max_num_team[begin_city] + num_team[i];
		}
	}
	for (int i = 0; i < num_city; i++)     //这个循环每次加入一个点
	{
		int temp = inf;
		int add_city=begin_city;     //这两个变量是为了下面赋值和判断备用的
		for (int j = 0; j < num_city; j++)        //这个循环是找到没走过的路径最短的点
			if (!visited_city[j] && temp > shortest_path[j]) 
			{ 
				temp = shortest_path[j]; 
				add_city = j;
			}
		visited_city[add_city] = 1;     //放入走过的城市的集合
		for (int j = 0; j < num_city; j++)
		{    //更新其他没有走过的点的最短路径
			if (!visited_city[j] && (shortest_path[add_city] + map_city[add_city][j] < shortest_path[j]))
			{
				shortest_path[j] = shortest_path[add_city] + map_city[add_city][j];//更新最短路径
				num_shortest_paths[j] = num_shortest_paths[add_city];//更新最短路径数量为到达该店的最短路径数量
				max_num_team[j] = max_num_team[add_city] + num_team[j]; //更新最大队伍数
			}
			else if(!visited_city[j] && (shortest_path[add_city] + map_city[add_city][j]) == shortest_path[j])
				//如果加入该点后，最短路径不变
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
	memset(map_city, inf, sizeof(map_city));    //初始化全为不通
	cin >> num_city >> num_road >> begin_city >> end_city;
	for (int i = 0; i < num_city; i++)      //城市到自身为0
		map_city[i][i] = 0;
	for (int i = 0; i < num_city; i++)
		cin >> num_team[i];
	for (int i = 0; i < num_road; i++)      //无向图；路为双向的
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