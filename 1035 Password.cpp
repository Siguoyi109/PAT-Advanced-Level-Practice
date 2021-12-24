//简单题；修改字符串，不过思路挺有趣
//    把需要更改的字母和对应的字母分别存在string中，两者下标索引要对应。
//    采用 vector来存储< string, string>这样的pair便于输出
#include<iostream>
#include<vector>
using namespace std;
string Name, Code;
typedef pair< string, string> PII;
vector<PII> vec;
int main() {
    int n;
    cin >> n;
    int N = n;
    int cntM = 0;
    string suffix = "01lO";
    string replace = "%@Lo";
    while (n--) {
        string name, code;
        cin >> name >> code;
        bool flag = true; //没改过
        for (int i = 0; i < code.size(); i++) {
            int pos = suffix.find(code[i]);
            if (pos != -1) {
                code[i] = replace[pos];
                flag = false;
            }
        }
        if (!flag) cntM++, vec.push_back({ name,code });
    }
    if (cntM) { //有修改过的
        cout << cntM << endl;
        for (auto c : vec) 
            cout << c.first << " " << c.second << endl;
    }
    else {
        if (N != 1)
            cout << "There are " << N << " accounts and no account is modified";
        else
            cout << "There is " << N << " account and no account is modified";
    }
}
