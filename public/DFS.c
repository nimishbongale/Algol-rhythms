#include<stdio.h>

int count =0;

void dfs(int a[20][20],int n,int visited[20],int source)
{
    count++;
    int v;
    visited[source]=count;
    for(v=1;v<=n;v++)
    {
        if(a[source][v]==1&&visited[v]==0)
        {
            dfs(a,n,visited,v);
        }
    }
}

void main()
{
    int n,a[20][20],i,j,visited[20],source,visitedorder[20];
    printf("Enter the no of vertices\n");
    scanf("%d",&n);//n=no. of vertices
    printf("Enter the adjacency matrix\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)//i & j looping variables
            scanf("%d",&a[i][j]);//a[][]=adjacency matrix
    for(i=1;i<=n;i++)
        visited[i]=0;//visited stack all initialized with 0
    printf("Enter source node\n");
    scanf("%d",&source);//source contains source node, usually 0 or 1
    for(i=1;i<=n;i++)
        if(visited[i]==0)//if the current stack location is empty; ie. the vertex hasn't been reached 
            dfs(a,n,visited,i);//carry out DFS with that vertex as source
            
	/*visited[] will now contain the count of each vertex; ie. if vertex 6 was traversed in the 2nd call, visited[6]=2.
    	Now we will have to display the elements in the way in which they were traversed.
    	visitedorder[] stores exactly that.
		visited[1]=1
		visited[2]=2
		visited[3]=3
		visited[5]=4
		visited[4]=5*/
	for(i=1;i<=n;i++)
    visitedorder[visited[i]]=i;//for every vertex visited in that order, assign the order no. i in the visited order. 
	//indice - value swap 
    
    printf("DFS traversal= \n");
    for(i=1;i<=n;i++)
    printf("%c \t",visitedorder[i]+47);
}

