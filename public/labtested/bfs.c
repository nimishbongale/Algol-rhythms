/*
Author:- Nimish Bongale
Version 1.0.4
Date:- 29/2/19
A program which demonstartes Breadth First Search(BFS) */

#include<stdio.h>

int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;


void bfs(int v) {

 for(i = 1; i <= n; i++)
 	if(a[v][i] && !visited[i])
 	q[++r] = i;
 
 if(f <= r) {
 	visited[q[f]] = 1;
 	bfs(q[f++]);
 }
}

int main() {
 int v;
 printf("Enter the number of vertices:");
 scanf("%d", &n);
 for(i=1; i <= n; i++) {
 	q[i] = 0;
 	visited[i] = 0;
}
 printf("\nEnter the adjacency matrix:\n");
 for(i=1; i<=n; i++) {
 	for(j=1;j<=n;j++) {
 		scanf("%d", &a[i][j]);
 }
}
 printf("\nEnter the starting vertex:");
 scanf("%d", &v);
 
 bfs(v);
 
 printf("\nThe nodes which are reachable are:\n");
 for(i=1; i <= n; i++) 
 	if(visited[i])
 		printf("%d\t", i);
		 	
	return 0;
 }


