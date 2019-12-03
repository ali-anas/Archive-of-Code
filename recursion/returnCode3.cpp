// SOLVED SUCCESSFULLY UNTIL '22222222222222'

#include <iostream>

using namespace std;

char getString(int i)
{
    char ans = i + 'a' - 1;
    return ans;
}

int getNumberOfStrings(string input, string output[],int index)
{
    if(input.length() == 0)
    {
        output[index] += "";
        return 1;
    }
    if(input.length() == 1)
    {
        output[index] = getString(input[0] - '0');
        return 1;
    }
    string out1[1000];
    int firstDigit = input[0]-'0';
    int smallAns1 = getNumberOfStrings(input.substr(1), out1, index);
    //index = index + smallAns1;
    //cout << "index + smallans1 : " << index << endl;
    int smallAns2 = 0;
    int firstTwoDigits = 0;
    string out2[1000];
    if(input.length() >= 2)
    {
        firstTwoDigits = ((input[0] - '0') * 10 + (input[1] - '0'));
        //cout << firstTwoDigits << endl;
        if(firstTwoDigits >= 10 && firstTwoDigits <= 26)
        {
            smallAns2 = getNumberOfStrings(input.substr(2), out2, index);
        }
    }
    int ans = smallAns1 + smallAns2;
    int k = 0;/*
    for(int i = 0; i < smallAns1; i++)
    {
        cout << out1[i] << endl;
    }
    for(int i = 0; i < smallAns2; i++)
    {
        cout << out2[i] << endl;
    }*/
    //cout << "smallAns1 : " << smallAns1 << "\tsmallAns2 : " << smallAns2 << endl;
    for(int i = 0; i < smallAns1; i++)
    {
        char first = getString(firstDigit);
        output[k] = first + out1[i];
        //cout << output[k] << endl;
        k++;
    }
    for(int i = 0; i < smallAns2; i++)
    {
        char first = getString(firstTwoDigits);
        output[k] = first + out2[i];
        //cout << output[k] << endl;
        k++;
    }
    return k;
}

int main()
{
    string input;
    cin >> input;
    string output[10000];
    int index = 0;
    int numberOfStrings = getNumberOfStrings(input, output, index);
    cout << numberOfStrings << endl;
    for(int i = 0; i < numberOfStrings; i++)
    {
        cout << output[i] << "\n";
    }
    return 0;
}
