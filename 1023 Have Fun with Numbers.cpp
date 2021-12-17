/*由于是20位，较大，所以将各个字符拆分出来计算并比较。
    1.声明两个int数组，存放原数input和翻倍后cmp的数中各数字的出现次数（下标对应数字，值对应出现的次数）；
    2.声明vector<int> ans，将翻倍后的数字中的每位依次存入其中；
    3.以字符串形式接受所给的数字，从末位开始，每位×2并加上进位，更新input和cmp数组，以及将得出的数的个位加入ans中；
    4.注意翻倍后的数字，位数可能比原来的数要多一位；*/
#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> ans;
    int input[10] = { 0 }, cmp[10] = { 0 };
    string s;
    cin >> s;
    int c = 0, sum;                     //c进位 sum单独一位乘以2的结果
    for (int i = s.length() - 1; i >= 0; i--) {
        sum = (s[i] - '0') * 2 + c;
        if (sum > 9) {
            c = 1;
            sum -= 10;
        }
        else c = 0;
        input[s[i] - '0'] += 1;
        cmp[sum] += 1;
        ans.push_back(sum);
    }
    if (c == 1) {                         //翻倍后最高位有进位
        ans.push_back(1);
        cout << "No" << endl;
    }
    else {                              //翻倍后位数不变
        for (int i = 0; i < 10; i++) {
            if (input[i] != cmp[i]) {
                cout << "No" << endl;
                for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
                return 0;
            }
        }
        cout << "Yes" << endl;
    }
    for (int i = ans.size() - 1; i >= 0; i--)  cout << ans[i];
    return 0;
}

/*
Input:
1234567899
Output:
Yes
2469135798
*/