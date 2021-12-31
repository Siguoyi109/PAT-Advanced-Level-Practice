/*
题目大意就是，给个N，求1-N所有数出现'1'次数的总和
对于任意一个数字N，当要判断从右向左数第i位上1出现的次数num时，可以将这个数字分成三部分，分别
用left、current、right表示，即left=数字N在i位左侧的数字、current=数字N在第i位的数字、right=数
字N在i位右侧的数字。例如数字N=123456，判断从右向左第2位也就是百位上，即数字4所在位置1出现的次
数时，left=123、current=4、right=56。此时分三种情况进行计算：
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