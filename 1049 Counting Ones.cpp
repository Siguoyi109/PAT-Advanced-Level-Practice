/*
��Ŀ������ǣ�����N����1-N����������'1'�������ܺ�
��������һ������N����Ҫ�жϴ�����������iλ��1���ֵĴ���numʱ�����Խ�������ֳַ������֣��ֱ�
��left��current��right��ʾ����left=����N��iλ�������֡�current=����N�ڵ�iλ�����֡�right=��
��N��iλ�Ҳ�����֡���������N=123456���жϴ��������2λҲ���ǰ�λ�ϣ�������4����λ��1���ֵĴ�
��ʱ��left=123��current=4��right=56����ʱ������������м��㣺
1.current=0:num=left*10^i
2.current=1:num=left*10^i+(right+1)
3.current>1:num=left*10^i+10^i
*/
#include <iostream>
using namespace std;
int main()
{
    int n, ans = 0;
    cin >> n;
    int left = n / 10, right = 0, cur = n % 10;
    for (int i = 1; right != n; i *= 10)
    {
        ans += left * i + (cur == 0 ? 0 : cur == 1 ? (right + 1) : i);
        right += cur * i;
        cur = left % 10;
        left /= 10;
    }
    cout << ans << endl;
    return 0;
}
/*
12            5
*/