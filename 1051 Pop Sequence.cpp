/*
题的意思就是：判断出栈序列是否正确（反复学习）
*/
#include <iostream>
#include <stack>
using namespace std;
int M, N, K, v[1001];
int main(){
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++){
        stack<int> s;
        int cur = 0, flag = 0, current = 0;
        for (int j = 0; j < N; j++)
            cin >> v[j];
        for (int j = 1; j <= N; j++){
            s.push(j);
            if (s.size() > M){
                flag = 1;
                break;
            }
            if (v[current] > s.top())
                continue;
            while (s.size() > 0 && v[current] <= s.top()){
                if (v[current] == s.top()){
                    s.pop();
                    current++;
                    continue;
                }
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
/*
5 7 5             
1 2 3 4 5 6 7               YES
3 2 1 7 5 6 4               NO
7 6 5 4 3 2 1               NO
5 6 4 3 7 2 1               YES
1 7 6 5 4 3 2               NO
*/
