#include <iostream>
using namespace std;
int main8() {
	int n;
	cin >> n;
	int index = 0, now, ans = 0, i;
	for (i = 0; i < n; i++) {
		cin >> now;
		if (now > index) ans += (now - index) * 6;
		if (now < index) ans += (index - now) * 4;
		ans += 5;
		index = now;
	}
	cout << ans;
	return 0;
}
