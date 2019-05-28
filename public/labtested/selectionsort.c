/*
Author:- Nimish Bongale
Version 1.0.2
Date:- 22/2/19
A program which sorts an array using selection sort*/

#include<stdio.h>
#include<time.h>

#define size 100000

int main()
{
	int min,temp,i,j,k;
	clock_t start,end;
	
	double y;
	
	int A[size];
	    
	for(i=0;i<size;i++)
	A[i]=rand();
	
	start=clock();
	for(i=0;i<size;i++)
	{
		min=i;
		for(j=i+1;j<size;j++)
		if(A[j]<A[min])
		min=j;
		
		temp=A[i];
		A[i]=A[min];
		A[min]=temp;
	}
	end=clock();
	
	/*for(i=0;i<size;i++)
	printf("%d \n",A[i]);*/
	
	y=(double)((double)(end-start)/(double)CLOCKS_PER_SEC);
	printf("Time required = %lf",y);
	return 0;
}
	

