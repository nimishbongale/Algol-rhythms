#include<stdio.h>
#include<time.h>

int n;

void SimpleMerge(int A[],int low,int mid,int high)
{
	int i=low,j=mid+1,k=low;
	int B[n];
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
	int min,temp,i,j,t,k;
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
	MergeSort(A,0,n-1);
	end=clock();
	
	
	double timetaken=((double)(end-start))/CLOCKS_PER_SEC;
	fprintf(f,"%lf %lf\n",n,timetaken);
	}
	return 0;
}
