/*
Author:- Nimish Bongale
Version 1.0.1
Date:- 13/2/19
A program which sorts an array using bubble sort*/

#include<stdio.h>
#include<time.h>

#define size 100000

int main()
{
	int min,temp,i,j;
	clock_t start,end;
	
	double y;

	int A[size];
	
	for(i=0;i<size;i++)
	A[i]=rand();
	
	start=clock();
	for(i=0;i<size;i++)
		{
			for(j=0;j<size-i-1;j++)
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
	
	/*for(i=0;i<size;i++)
	printf("%d \n",A[i]);*/
	
	y=(double)(((double)end-start)/(double)CLOCKS_PER_SEC);
	printf("Time required = %lf",y);

	return 0;
}
