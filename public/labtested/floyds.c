#include<stdio.h>

#define min(a,b) (a<b)?a:b

void floyd(int d[50][50],int n)
{
int i,j,k;
for(k=0;k<n;k++)
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
   d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}

int main()
{
 int d[50][50],i,j,n;//d = weighted cost adjacency matrix (could be visualised as distances from point to point)
 printf("Enter the number of vertices:\n");
 scanf("%d",&n);//n = no. of vertices
 printf("Enter the cost adjacency matrix:\n");
 for(i=0;i<n;i++)
 for(j=0;j<n;j++)
 scanf("%d",&d[i][j]);
 floyd(d,n);
 printf("The minimum distance matrix is:\n");
 for(i=0;i<n;i++)
	{
  		for(j=0;j<n;j++)
   			printf("%d \t",d[i][j]);
		printf("\n");
	}
	return 0;
}
