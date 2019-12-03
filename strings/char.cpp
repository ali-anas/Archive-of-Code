#include <iostream>

using namespace std;

int main(){
	char input[10];
	int i;
	cin >> input;
	/*
	cout << input+1<<endl;
	for(i = 2; input[i] != '\0'; i++)
	{
		input[i+2] = input[i];
	}
	input[i] = '\0';
	input[0]='3';
	input[1]='.';
	input[2] = '1';
	input[3] = '4';
	cout << input << endl;
	*/
	int length = 0;
	for(char ch: input)
		++length;
	cout << length << endl;
	return 0;
}
