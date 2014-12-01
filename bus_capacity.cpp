#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
int main()
{
	int arr[] = {2,3,4,5};
	int group = 4;
	int capacity = 7;
	int rounds = 4;

	int money = 0;

	queue<int> myq;

	for(int x =0;x<group;x++)
	{
		myq.push(arr[x]);
	}

	for(int y =0 ;y<rounds;y++)
	{
		int temp = 0;
		while(temp + myq.front() <= capacity)
		{
			money = money + myq.front();
			temp = temp + myq.front();
			myq.push(myq.front());
			myq.pop();
		}

	}

	cout << "money earned = " << money << endl;

}
