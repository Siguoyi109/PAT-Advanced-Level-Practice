#include<iostream>
#include<map>
#include<iomanip>
using namespace std;

//�ⲻ�ѣ���������Ҫ���������������stl��ĺ���

int main2()
{
    int k[2];
    map<int, double, greater<int> > polyMap;
    map<int, double, greater<int> >::iterator it;

    for (int i = 0; i < 2; ++i)
    {
        cin >> k[i];
        int exp;
        double coe;
        for (int j = 0; j < k[i]; ++j)
        {
            cin >> exp >> coe;
            if ((it = polyMap.find(exp)) != polyMap.end())    //find����ҵ��ˣ����ظ�Ԫ�صĵ�����������Ҳ���������end()
            {
                if ((it->second += coe) == 0)
                {
                    polyMap.erase(it);
                }
                continue;
            }
            polyMap.insert(make_pair(exp, coe));
        }
    }
    cout << polyMap.size();
    for (it = polyMap.begin(); it != polyMap.end(); ++it)     //�����ס��ο��������λС����
    {
        cout << " " << it->first << " " << setiosflags(ios::fixed) << setprecision(1) << it->second;
    }
 
    cout << endl;

	system("pause");
	return 0;
}