//回文的一道题，关于string的应用很有趣
#include <iostream>
#include<sstream>
using namespace std;

bool palindromic(string number) {          //判断是否是回文
    for (int i = 0; i < number.size() / 2; i++) {
        if (number[i] != number[number.size() - 1 - i]) 
            return false;
    }
    return true;
}
string paired(string number) {         //将number倒置并且进行大整数加法
    string reversedNumber = number;
    reverse(reversedNumber.begin(), reversedNumber.end());
    int carry = 0;
    for (int i = number.size() - 1; i >=0; i--) {
        int result = number[i] - '0' + reversedNumber[i] - '0' + carry;
        carry = result / 10;
        result %= 10;
        number[i] = '0' + result;
    }
    if (carry)        //如果进位了
        number = char('0' + carry) + number;    //这里值得注意，是在string前面加了一个字符
    return number;
}
int main(int argc, char const* argv[]) {
    long long int N;
    int K;
    cin >> N >> K;
    int times = 0;
    stringstream ss;
    string number;
    ss << N;       //ss是个输入流；代表把N放进输入流
    ss >> number;      //代表从ss中提取出输入流，赋值给string number
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
