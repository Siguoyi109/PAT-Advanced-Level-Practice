/*
1.以字符串接收数据，
2.之后对字符串数组进行排序，采用了贪心策略，
3.最后将字符串数组进行拼接为字符串s，得到最小的字符串，
4.注意是以非0开始，所以需要去掉开始的0，若s.length() == 0直接输出0
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string str[10010];
//这一步是精髓；太帅了这个cmp
bool cmp(string a, string b) {
	return a + b < b + a; 
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> str[i];
	sort(str, str + n, cmp);
	string s;
	for (int i = 0; i < n; i++) 
		s += str[i];
	while (s.length() >= 1 && s[0] == '0') 
		s.erase(s.begin());
	if (s.length() == 0) cout << 0;
	else cout << s;
	system("pause");
	return 0;
}
