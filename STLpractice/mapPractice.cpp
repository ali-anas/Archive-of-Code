#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

/*
 * <map> - implemented in balanced BST.
 * 		- takes O(log n) time for average &
 *		  worst case.
 * <unordered_map> - implemented with hash-tables
 * 		- takes O(1) in average case.
 *		- takes O(n) in worst case.
 */

using namespace std;

int main()
{
	map<string,double> marks;
	/*string stName;
	double stMarks;
	while(true)
	{
		cout << "Give name of student : ";
		cin >> stName;
		if(stName == "end")
		{
			cout << "Bye!!!" << endl;
			break;
		}
		else
		{
			cout << "Give marks : ";
			cin >> stMarks;
			marks[stName] = stMarks;
			cout << "\n";
		}
	}
	while(true)
	{
		cout << "enter name of student : ";
		cin >> stName;
		if(stName == "end")
		{
			cout << "Bye!!!" << endl;
			break;
		}
		else
		{
			cout << "marks of " << stName << " is : " << marks.at(stName) << endl;
		}
	}*/
	marks["ajanta"] = 10.0;
	marks["bobby"] = 11.0;
	marks["abdul"] = 12.0;

	map<string, double>::iterator it;
	for(it = marks.begin(); it != marks.end(); it++)
	{
		cout << it -> first << " : " << it -> second << endl;
	}

	map<string, double>::reverse_iterator rit;
	cout << "\nreverse :" << endl;
	for(rit = marks.rbegin(); rit != marks.rend(); rit++)
	{
		cout << rit -> first << " : " << rit -> second << endl;
	}
	cout << "marks at abdul : " << marks.at("abdul") << endl;

	/*// finding if an element exist in map : using count
	if(marks.count("bobby") > 0)
	{
		cout << "marks at bobby : " << marks.at("bobby") << endl;
	}
	if(marks.count("boby") > 0)
	{
		cout << "marks at boby : " << marks.at("boby") << endl;
	}

	// finding if an element exists in map : using iterator
	string stName;
	cin >> stName;
	it = marks.find(stName);
	if(it != marks.end())
	{
		cout << "Marks : " << it -> second << endl;
	}
	else
	{
		cout << "no student with name : " << stName << endl;
	}
	*/

	// deleting elements from map.
	cout << marks.size() << endl;
	marks.erase("bobby");
	cout << marks.size() << endl;
	it = marks.find("abdul");
	marks.erase(it);
	cout << marks.size() << endl;

	//cout << marks[] << endl;
	
	map<char,int> charToInt;
	cout << charToInt.size() << endl;
	cout << charToInt['A'] << endl;
	cout << charToInt.size() << endl;

	// modifiers

	charToInt.insert(pair<char,int>('C', 400));
	cout << charToInt.size() << endl;

	return 0;
}
