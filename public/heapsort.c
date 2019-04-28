#include<stdio.h>
#include<time.h>
#include<math.h>

int h[100000];//can be smaller depending on user input 
void heapify(int h[],int n)
{
	int i,j,n1,k,heap,v;
	n1=n;
	for(i=n/2;i>=1;i--)//i = looping variable
	{
	  k=i;//k = current node
	  v=h[k];//v = value of current node 
	  heap=0;//variable to indicate if the formed tree is a heap or not (heap=0 not heap, heap=1 heap)
	  while(!(heap)&&(2*k)<=n1)
	  {
	    j=2*k;//find left child
	    if(j<n1)//If index position of left child is smaller than total nodes
	     if(h[j]<h[j+1])//If right child is greater
	       j=j+1;//go to right child
	   
	   if(v>=h[j])//If the value of the source node is greater than the child
	       heap=1;//still a heap
	   else 
	   {
	    h[k]=h[j];/*Now that it is not a heap, we have to make it a heap
	    Now source is the max element h[j]*/
	    k=j;//Source node index changes, becomes j now
	   }
	  }
	h[k]=v;//the value of the element in the source node (ie. max element) is put in kth index (where the max element was previously)
 }
}


int main()
{
 int i,n,size,t;
 clock_t start,end;
 printf("Enter the value of n \n");
 scanf("%d",&n);// n = no. of elements
 /*printf("Enter the array elements \n");
 for(i=1;i<=n;i++)
  scanf("%d",&h[i]);//h[] stores the elements*/
	for(i=1;i<=n;i++)
  h[i]=rand()%1000;//h[] stores the elements*/
    
  heapify(h,n);
  printf("Elements heapified \n");
  for(i=1;i<=n;i++)
   printf("%d \t",h[i]);//h[] now stores max heap
   start=clock();
  for(i=n;i>=1;i--)
  {
   t=h[1];
   h[1]=h[i];
   h[i]=t;//by this swap, the greatest element(which was at the beginning) comes to the end.
   size=i-1;//reduce the size of heap by 1
    heapify(h,size);
  }
  end=clock();
  
 printf("Sorted array \n");
 for(i=1;i<=n;i++)
  printf("%d \t",h[i]);
  
  printf("Time taken: %lf",(double)(((double)(end-start))/(double)CLOCKS_PER_SEC));
  return 0;
}
