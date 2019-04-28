#include<stdio.h>

//#define max(a,b) (a>b)?a:b

int max (int a,int b)
{
 if (a>b)
 return a;
 else
 return b;
}

void knapsack(int m,int n,int w[],int p[])
{
	int v[100][200],x[10],i,j,sum=0;
	for(i=0;i<=n;i++)
		v[i][0]=0;//first column all elements=0
	for(j=0;j<=m;j++)
		v[0][j]=0;//first row all elements=0
	
	/*Here, we assume all the given item weights are always lesser than the max capacity of the sack, and therefore j (along knapsack capacity)
	can be subtracted with w[i] ie. j-w[i]
	We dont have to subtract and compare for each step. Only when a new item can be accomodated (ie. when the current leftover capacity can fit
	w[i])*/
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(j>=w[i])
				v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
			else
				v[i][j]=v[i-1][j];
	
	for(i=1;i<=n;i++)
	x[i]=0;
	//x[] is a binary array to store if the item will be taken or not (0->not taken, 1->taken)
	i=n;
	j=m;
	
	while(i>0 && j>0)
	{
 		if(v[i][j]!=v[i-1][j])
		{
			x[i]=1;//taken, because the previous value isn't carried over 
			j=j-w[i];//subtract the weight of current item from capacity.
		}
		i--;
	}
	printf("\n The optimal set of items are :\n");
	for(i=1;i<=n;i++)
	{
		if(x[i]==1)
		{
			printf("%d \t ",i);
			sum=sum+p[i];//add all sums to print the net profit
		}
	}
	printf("\n total profit is %d",sum);
}

int main()
{
	int w[10],p[10],m,n,j,i;
	printf("Enter the number of items:");
	scanf("%d",&n);//n = no. of items
	printf("Enter the weights of the items:\n ");
	for(i=1;i<=n;i++)
	scanf("%d",&w[i]);//w[] = weights 
	printf("Enter profit of items: \n");
	for(i=1;i<=n;i++)
	scanf("%d",&p[i]);//p[] = profits of individual items
	printf("Enter capacity: \n");
	scanf("%d",&m);//m = capacity
	knapsack(m,n,w,p);
	return 0;
}
