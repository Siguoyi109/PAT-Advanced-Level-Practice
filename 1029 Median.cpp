/*
�Ƚ��ܵ�һ�����ݣ��������mid��
������ܵڶ�������temp��������1��ǰ�±��Ӧ��Ԫ��С��tempʱ���ͽ������vector<int> ans�У�����temp����ans�С�ֱ��ans.size()�ﵽmidʱ�����ans[mid-1]��
���ڶ���������ǰ������ϣ����Ե�6����������һ�������ʣ��Ԫ�أ�ֱ��ans.size()==midʱ�����ans[mid-1]��
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int num1, num2, index = 0, mid;
    int input[200001], tem;
    vector<int> ans;
    scanf("%d", &num1);
    for (int i = 0; i < num1; i++) scanf("%d", &input[i]);
    scanf("%d", &num2);
    mid = (num1 + num2 + 1) / 2;             //��λ����λ��
    for (int i = 0; i < num2; i++) {
        scanf("%d", &tem);
        while (index < num1 && input[index] <= tem) {
            ans.push_back(input[index++]);
            if (ans.size() == mid) {            //ֻҪ�ﵽmid�����
                cout << ans[mid - 1];
                return 0;
            }
        }
        ans.push_back(tem);
        if (ans.size() == mid) {                          //ֻҪ�ﵽmid�����
            cout << ans[mid - 1];
            return 0;
        }
    }
    while (index < num1) {                                //���ڶ��������Ѿ�������� ��δ����mid
        ans.push_back(input[index++]);
        if (ans.size() == mid) {
            cout << ans[mid - 1];
            return 0;
        }
    }
    return 0;
}