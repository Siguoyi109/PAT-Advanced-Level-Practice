/*������20λ���ϴ����Խ������ַ���ֳ������㲢�Ƚϡ�
    1.��������int���飬���ԭ��input�ͷ�����cmp�����и����ֵĳ��ִ������±��Ӧ���֣�ֵ��Ӧ���ֵĴ�������
    2.����vector<int> ans����������������е�ÿλ���δ������У�
    3.���ַ�����ʽ�������������֣���ĩλ��ʼ��ÿλ��2�����Ͻ�λ������input��cmp���飬�Լ����ó������ĸ�λ����ans�У�
    4.ע�ⷭ��������֣�λ�����ܱ�ԭ������Ҫ��һλ��*/
#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> ans;
    int input[10] = { 0 }, cmp[10] = { 0 };
    string s;
    cin >> s;
    int c = 0, sum;                     //c��λ sum����һλ����2�Ľ��
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
    if (c == 1) {                         //���������λ�н�λ
        ans.push_back(1);
        cout << "No" << endl;
    }
    else {                              //������λ������
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