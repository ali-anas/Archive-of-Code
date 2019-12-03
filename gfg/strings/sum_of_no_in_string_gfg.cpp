#include <iostream>

using namespace std;

int findSum(string str)
{
	string temp = "";
	int sum = 0;
	for(char ch: str)
	{
		if(isdigit(ch))
			temp += ch;
		else
		{
			sum += atoi(temp.c_str());
			temp = "";
		}
	}
	return sum + atoi(temp.c_str());
}

int main()
{
	int test_cases;
	cin >> test_cases;
	while(test_cases--)
	{
		string str;
		cin >> str;
		cout << findSum(str);
	}
	return 0;
}
