#include<stdio.h>

void swap1(double *a, double *b)
{
   double t;
   t  = *b;
   *b = *a;
   *a = t;
}

void swap2(int *a, int *b)
{
   int t;
   t  = *b;
   *b = *a;
   *a = t;
}

int main()
{
	int item,cap,i,j,sum=0;
	printf("Enter the no. of items:");
	scanf("%d",&item);
	printf("\nEnter the capacity of knapsack:");
	scanf("%d",&cap);
	int curcap=cap;
	int weight[item],value[item];
	
	printf("\nEnter the weights:\n");
	for(i=0;i<item;i++)
	scanf("%d",&weight[i]);
	
	printf("\nEnter the values:\n");
	for(i=0;i<item;i++)
	scanf("%d",&value[i]);
	
	double networth[item];
	
	for(i=0;i<item;i++)
	networth[i]=((double)value[i])/((double)weight[i]);
	
	
	for(i=0;i<item;i++)
		for(j=0;j<item-1-i;j++)
			if(networth[j]<=networth[j+1])
			{
				swap1(&networth[j],&networth[j+1]);
				swap2(&weight[j],&weight[j+1]);
				swap2(&value[j],&value[j+1]);
			}
	
	for(i=0;i<item;i++)
	{
		if(weight[i]<=curcap)
		{
			printf("\n%d weight with value %d",weight[i],value[i]);
			curcap-=weight[i];
			sum+=value[i];
		}
	}
	printf("\nTotal profit=%d",sum);
	return 0;
}
