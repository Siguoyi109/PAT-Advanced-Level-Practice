/*
��Ŀ������������ַ������
hash��ͷ�ļ�
#include<unordered_set>
//����hash�� ��û���ظ�Ԫ��
unordered_set<char>  hash1;
//hash���в��Һͼ���
hash1.count(x)  //��hash1�в���Ԫ��x
*/
#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

string a, b;

//��ϣ��
unordered_set<char> hash1;
int main() {
    getline(cin, a);
    getline(cin, b);
    for (auto c : b) hash1.insert(c);
    string res;
    for (auto c : a) {
        if (!hash1.count(c))  //���������O(1)�ĸ��Ӷ�
            res += c;
    }
    cout << res << endl;
}

