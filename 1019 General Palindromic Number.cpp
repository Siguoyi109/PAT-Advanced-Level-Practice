#include<iostream>
using namespace std;

int main19()
{
    int z[40], num = 0;//数组z存放q进制数y的每一位，num为位数
    int q, y;
    int flag = 1;
    scanf_s("%d %d", &y, &q);
    do {
        z[num++] = y % q;
        y = y / q;
    } while (y != 0);
    for (int i = 0; i <= num / 2; i++) {
        if (z[i] != z[num - 1 - i]) {
            flag = 0;
            break;
        }
    }
    if (flag == 1)  printf("Yes\n");
    if (flag == 0)  printf("No\n");
    printf("%d", z[num - 1]);
    for (int i = num - 2; i >= 0; i--) 
        printf(" %d", z[i]);
	system("pause");
	return 0;
}