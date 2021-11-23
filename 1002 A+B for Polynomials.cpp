#include<iostream>
#include<map>
#include<iomanip>
using namespace std;

//题不难；不过代码要尽量精简；灵活运用stl里的函数

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
            if ((it = polyMap.find(exp)) != polyMap.end())    //find如果找到了，返回该元素的迭代器；如果找不到，返回end()
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
    for (it = polyMap.begin(); it != polyMap.end(); ++it)     //这里记住如何控制输出几位小数；
    {
        cout << " " << it->first << " " << setiosflags(ios::fixed) << setprecision(1) << it->second;
    }
 
    cout << endl;

	system("pause");
	return 0;
}