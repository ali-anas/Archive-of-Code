/*                   num        rem
                    abc<--23 -->def
                        /  |    \
                      /    |     \
                    /      |       \
                 2 , d     2, e    2, f  rem[]
            /    |   \
           /     |    \
         /       |      \
       0,"ad"   0,"bd"   0,"cd"
*/

#include <iostream>
#include <string>

using namespace std;

int printKeypadCode(int num, string output, string sequence[])
{
    if(num == 0)
    {
        cout << output << endl;
        return 1;
    }
    int rem = num % 10;
    int smallInput = num/10;
    string option = sequence[rem];
    int ans = 0;
    for(int i = 0; i < option.length(); i++)
    {
        int smallOutput = printKeypadCode(smallInput, option[i]+output, sequence);
        ans += smallOutput;
    }
    return ans;
}

int main()
{
    string output = "";
    int num;
    cin >> num;
    string sequence[] = {"" ,"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    cout << printKeypadCode(num, output, sequence) << endl;
    return 0;
}
