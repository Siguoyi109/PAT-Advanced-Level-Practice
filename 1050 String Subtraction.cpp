/*
题目大意就是两个字符串相减
hash表：头文件
#include<unordered_set>
//定义hash表 ：没有重复元素
unordered_set<char>  hash1;
//hash表中查找和计数
hash1.count(x)  //在hash1中查找元素x
*/
#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

string a, b;

//哈希表
unordered_set<char> hash1;
int main() {
    getline(cin, a);
    getline(cin, b);
    for (auto c : b) hash1.insert(c);
    string res;
    for (auto c : a) {
        if (!hash1.count(c))  //这里查找是O(1)的复杂度
            res += c;
    }
    cout << res << endl;
}

