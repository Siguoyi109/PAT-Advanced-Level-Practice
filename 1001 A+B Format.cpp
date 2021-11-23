#include <iostream>
#include <string>
using namespace std;

//注意找到满足题意的加入‘，’的位置；其实就是%3的位置；

int main1() {
    int a, b;
    cin >> a >> b;
    int sum = a + b;
    if (sum < 0) {
        cout << "-";
        sum = -sum;
    }
    string s = to_string(sum);
    if (s.length() <= 3)
        cout << s;
    else {
        int count = s.length();
        for (unsigned int i = 0; i < s.length(); i++) {
            /*不能只是对3取余为0就可以了，就按样例来说，位数是6，满足%运算为0，但显然
            此时不能输出“,”所以第一位不能输出分隔符，同理当到达末尾时，
            最后一个也是不需要的。
            */
            if (count % 3 == 0 && count != s.length() && i != s.length() - 1) {
                cout << ",";
            }
            cout << s[i];
            count--;
        }
    }
    system("pause");
    return 0;
}
