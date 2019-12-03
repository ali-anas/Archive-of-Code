/*
 In this problem we just have to print the possible
 subsequences of the string.
 So i do not take output[] array of strings,
 instead i just take just a singlt output strings
                 "ab"
                 /  \
            i  o/    \i   o
            "b" ""   "b" "a"
            /  \          /  \
           /    \        /    \i    o
        "" ""  "" "b"  "" "a"  "" "ab"
*/
#include <iostream>

using namespace std;

int printSubsequences(string input, string output)
{
    if(input == "")  // input.length() == 0
    {
        cout << output << endl;
        return 1;
    }
    //string smallInput = input.substr(1);
    //string nextOutput = output + input[0];
    int smallAns1 = printSubsequences(input.substr(1), output);
    int smallAns2 = printSubsequences(input.substr(1), output+input[0]);
    return smallAns1+smallAns2;

}

int main()
{
    string input = "";
    cin >> input;
    string output = "";
    cout << printSubsequences(input, output) << "\n";

    return 0;
}
