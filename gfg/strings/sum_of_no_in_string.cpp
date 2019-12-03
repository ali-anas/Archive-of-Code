#include <iostream>
#include <string>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t>0)
	{
	    string str;
	    cin >> str;
	    int i = 0;
	    int sum = 0;
	    int size = str.length();

	    while(i < size)
	    {
	        int num = 0;
	        if(isdigit(str[i]))
	        {
	            while(isdigit(str[i]) && i < size)
	            {
	                num = num * 10 + (int(str[i]) - 48);
	                i++;
	            }
	            sum = sum + num;
	        }
		    else
			{
				i++;
			}
	    }
	    cout << sum<< "\n";
	    t--;
	}
	return 0;
}
