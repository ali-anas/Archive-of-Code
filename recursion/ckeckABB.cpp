/*

1. every string should start with 'a'.
2. a can followed a or ''.
3. every b should follwed by another and that can be
   follwed by a or ''.
   i.e  abbaaabb  is valid
        bb  is invalid.
        abbb is invalid.  abb is valid.
*/

#include <iostream>
#include <string>

using namespace std;

bool checkABB(string input, int start, int end)
{
    /*
    if(start == 0 && input[start] != 'a')
    {
        return false;
    }
    if(start == end)
    {
        return true;
    }*/
    if(input.length() == 0)
    {
        return true;
    }
     if(start == 0 && a[start] != 'a'))
    {
        return false;
    }
    if(start == input.length())
    {
        return true;
    }

    bool ans = true;
    int x = 1
    if(input[start] == 'b' && input[start+1] == 'b')
    {
        if(input[start+2] == 'a' || input[start+2] == '')
        {
            ans = true;
            x = start+2;
        }
        else
        {
            ans = false;
            return false;
        }
    }

    bool smallAns = checkABB(input,start + x, end);

    return smallAns&&ans;

}

int main()
{
    string input;
    cin >> input;

    int end = input.length();
    if(checkABB(input, 0, end))
        cout << "true";
    else
        cout << "false";
    return 0;
}
