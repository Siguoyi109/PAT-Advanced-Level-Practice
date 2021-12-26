//���ö�̬�滮���⣬dp[i][j]��ʾ�Ӵ�i->j�Ƿ��ǻ��ģ���˶�̬����Ϊdp[i][j] = s[i] == s[j] && dp[i + 1][j - 1]
#include <iostream>
#include <algorithm>
#include<vector>
#include<string>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    int n = s.size(), res = 1;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
        if (i <= n - 2 && s[i] == s[i + 1]) {
            dp[i][i + 1] = true;      //����Ϊ2�Ļ��Ĵ�
            res = 2;
        }
    }
    for (int len = 3; len <= n; ++len) {    //����Ϊ3��3���ϵĻ��Ĵ�
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {   
                dp[i][j] = true;
                res = len;
            }
        }
    }
    printf("%d", res);
    return 0;
}
