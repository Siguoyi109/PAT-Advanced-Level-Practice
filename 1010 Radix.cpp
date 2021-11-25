#include<iostream>
#include<cctype>
#include<algorithm>
#include<cmath>
using namespace std;
long long convert(string s, long long radix) {
    long long sum = 0;
    int index = 0, temp = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (isdigit(s[i]))           //sum += (s[i] - '0') * int(pow(radix, index++))ǿ������ת���� �����������Ե��޷�ͨ��
            sum += (s[i] - '0') * pow(radix, index++);
        else  sum += (s[i] - 'a' + 10) * pow(radix, index++);
    }
    return sum;
}
long long find_radix(string n, long long num) {

    char it = *max_element(n.begin(), n.end()); //*max_element�������ѧ����:ȡ���ֵ������*ȡ���ֵ��λ�ã�
    long long low = (isdigit(it) ? it - '0' : it - 'a' + 10) + 1;//������С����
    long long high = max(num, low);//��num̫С ��ȡδȷ�����Ƶ�������С����Ϊ���ֵ ���統����Ϊ1 1 1 2
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long t = convert(n, mid);
        if (t < 0 || t > num)   high = mid - 1;   //t<0����̫���� ������� ��Ҳ����ȡֵ����
        else if (t == num)   return mid;
        else low = mid + 1;
    }
    return -1;
}
int main10() {
    string n1, n2;
    long long tag = 0, radix = 0, result_radix;
    cin >> n1 >> n2 >> tag >> radix;
    result_radix = tag == 1 ? find_radix(n2, convert(n1, radix)) : find_radix(n1, convert(n2, radix));
    if (result_radix != -1)  printf("%lld", result_radix);
    else  printf("Impossible");
    return 0;
}