#include <stdio.h>

void sum(int start, int end)
{
	int i = 0;
	int sum = 0;
	int count;
	for (i = start; i <= end; i++)
	{
		sum += i;
	}
	printf("The sum is: %d\n", sum);
}
int main()
{	
	int a,b;
	scanf("%d %d",&a,&b);
	sum(a,b);
	
	return 0;
}
