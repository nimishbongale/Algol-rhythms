#include<stdio.h>
#include<time.h>

int main()
{
	FILE *f=fopen("file.txt","w");
	int n,min,temp,i,j,k,testrun;
	clock_t start,end;
	printf("Enter the no. of test runs: ");
	scanf("%d",&testrun);
	double x,y;
	for(k=0;k<testrun;k++){
	printf("Enter the no. of elements for testrun %d: ",(k+1));
	scanf("%d",&n);
	int A[n];
	
	for(i=0;i<n;i++)
	A[i]=rand();
	
	start=clock();
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		if(A[j]<A[min])
		min=j;
		
		temp=A[i];
		A[i]=A[min];
		A[min]=temp;
	}
	end=clock();
	x=n;
	y=(double)(end-start)/CLOCKS_PER_SEC;
	fprintf(f,"%lf %lf\n",x,y);
}
	
	
	fclose(f);
	return 0;
}
