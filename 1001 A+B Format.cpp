#include <iostream>
#include <string>
using namespace std;

//ע���ҵ���������ļ��롮������λ�ã���ʵ����%3��λ�ã�

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
            /*����ֻ�Ƕ�3ȡ��Ϊ0�Ϳ����ˣ��Ͱ�������˵��λ����6������%����Ϊ0������Ȼ
            ��ʱ���������,�����Ե�һλ��������ָ�����ͬ������ĩβʱ��
            ���һ��Ҳ�ǲ���Ҫ�ġ�
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
