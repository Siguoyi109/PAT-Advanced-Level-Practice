//���⣻�޸��ַ���������˼·ͦ��Ȥ
//    ����Ҫ���ĵ���ĸ�Ͷ�Ӧ����ĸ�ֱ����string�У������±�����Ҫ��Ӧ��
//    ���� vector���洢< string, string>������pair�������
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
        bool flag = true; //û�Ĺ�
        for (int i = 0; i < code.size(); i++) {
            int pos = suffix.find(code[i]);
            if (pos != -1) {
                code[i] = replace[pos];
                flag = false;
            }
        }
        if (!flag) cntM++, vec.push_back({ name,code });
    }
    if (cntM) { //���޸Ĺ���
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
