//题理论来说不难，但是逻辑需要比较清晰；可以看一下
#include <iostream>
using namespace std;

int main(){
    int k;
    char arr[55][4] = { "0", //0是拿来充数的
        "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13",
        "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13",
        "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13",
        "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13",
        "J1", "J2" };
    int v[55], res[55], seq[55];
    cin >> k;
    if (k == 0)
        return 1;
    for (int i = 1; i < 55; i++)
        v[i] = i;
    for (int i = 1; i < 55; i++){
        cin >> seq[i];
        res[seq[i]] = v[i];
    }
    while (--k){
        for (int i = 1; i < 55; i++)
            v[i] = res[i];
        for (int i = 1; i < 55; i++)
            res[seq[i]] = v[i];
    }
    cout << arr[res[1]];
    for (int i = 2; i < 55; i++)
        cout << " " << arr[res[i]];
    return 0;
}