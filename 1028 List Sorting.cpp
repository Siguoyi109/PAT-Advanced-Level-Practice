#include <stdio.h>
#include<iostream>
#include <algorithm>
#include<string.h>
using namespace std;
struct Stu {
    char name[10];
    int id, score;
}stu[100000];
int m;
bool cmp(Stu& a, Stu& b) {
    if (m == 1)
        return a.id < b.id;
    else if (m == 2) {
        if (strcmp(a.name, b.name) == 0)
            return a.id < b.id;
        else
            return strcmp(a.name, b.name) <= 0;
    }
    else if (m == 3) {
        if (a.score < b.score)
            return true;
        else if (a.score == b.score)
            return a.id < b.id;
    }
    return false;
}
int main() {
    int n;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d%s%d", &stu[i].id, &stu[i].name, &stu[i].score);
    }
    sort(stu, stu + n, cmp);
    for (int i = 0; i < n; i++)
        printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].score);
    return 0;
}