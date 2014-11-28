#include <stdio.h>
int main()
{

	int x = 20;
	int *y = &x;
	int ** z = &y;
	printf("%d\n",x);
	printf("%d\n",&x);
	printf("%d\n", *y);
	printf("%d\n",&y);
	printf("%d\n",**z );
	printf("%d\n",&z);
}