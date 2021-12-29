//这题的意思就是一个环，求两点之间的最短距离
#include <iostream>
using namespace std;

int main(){
    int N, M, d[100001] = { 0 }, check[10001];
    int tlen = 0;
    cin >> N;
    for (int i = 1; i <= N; i++){
        scanf_s("%d", &d[i]);
        d[i] += d[i - 1];
    }
    tlen = d[N];
    cin >> M;
    for (int i = 0; i < M; i++){
        int x, y;
        scanf_s("%d %d", &x, &y);
        if (x < y)
            swap(x, y);
        int temp = d[x - 1] - d[y - 1];
        printf_s("%d\n", min(temp, tlen - temp));
    }
    return 0;
}
/*
5 1 2 4 14 9             3
3                        10
1 3                      7
2 5
4 1
*/