#include<iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int N, n, skip;
    N = s.length();                         //�ַ�������
    n = (N + 2) / 3;                        //n1��n3
    skip = N - 2 * n;                       //��Ҫ����Ŀո���
    int left = 0, right = s.length() - 1;
    while (left < n - 1) {
        printf("%c", s[left++]);
        for (int i = 0; i < skip; i++) printf(" ");
        printf("%c\n", s[right--]);
    }
    while (left <= right) 
        printf("%c", s[left++]);
    return 0;
}