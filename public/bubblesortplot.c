/*
Author:- Nimish Bongale
Version 1.0.1
Date:- 13/2/19
A program which sorts an array using selection sort*/

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

			for(j=0;j<n-i-1;j++)

			{

				if(A[j]>A[j+1])

				{

					temp=A[j];

					A[j]=A[j+1];

					A[j+1]=temp;

				}

			}

		}
			end=clock();
	x=n;
	y=(double)(end-start)/CLOCKS_PER_SEC;
	fprintf(f,"%lf %lf\n",x,y);
}
	
	
	fclose(f);
	return 0;
}
