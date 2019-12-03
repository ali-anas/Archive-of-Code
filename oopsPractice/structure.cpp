#include <iostream>
using namespace std;

struct driver{
	string name;
	int id;
};

struct linkedtaxi{
	int id;
	driver *drv;
	linkedtaxi *next;
};

struct queue{
	linkedtaxi *front, *end;
	int numtaxis;
};

joinqueue()
{
	driver *newdrv;
	newdrv = new driver;
	if(newdrv = NULL)
	{
		cout << "Memory allocation failure" << endl;
		return -1;
	}
	cout << "Give name of driver : ";
        cin >> newdrv->name;
	cout << "Give id of driver : ";
	cin >> newdrv->id;
	linkedtaxi *newtaxi;
	newtaxi = new linkedtaxi;
	if(newtaxi == NULL)
	{
		"Memory allocation failure"<<endl;
		return -1;
	}
	newtaxi->drv = newdrv;
	newtaxi->next = NULL;
	cout << "Give id of taxi : ";
	cin >> newtaxi -> id;
	if(q.end == NULL)
	{
		q.front = newtaxi;
		q.end = newtaxi;
		q.numtaxis++;
	}
	else
	{
		(q.end) -> next = newtaxi;
		q.end = newtaxi;
		q.numtaxis++;
	}
}

int main()
{
	queue q;
	q.front = NULL;
	q.end = NULL;
	q.numtaxis = 0;
	while(true)
	{
		cout << " command : 'j' to join queue, 'd' to dispatch, 'x' to exit." << endl;
		char command;
		cin >> command;
		switch(command)
		{
			case 'j': joinqueue();
				break;
			case 'd': dispatch();
				break;
			case 'x': cout << "Thank you" << endl;
				  return 0;
			default : cout << "Invalid command." << endl;
		}
	}
	return 0;
}
