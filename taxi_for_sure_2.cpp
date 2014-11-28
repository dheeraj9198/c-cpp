#include <stdio.h>
#include <iostream>
#include <map>
static long win = 0;
static long MODULO = 1000000007 ;

long multiply(long a,long b)
{
	long temp;
	if(a < b)
	{
		temp = b;
		b = a;
		a=temp;
	}


long res=0;
while(b != 0) // Iterate the loop till b==0
{
if (b&01) // Bitwise & of the value of b with 01
{
res=res+a; // Add a to result if b is odd .
}
a<<=1; // Left shifting the value contained in 'a' by 1
// multiplies a by 2 for each loop
b>>=1; // Right shifting the value contained in 'b' by 1.
}

}

void recursion(long dexter,long mandark,long test,long Mfactor,long Nrounds)
{
	if((dexter+mandark) == Nrounds)
	{
		if(dexter > mandark)
		{
			win = (win +1)%MODULO;
			return;
		}
	}

	if(dexter >= test+Mfactor)
	{
		recursion(dexter+1,mandark,test,Mfactor,Nrounds);
		recursion(dexter,mandark+1,test+Mfactor,Mfactor,Nrounds);
	}else{
		recursion(dexter+1,mandark,test,Mfactor,Nrounds);
	}
}

int main()
{
	long mandark = 0;
	long dexter = 0;

	int testCases;
	scanf("%d",&testCases);

	long roundM,factorM;
	/*
	int Nrounds[testCases];
	int Mfactor[testCases];
	*/
	for(int x=0;x<testCases;x++)
	{
			win =0;
			mandark = 0;
			dexter =0;
			scanf("%ld",&roundM);
			scanf("%ld",&factorM);
			recursion(dexter,mandark,0,factorM,roundM);
			printf("%ld\n",win );
	}

/*
	for(int x =0;x<testCases;x++)
	{
		win = 0;
		mandark = 0;
		dexter =0;
		recursion(dexter,mandark,Mfactor[x],Nrounds[x]);
		printf("%d\n",win );
	}
	*/



}

