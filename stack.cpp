#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;
int main()
{
	stack<int> myStack;
	myStack.push(1);
		myStack.push(1);

	myStack.push(2);
	myStack.push(3);
	myStack.push(4);

	while(!myStack.empty())
	{
		cout << myStack.top() << endl;
		myStack.pop();
}



}