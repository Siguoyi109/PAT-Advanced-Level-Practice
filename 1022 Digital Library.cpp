//柳神没有建立结构体数组，直接用map建立了各类信息到id集合（用set能去重且自动升序排列）的映射;
#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;
int n;
map<string, set<int>> title, author, keywords, publisher, year;
void query(map<string, set<int>>& m, string& str) {
	if (m.find(str) != m.end()) {
		for (set<int>::iterator i = m[str].begin(); i != m[str].end(); i++) 
			printf("%07d\n", *i);
	}
	else 
		cout << "Not Found" << endl;
}
int main() {
	cin >> n;
	int id;
	string t_title, t_author, t_key, t_publisher, t_year;
	for (int i = 0; i < n; i++) {
		cin >> id;
		getchar();    //这里很重要；是用getchar吸收cin后面的换行符
		getline(cin, t_title);
		title[t_title].insert(id);
		getline(cin, t_author);
		author[t_author].insert(id);
		while (cin >> t_key) {
			keywords[t_key].insert(id);
			char c = getchar();   //吸收的是关键字间的" "；
			if (c == '\n') 
				break;
		}
		getline(cin, t_publisher);
		publisher[t_publisher].insert(id);
		getline(cin, t_year);
		year[t_year].insert(id);
	}
	int m;
	cin >> m;
	int num;
	string q;
	for (int i = 0; i < m; i++) {
		scanf_s("%d: ", &num);
		getline(cin, q);
		cout << num << ": " << q << endl;
		if (num == 1) query(title, q);
		else if (num == 2) query(author, q);
		else if (num == 3) query(keywords, q);
		else if (num == 4) query(publisher, q);
		else if (num == 5) query(year, q);
	}
	system("pause");
	return 0;
}
/* 
Input:                           
3
1111111
The Testing Book
Yue Chen
test code debug sort keywords
ZUCS Print
2011
3333333
Another Testing Book
Yue Chen
test code sort keywords
ZUCS Print2
2012
2222222
The Testing Book
CYLL
keywords debug book
ZUCS Print2
2011
6
1: The Testing Book
2: Yue Chen
3: keywords
4: ZUCS Print
5: 2011
3: blablabla
*/
