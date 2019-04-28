#include <stdio.h>

int N;
int board[20][20];

int is_attack(int i,int j)
{
    int k,l;
    for(k=0;k<N;k++)
    {
        if((board[i][k] == 1) || (board[k][j] == 1))//If there exists a queen along that column or row, return 1(is under attack)
            return 1;
    }
    
    for(k=0;k<N;k++)
    {
        for(l=0;l<N;l++)
        {
            if(((k+l) == (i+j)) || ((k-l) == (i-j)))
            {
                if(board[k][l] == 1)//If there exists a queen along the same diagonal, return 1(is under attack)
                    return 1;
            }
        }
    }
    return 0;//If not under attack
}

int N_queen(int n)
{
    int i,j;
    if(n==0)
        return 1;//can be placed there, else do the following
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if((!is_attack(i,j)) && (board[i][j]!=1))//If the queen is not under attack and the square is not already occupied by a queen previously
            {
                board[i][j] = 1;//place the queen there
                if(N_queen(n-1)==1)//return 1 only if the queens in the previous positions occupies the correct spot
               		return 1;//also serves as base condition
                board[i][j] = 0;//makes all the positions of the queens as 0 if they shouldn't occupy that place ideally
            }
        }
    }
    return 0;//to indicate that no such arrangement was found satisfying the nqueens condition
}

int main()
{
    printf("Enter the value of N for NxN chessboard\n");
    scanf("%d",&N);

    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            board[i][j]=0;
        }
    }
    N_queen(N);
    /*
    int a=N_queen(N);
    if(a==1)
    {
    	printf("n-Queens possible, possible chessboard:\n");
    	for(i=0;i<N;i++)
    	{
        	for(j=0;j<N;j++)
            	printf("%d\t",board[i][j]);
        	printf("\n");
    	}
	}
	else
	printf("n-Queens not possible");
	*/
	 
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            printf("%d\t",board[i][j]);
        printf("\n");
    }
	return 0;
}
