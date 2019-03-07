/*
Author:- Nimish Bongale
Version 1.0.3
Date:- 22/2/19
A program which sorts an array using quick sort*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

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
	int i,n,t,k;
	clock_t start,end;
	FILE *f=fopen("file.txt","w");
	printf("Enter the no. of trial runs:-");
	scanf("%d",&t);
	for(k=1;k<=t;k++){
	printf("Enter the no. of elements for testrun %d:- ",k);
	scanf("%d",&n);
	
	int A[n];

	for(i=0;i<n;i++)
	A[i]=rand()%100;
	
	start=clock();
	QuickSort(A,0,n-1);
	end=clock();
	
	
	double timetaken=((double)(end-start))/CLOCKS_PER_SEC;
	/*for(i=0;i<n;i++)
	printf("%d\n",A[i]);*/
	fprintf(f,"%f %lf\n",(double)n,timetaken);
	//printf("\n%f",timetaken);
	}
	return 0;
}
