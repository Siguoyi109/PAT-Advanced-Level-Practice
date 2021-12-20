#include <iostream>
#include <string>
using namespace std;
string str = "0123456789ABC";
string change(int a) {
    string s = "00";
    int index = 1;
    while (a) {
        s[index--] = str[a % 13];
        a /= 13;
    }
    return s;
}
int main(){
    int r, g, b;
    cin >> r >> g >> b;
    cout << "#" << change(r) << change(g) << change(b) << endl;
    return 0;
}
