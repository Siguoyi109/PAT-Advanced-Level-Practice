//�ܼ򵥵�̰����Ŀ
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> a;
vector<int> b;
int main(){
    int np, nc, tmp, _; long long int sum = 0;
    for (scanf_s("%d", &nc), _ = nc; _; _--) { scanf_s("%d", &tmp); a.push_back(tmp); }
    for (scanf_s("%d", &np), _ = np; _; _--) { scanf_s("%d", &tmp); b.push_back(tmp); }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int p = 0, c = 0;
    while (p < np && c < nc && a[c] < 0 && b[p] < 0) { sum += a[c] * b[p]; p++; c++; }// ��С�ĸ���֮�����
    p = np - 1; c = nc - 1;
    while (p >= 0 && c >= 0 && a[c] > 0 && b[p] > 0) { sum += a[c] * b[p]; p--; c--; }// ��������֮�����
    printf("%lld\n", sum);
    a.clear(); b.clear();
    return 0;
}