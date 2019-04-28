#include<stdio.h>

void warshall(int r[10][10],int n)
{
	int i,j,k;//assume n=4
	for(k=0;k<n;k++)//k runs 4 times (row & column number every step)
	 for(i=0;i<n;i++)//i runs k*i times, 16 times
	  for(j=0;j<n;j++)//j runs k*i*j 64 times
	   r[i][j]=(r[i][j]|r[i][k]&r[k][j]); /*C[i][j]+=A[i][k]*B[k][j] equivalent (+ = |, * = &)
	   entire line could be replaced by r[i][j]=((r[i][j]+r[i][k]*r[k][j])>0)?1:0;*/
}

int main()
{
	int r[10][10],i,j,n;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	
	printf("Enter adjacency matrix \n");
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	scanf("%d",&r[i][j]);
	
	warshall(r,n);
	
	printf("Transitive closure is:\n");
	for(i=0;i<n;i++)
	{
	  for(j=0;j<n;j++)
		  printf("%d \t",r[i][j]);
	  printf("\n");
	}
	return 0;
}
