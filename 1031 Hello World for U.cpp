#include<iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int N, n, skip;
    N = s.length();                         //字符串总数
    n = (N + 2) / 3;                        //n1或n3
    skip = N - 2 * n;                       //需要输出的空格数
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