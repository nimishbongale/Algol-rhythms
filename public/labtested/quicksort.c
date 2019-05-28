/*
Author:- Nimish Bongale
Version 1.0.3
Date:- 22/2/19
A program which sorts an array using quick sort*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define size 100000

void swap(int* a,int* b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int Partition(int A[],int low,int high)
{
	int key=A[low],j=high,i=low+1;
	while(i<=j)
	{
		while(A[i]<=key)i++;
		while(A[j]>key)j--;
		if(i<j)
		swap(&A[i],&A[j]);
	}
	swap(&A[low],&A[j]);
	return j;
}

void QuickSort(int A[],int low,int high)
{
	if(low<=high)
	{
		int pos=Partition(A,low,high);
		QuickSort(A,low,pos-1);
		QuickSort(A,pos+1,high);
	}
}

int main()
{
	int i,t,k;
	clock_t start,end;

	double y;
	
	int A[size];

	for(i=0;i<size;i++)
	A[i]=rand();
	
	start=clock();
	QuickSort(A,0,size-1);
	end=clock();
	
	for(i=0;i<size;i++)
	printf("%d \n",A[i]);
	
	y=(double)((double)(end-start)/(double)CLOCKS_PER_SEC);
	printf("Time required = %lf",y);
	
	return 0;
}
