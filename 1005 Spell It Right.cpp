#include<iostream>
using namespace std;
#include<string>


int main5()
{
	string s;
	cin >> s;
	int sum = 0;
	for (int i = 0; i < (int)s.size(); i++)
	{
		sum += s[i] - '0';
	}
	string t = to_string(sum);
	switch (t[0] - '0')
	{
	case 0:cout << "zero";  break;
	case 1:cout << "one";  break;
	case 2:cout << "two";  break;
	case 3:cout << "three";  break;
	case 4:cout << "four";  break;
	case 5:cout << "five";  break;
	case 6:cout << "six";  break;
	case 7:cout << "seven";  break;
	case 8:cout << "eight";  break;
	case 9:cout << "nine";  break;
	default:
		break;
	}
	for (int j = 1; j < (int)t.size(); j++)
	{
		switch (t[j]-'0')
		{
		case 0:cout <<" " << "zero";  break;
		case 1:cout <<" " << "one";  break;
		case 2:cout <<" " << "two";  break;
		case 3:cout <<" " << "three";  break;
		case 4:cout <<" " << "four";  break;
		case 5:cout <<" " << "five";  break;
		case 6:cout <<" " << "six";  break;
		case 7:cout <<" " << "seven";  break;
		case 8:cout <<" " << "eight";  break;
		case 9:cout <<" " << "nine";  break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}