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

int getCodes1(string input, string output[])
{
    if(input.length() == 1)
    {
        output[0] = getstring(input.substr(0,1));
        return 1;
    }
    // recursive step.
    int ans = getCodes(input.substr(1), output);

    char ch = getstring(input.substr(0,1));
    for(int i = 0; i < ans; i++)
    {
        output[i] = ch + output[i];
    }
    if(input.length() > 2)
    {
        string second = input.substr(1,2);
    	if(atoi(second.c_str()) >=1 && atoi(second.c_str()) <= 26)
    	{
    		char twolength = getstring(input.substr(1,2));
    		output[ans] = twolength;
            output[ans] = ch + output[ans];
    		for(int i = 3; i < input.length(); i++)
    		{
    			output[ans] += getstring(input.substr(i,1));
    		}
    		return ans+1;
    	}
    }
    return ans;
}

int getCodes2(string input, string output[], int index)
{
    if(input.length() == 2)
    {
        output[index] = getstring(input.substr(0,2));
        return 1;
    }
    // recursive step.
    int ans = getCodes2(input.substr(1), output, index);

    char ch = getstring(input.substr(0,2));
    for(int i = 0; i < ans; i++)
    {

        output[i] = ch + output[i];
    }
    if(input.length() > 3)
    {
        string second = input.substr(2,2);
    	if(atoi(second.c_str()) >=1 && atoi(second.c_str()) <= 26)
    	{
    		char twolength = getstring(input.substr(1,2));
    		output[ans] = twolength;
            output[ans] = ch + output[ans];
    		for(int i = 3; i < input.length(); i++)
    		{
    			output[ans] += getstring(input.substr(i,1));
    		}
    		return ans+1;
    	}
    }
    return ans;
}

int main()
{
    string input;
    cin >> input;
    string output[10000];
    int ans1 = getCodes1(input, output);
    int ans2 = 0;
    if(input.length() >= 2)
    {
        string check = getstring(input.substr(0,2));
        if(atoi(check.c_str()) >= 1 && atoi(check.c_str()) <= 26)
        {
            ans2 = getCodes2(input, output, ans1);
        }
    }
    int ans = ans1 + ans2;
    cout << ans << endl;
    for(int i = 0; i < ans1; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
