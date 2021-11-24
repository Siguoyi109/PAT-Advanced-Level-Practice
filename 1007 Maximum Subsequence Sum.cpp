#include<iostream>
using namespace std;

int a[10001];
int main7()
{
	int k;
	cin >> k;
	int thissum, maxsum = -1, left = 0, right = k - 1;
	for (int i = 0; i < k; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < k; i++)
	{
		thissum = 0;
		for (int j = i; j < k; j++)
		{
			thissum += a[j];
			if (thissum > maxsum) {
				maxsum = thissum;
				left = i;
				right = j;
			}
		}
	}
	if (maxsum < 0)  maxsum = 0;
	cout << maxsum << " " << a[left] << " " << a[right];

	system("pause");
	return 0;
}