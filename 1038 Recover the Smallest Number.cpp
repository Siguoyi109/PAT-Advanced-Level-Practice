/*
1.���ַ����������ݣ�
2.֮����ַ�������������򣬲�����̰�Ĳ��ԣ�
3.����ַ����������ƴ��Ϊ�ַ���s���õ���С���ַ�����
4.ע�����Է�0��ʼ��������Ҫȥ����ʼ��0����s.length() == 0ֱ�����0
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string str[10010];
//��һ���Ǿ��裻̫˧�����cmp
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
