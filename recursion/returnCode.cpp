/*
 1 1 2 3
 | |
 1
 a
 */

#include <iostream>
#include <string>

using namespace std;

char getstring(string s)
{
	//int len = s.length();
	int i = atoi(s.c_str());
	char ans = i + 'a'-1;
	s = "";
	s += ans;
	return s[0];
}

int getCodes(string input, string output[])
{
	if(input.length() == 1)
	{
		output[0] = getstring(input.substr(0,1));
		return 1;
	}
	// recursive call
	int ans = getCodes(input.substr(1), output);

	char ch = getstring(input.substr(0,1));

	for(int i = 0; i < ans; i++)
	{
		output[i] = ch + output[i];
	}
	string second = input.substr(0,2);
	if(atoi(second.c_str()) >=1 && atoi(second.c_str()) <= 26)
	{
		char twolength = getstring(input.substr(0,2));
		output[ans] = twolength;
		for(int i = 2; i < input.length(); i++)
		{
			output[ans] += getstring(input.substr(i,1));
		}
		return ans+1;
	}
	return ans;
}

int getCodesForTwo(string input, string output[], int index)
{
	if(input.length() == 2)
	{
		string second = input.substr(0,2);
		if(atoi(second.c_str()) >=10 && atoi(second.c_str()) <= 26)
		{
			char twolength = getstring(input.substr(0,2));
			output[index] += twolength;
			return 1;
		}
		return 0;
	}

	string second = input.substr(0,2);
	if(atoi(second.c_str()) >=1 && atoi(second.c_str()) <= 26)
	{
		char twolength = getstring(input.substr(0,2));
		output[index] += twolength;
	}
	else
	{
		return 0;
	}

	// recursive call
	int ans = getCodesForTwo(input.substr(2), output, index);


	return 1;
}


int main()
{
	string input;
	cin >> input;
	string output[10000];
	int ans1 = getCodes(input, output);
	int ans2 = 0;
	if(input.length() > 2 && (input.length())%2 == 0)
	{
		ans2 = getCodesForTwo(input, output, ans1);
	}
	int ans = ans1+ans2;
	cout << ans <<endl;
	for(int i = 0; i < ans; i++)
	{
		cout << output[i] << "\n";
	}
    return 0;
}
