#include <iostream>
using namespace std;
#include<string>
int main6() {
    int n, minn = INT_MAX, maxn = INT_MIN;
    cin >> n;
    string unlocked, locked;
    for (int i = 0; i < n; i++) {
        string t;
        char p = ':',q=' ';
        cin >> t;
        int h1, m1, s1, h2, m2, s2;
        cin >> h1 >> p >> m1 >> p >> s1 >> h2 >> p >> m2 >> p >> s2;
        int tempIn = h1 * 3600 + m1 * 60 + s1;
        int tempOut = h2 * 3600 + m2 * 60 + s2;
        if (tempIn < minn) {
            minn = tempIn;
            unlocked = t;
        }
        if (tempOut > maxn) {
            maxn = tempOut;
            locked = t;
        }
    }
    cout << unlocked << " " << locked;
    system("pause");
    return 0;
}
