#include <iostream>
#include <stdio.h> 
using namespace std;

int findMinWindow(char sub[],char parent[],int ls,int lp)
	{
	cout << "searching " << sub << " in " << parent << endl;	
	int x,y;
	x=y=0;
	bool matchStart = false;
	int len = 0;
	int temp = -1;
	while(x<lp)
	{
		if(sub[y] == parent[x])
		{

			y++;
		}

	if(x > 0 && (parent[x] == sub[0]))
	{
			int newTemp = findMinWindow(sub,parent+x,ls,lp-x);	
			if(temp == -1)
			{
				temp = newTemp;
			}else{
				temp = min(temp,newTemp);
			}
	}

		if(y > 0)
		{
			len++;
		}

		if(y == ls)
		{
			cout << "returning nor " << len <<endl;
			return min(temp,len);
		}
		x++;
	}

cout << "returning -1 " <<endl;
return -1;

}

main() { 
    char sub[]="anna";
    char parent[]="annabancxna";
 
    int sSub = sizeof(sub)/sizeof(sub[0]) - 1;
    int sParent = sizeof(parent)/sizeof(parent[0]) -1;

    cout << sSub << "*" << sParent << endl;
   	int found;
 	found = findMinWindow(sub,parent,sSub,sParent);
 	if(found > 0)
 		cout << "found length " << found;
 	else
 		cout << "not found";
 }