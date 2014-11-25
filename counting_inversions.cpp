/**
*array sorting needed to verify if first arrays n'th element is greater than sencond arrays
*some element then all elements following n will do the same
*/
#include<stdio.h>
#include<iostream>
using namespace std;
int countInversions(int array[],int size);
int merge(int arr1[],int size1,int arr2[],int size2,int[]);
int main()
{
	int array[] = {2, 4, 1, 3, 5};
	int size = sizeof(array) / sizeof(array[0]);
	int x = countInversions(array,size);
	printf("number of inversions = %d",x);
}

int countInversions(int array[],int size)
{
	if(size > 1 )
	{
	int mid = size / 2;
	int count1 = countInversions(array,mid);
	int count2 = countInversions(array+mid,size-mid);
	int temp[size];
	int count3 = merge(array,mid,array+mid,size-mid,temp);
	for(int x =0;x<size ;x++)
	{
		array[x] = temp[x];
	}
	return count1 + count2 + count3;
	}else{
		return 0;
	}
}

int merge(int arr1[],int size1,int arr2[],int size2,int temp[])
{
	int count  = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	while(a < size1 && b < size2)
	{
		if(arr1[a] < arr2[b])
		{
			temp[c] = arr1[a];
			c++;
			a++;
		}else{
			temp[c] = arr2[b];
			b++;
			c++;
			count = count + size1 -a;
		}
	}

	while(a < size1)
	{
		temp[c] = arr1[a];
		c++;a++;
	}

while(b < size2)
	{
		temp[c] = arr2[b];
		c++;b++;
	}

	return count;
}
