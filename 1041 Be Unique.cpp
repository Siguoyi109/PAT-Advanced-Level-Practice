//送分题，但是要思考怎么让map不排序
#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int, int> mp;
    int input[100001], N;
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> input[i];
        mp[input[i]]++;
    }
    for (int i = 0; i < N; i++){
        if (mp[input[i]] == 1){
            cout << input[i];
            return 0;
        }
    }
    cout << "None";
    return 0;
}
