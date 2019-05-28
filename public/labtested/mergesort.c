/*
Author:- Nimish Bongale
Version 1.0.2
Date:- 22/2/19
A program which sorts an array using merge sort*/

#include<stdio.h>
#include<time.h>

#define size 100000

void SimpleMerge(int A[],int low,int mid,int high)
{
	int i=low,j=mid+1,k=low;
	int B[size];
	while((i<=mid)&&(j<=high))
	{
		if(A[i]<A[j])
		B[k++]=A[i++];
		else
		B[k++]=A[j++];
	}
	
	while(j<=high)
	B[k++]=A[j++];
	while(i<=mid)
	B[k++]=A[i++];
		
	for(i=low;i<=high;i++)
	A[i]=B[i];
}

void MergeSort(int A[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		MergeSort(A,low,mid);
		MergeSort(A,mid+1,high);
		SimpleMerge(A,low,mid,high);
	}
}

int main()
{
	int min,temp,i,j,k;
	clock_t start,end;
	
	double y;

	int A[size];
	
	for(i=0;i<size;i++)
	A[i]=rand();
	
	start=clock();
	MergeSort(A,0,size-1);
	end=clock();
	
	/*for(i=0;i<size;i++)
	printf("%d \n",A[i]);*/
	
	y=(double)(((double)(end-start))/(double)(CLOCKS_PER_SEC));
	printf("Time required = %lf",y);
	
	return 0;
}
