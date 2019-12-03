/*
   given expression -> 30+20-30+40-50
   find expression that would have maximum sum from the given expression
   by using + and - between numbers
   i.e.  30+20+-3+0+40-5+0
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    cin >> input;
    string res = "";
    for(size_t i = 0; i < input.size(); i++)
    {
        res += input[i];
        if(input[i] == '-')
        {
            i++;
            res += input[i];
            i++;
            while(i < input.size() && input[i] == '0')
            {
                res += "+0";
                i++;
            }
            if(i < input.size() && input[i] >= '1' && input[i] <= '9')
            {
                res += "+";
            }
            i--;
        }
    }
    cout << res << endl;
    return 0;
}
