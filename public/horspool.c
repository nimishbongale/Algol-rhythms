#include<stdio.h>
#include<string.h>

#define MAX 500

int t[MAX];
void shifttable(char p[])
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
 	n=strlen(src);
 	m=strlen(p);
 	i=m-1;
 	while(i<n)
 	{
  		k=0;
 		while((k<m)&&(p[m-1-k]==src[i-k]))
  		 k++;
 		 if(k==m)
   		return(i-m+1);
  		else
  		 i+=t[src[i]];
 	}
 	return -1;
}
int main()
{
	char src[100],p[100];
 	int pos;
 	printf("Enter the text in which pattern is to be searched: ");
 	gets(src);
 	printf("\nEnter the pattern to be searched: ");
 	gets(p);
 	shifttable(p);
 	pos=horspool(src,p);
 	if(pos>=0)
  	printf("\nPattern found from position %d",pos);
 	else
 	printf("\nThe pattern was not found in the given text");
	return 0; 
}
