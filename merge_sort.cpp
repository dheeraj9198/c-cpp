#include <iostream>
#include <stdio.h>
using namespace std;
void mergeSort(int array[],int length);
void merge(int arr1[],int length1,int arr2[],int length2,int temp[]);

int main()
{
	int array[] = {10,9,8,7,6,5,4,3,2,1,0};
	int length = sizeof(array)/sizeof(array[0]);
	mergeSort(array,length);
	for(int i = 0;i<length;i++)
		printf("%d ", array[i]);	
	return 0;
}


void mergeSort(int array[],int length)
{
	if(length > 1)
	{
	int temp[length];
	int mid = (length)/2;
	mergeSort(array,mid);
	mergeSort(array+mid,length-mid);
	merge(array,mid,array+mid,length-mid,temp);
	for(int x = 0;x<length;x++)
	{
		array[x] = temp[x];
	}
	}
}

void merge(int arr1[],int length1,int arr2[],int length2,int temp[])
{
	int i =0;
	int j = 0;
	int k = 0;
	while(i < length1 && j < length2)
	{
		if(arr1[i] < arr2[j])
		{
			temp[k] = arr1[i];
			k++;
			i++;

		}	else{

			temp[k] = arr2[j];
			k++;
			j++;
		}

	}

	while(i < length1)
	{
		temp[k] = arr1[i];
		k++;i++;
	}

	while(j < length2)
	{
		temp[k] = arr2[j];
		k++;j++;
	}

}