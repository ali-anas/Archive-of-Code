#include <iostream>
using namespace std;

int findlength(string str)
{
    if(str.length()==0)
        return 0;
    int freq[256],i;
    for(i= 0; i < 255; i++)
    {
        freq[i] = 0;
    }
    int count = 0;
    i = 0;
    for(char ch: str)
    {
        freq[int(ch)]++;
    }
    for(i = 65; i <= 90; i++)
    {
        count += freq[i];
    }
    return count+1;
}


int main() {
	int t;
	cin >> t;
	while(t>0)
	{
	    string str;
	    cin >> str;
	    cout << findlength(str)<< "\n";
	    t--;
	}
	return 0;
}
