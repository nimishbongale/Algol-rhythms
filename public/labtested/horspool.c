/*
Author:- Nimish Bongale
Version 1.0.2
Date:- 3/7/19
A program which checks if a substring is present in a larger string using Horspools algorithm*/

#include<stdio.h>
#include<string.h>

#define MAX 500 

int t[MAX];
void shifttable(char p[])//function to calculate shifttable
{
 	int i,j,m;
 	m=strlen(p);
 	for(i=0;i<MAX;i++)
  	t[i]=m;
 	for(j=0;j<m-1;j++)
  	t[p[j]]=m-1-j;
}

int horspool(char src[],char p[])
{
 	int i,j,k,m,n;
 	n=strlen(src);//length of larger string
 	m=strlen(p);//length of smaller string 
 	i=m-1;
 	while(i<n)
 	{
  		k=0;
 		while((k<m)&&(p[m-1-k]==src[i-k]))//loop to check matching or not 
  		k++;//If match=true, then k value will be ==m, otherwise it will be something lesser than m
 		if(k==m)
   		return(i-m+1);
  		else
  		i+=t[src[i]];//shift the value of i (in effect, shifting the pattern string) 
 	}
 	return -1;
}

int main()
{
	char src[100],p[100];
 	int pos;
 	printf("Enter the text in which pattern is to be searched: ");
 	gets(src);//src=source string to be searched
 	printf("\nEnter the pattern to be searched: ");
 	gets(p);//pattern to be matched with
 	
 	shifttable(p);
 	pos=horspool(src,p);
 	
 	if(pos!=-1)
  	printf("\nPattern found from position %d",pos);
 	else
 	printf("\nThe pattern was not found in the given text");
 	
	return 0; 
}
