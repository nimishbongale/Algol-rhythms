#include<stdio.h>

int main()
{
	int a,b,u,v,n,i,j,ne=1,source;
	int visited[20]={0},min,mincost=0,cost[20][20];
	
	printf("Enter the number of nodes\n");
 	scanf("%d",&n);//n = number of nodes
 	printf("Enter the cost matrix\n");
 	for(i=1;i<=n;i++)
  		for(j=1;j<=n;j++)
  		{
   			scanf("%d",&cost[i][j]);//input for cost matrix
   			if(cost[i][j]==0)
    			cost[i][j]=999;
 		}
 	printf("Enter the source node\n");
 	scanf("%d",&source);//source = source node
 	visited[source]=1;//visited[] stores all the visited nodes (1->visited, 0->non visited)
	while(ne<n)//ne is initially 1
	{
	  for(i=1,min=999;i<=n;i++)
	   for(j=1;j<=n;j++)
	    if(cost[i][j]<min)//find the minimum path cost
	     if(visited[i]!=0)//and if the vertex has been visited (therefore,connected graph) 
	     {
	      min=cost[i][j];
	      a=u=i;//to store for later
	      b=v=j;
	     }
	     //After the mega loop, we have found the minimum connecting edge
	  if(visited[u]==0 || visited[v]==0)//If either u or v hasn't been visited, and edge can therefore exist expanding the MST 
	  {
	   printf("Edge %d:(%d->%d) cost:%d\n",ne++,a,b,min);
	   mincost+=min;
	   visited[b]=1;//mark it visited
	  }
	  cost[a][b]=cost[b][a]=999;//by doing this, traversal in both ways along that traversed path becomes null/void 
	 }
	 printf("Minimum cost=%d\n",mincost);//print mincost
	return 0;
}
