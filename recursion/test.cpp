#include <iostream>
#include <string>

using namespace std;

char getstring(string s)
{
	int len = s.length();
	int i = atoi(s.c_str());
	char ans = i + 'a'-1;
	s = "";
	s += ans;
	cout << s << endl;
	return s[0];
}

int main()
{
	int input;
	cin>> input;
	/*
	string output = "abc";
	cout << "int input[0] : " << ((input[0] - '0') *10 + (input[1] - '0'))<< endl;
	char ch = getstring(input.substr(0,2));
	output = ch + output;
	cout << "output : "  << output << endl;
	string output2 = "2";
	for(int i = 0; i < input.length(); i++)
	{
		output2 += getstring(input.substr(i,1));
	}
	cout << output2 << endl;
	*/

	if(input>5)
		cout <<">5" <<endl;
	if(input <10)
		cout << "<10"<<endl;
	else
		cout <<"<5"<<endl;

	return 0;
}
