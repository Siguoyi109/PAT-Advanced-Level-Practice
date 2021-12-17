//���ĵ�һ���⣬����string��Ӧ�ú���Ȥ
#include <iostream>
#include<sstream>
using namespace std;

bool palindromic(string number) {          //�ж��Ƿ��ǻ���
    for (int i = 0; i < number.size() / 2; i++) {
        if (number[i] != number[number.size() - 1 - i]) 
            return false;
    }
    return true;
}
string paired(string number) {         //��number���ò��ҽ��д������ӷ�
    string reversedNumber = number;
    reverse(reversedNumber.begin(), reversedNumber.end());
    int carry = 0;
    for (int i = number.size() - 1; i >=0; i--) {
        int result = number[i] - '0' + reversedNumber[i] - '0' + carry;
        carry = result / 10;
        result %= 10;
        number[i] = '0' + result;
    }
    if (carry)        //�����λ��
        number = char('0' + carry) + number;    //����ֵ��ע�⣬����stringǰ�����һ���ַ�
    return number;
}
int main(int argc, char const* argv[]) {
    long long int N;
    int K;
    cin >> N >> K;
    int times = 0;
    stringstream ss;
    string number;
    ss << N;       //ss�Ǹ��������������N�Ž�������
    ss >> number;      //�����ss����ȡ������������ֵ��string number
    while (!palindromic(number) && times < K) {
        number = paired(number);
        times++;
    }
    cout << number << "\n" << times;
    return 0;
}
/*
Input:
67 3
Output:
484
2
*/
