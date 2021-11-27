#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int d[100001];
bool isprime(int n) {
	if (n <= 1)   return false;
	int t = int(sqrt(n * 1.0));
	for (int i = 2; i <= t; i++) {
		if (n % i == 0)   return false;
	}
	return true;
}
int main15() {
	int n, radix;
	while (scanf("%d", &n) != EOF && n >= 0) {
		cin >> radix;
		if (!isprime(n))  cout << "No" << endl;
		else {
			//进制转换
			int len = 0;
			while (n != 0) {
				d[len++] = n % radix;
				n /= radix;
			}
			//进制逆序
			for (int i = 0; i < len; i++)
				n = n * radix + d[i];
			if (isprime(n))cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}