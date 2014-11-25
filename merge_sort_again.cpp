#include<stdio.h>
#include<iostream>
using namespace std;
void mergeSort(int array[],int size);
void merge(int arr1[],int size1,int arr2[],int size2,int temp[]);

int main()
{
	int array[] = {10,9,8,7,6,5,4,3,2,1,0};
	int size = sizeof(array)/sizeof(array[0]);

	mergeSort(array,size);

	for(int x = 0 ;x<size;x++)
	{
		printf("%d ",array[x]);
	}
	return 0 ;
}

void mergeSort(int array[],int size)
{
	if(size == 1)
	{
		return;
	}
	int temp[size];
	int mid = size/2;
	mergeSort(array,mid);
	mergeSort(array+mid,size-mid);
	merge(array,mid,array+mid,size-mid,temp);
	for(int x= 0 ;x< size;x++)
	{
		array[x] = temp[x];
	}
}

void merge(int arr1[],int size1,int arr2[],int size2,int temp[])
{
	int a=0;
	int b=0;
	int c=0;
	while(a < size1 && b < size2)
	{
		if(arr1[a] < arr2[b])
		{
			temp[c] = arr1[a];
			a++;
			c++;
		}else{
			temp[c] = arr2[b];
			b++;
			c++;
		}
	}

	while(a<size1)
	{
		temp[c] = arr1[a];
		c++;
		a++;
	}

	while(b<size2)
	{
		temp[c] = arr2[b];
		c++;
		b++;
	}

}





