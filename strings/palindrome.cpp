 #include<iostream>

using namespace std;

bool checkPalindrome(char str[]){
    int k = 0;
    while(str[k] != '\0')
    {
        k++;
    }
    int i = 0;
    int j = k - 1;
    while(j > i)
    {
        if(str[i++] != str[j--])
        {
            return false;
        }
    }
    return true;
}
int main()
{
	cout << checkPalindrome("abba") << endl;
	cout << checkPalindrome("abcdcba");
	return 0;
}
