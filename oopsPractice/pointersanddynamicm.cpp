#include <iostream>
using namespace std;

int *readquizmarks(int n);

int main()
{
	int numberofstudents;
	int *qmarks;
	cout << "Give student count : ";
	cin>> numberofstudents;
	cout << "Give marks of students" << endl;
	qmarks = readquizmarks(numberofstudents);
	for(int i = 0; i < numberofstudents; i++)
	{
		cout << qmarks[i] << " " ;
	}  
	cout << endl;
	return 0;
}

int *readquizmarks(int n)
{
	int *marks;
	marks = new int[n];
	if(marks == NULL)
		return NULL;
	 for(int i = 0; i < n; i++)
		 cin >> marks[i];
	 return marks;
}
