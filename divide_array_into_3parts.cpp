#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
int maximum(int x, int y, int z) {
	int max = x; /* assume x is the largest */

	if (y > max) { /* if y is larger than max, assign y to max */
		max = y;
	} /* end if */

	if (z > max) { /* if z is larger than max, assign z to max */
		max = z;
	} /* end if */

	return max; /* max is the largest value */
} 

int main()
{
	int array[] = {97,98,1,98};
	int size = sizeof(array)/sizeof(array[0]);
	int part1=0;
	int part2=0;
	int part3=0;

	sort(array,array+size,greater<int>());
	for(int x=0;x<size;x++)
	{
		if( part1 < part2 && part1 < part3)
		{
			part1 +=array[x];
		}else if(part2 < part3){
			part2 +=array[x];
		}else{
			part3 +=array[x];
		}
	}

	printf("first part1 = %d\n",part1 );
	printf("first part2 = %d\n",part2 );
	printf("first part3 = %d\n",part3 );

	printf("-------------------------------\n");
	printf("largest number = %d\n",maximum(part1,part2,part3));
}