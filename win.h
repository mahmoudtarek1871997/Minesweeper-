#ifndef WIN_H_INCLUDED
#define WIN_H_INCLUDED

void win(int r,int c,int M[][c],int V[][c],char G[][c],int R[], int C[], int mines, int moves,int C_Ts,int P_Ts,int C_Tm,int P_Tm,int time_m,int time_s)
{
    FILE*game;
    fclose(fopen("game.txt", "w"));
    FILE*OpenedGrid;
    fclose(fopen("OpenedGrid.txt", "w"));
    int i,j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(G[i][j]=='X' || G[i][j]=='?')
            {
                G[i][j]='F';
            }
        }
    }
    int flags,QM;
    flags=mines;
    QM=0;
    for(j=0; j<c+1; j++)
    {
        if(C[j]==0) //printing the numbers of columns to guide the player
        {
            printf("\n   ");
        }
        else if(C[j]<9)
        {
            printf("  %d ",C[j]);
        }
        else
        {
            printf("  %d",C[j]);
        }
    }
    printf("\n");
    for(j=0; j<c+1; j++)
    {
        if(j==0)
        {
            printf("   -");
        }
        else
        {
            printf("----");
        }
    }
    printf("\n");

    HANDLE hConsole;
    hConsole=GetStdHandle(STD_OUTPUT_HANDLE);

    for(i=0; i<r; i++)
    {
        if(R[i]<10)
        {
            printf("%d  |",R[i]); //printing the numbers of rows to guide the player
        }
        else
        {
            printf("%d |",R[i]);
        }
        for(j=0; j<c; j++)
        {
            if(G[i][j]=='1')
            {
                SetConsoleTextAttribute(hConsole,9);
            }
            else if(G[i][j]=='2')
            {
                SetConsoleTextAttribute(hConsole,10);
            }
            else if(G[i][j]=='3')
            {
                SetConsoleTextAttribute(hConsole,12);
            }
            else if(G[i][j]=='4')
            {
                SetConsoleTextAttribute(hConsole,1);
            }
            else if(G[i][j]=='5')
            {
                SetConsoleTextAttribute(hConsole,4);
            }
            else if(G[i][j]=='6')
            {
                SetConsoleTextAttribute(hConsole,13);
            }
            else if(G[i][j]=='7')
            {
                SetConsoleTextAttribute(hConsole,14);
            }
            else if(G[i][j]=='8')
            {
                SetConsoleTextAttribute(hConsole,11);
            }
            else if(G[i][j]=='F')
            {
                SetConsoleTextAttribute(hConsole,207);
            }
            printf(" %c ",G[i][j]); //printing the Grid
            SetConsoleTextAttribute(hConsole,10);
            printf("|");
        }
        printf("\n");
        for(j=0; j<c+1; j++)
        {
            if(j==0)
            {
                printf("   -");
            }
            else
            {
                printf("----");
            }
        }
        printf("\n");
    }
    SetConsoleTextAttribute(hConsole,15);
    printf("Number of mines ---> %d\n",mines);
    printf("Number of cells marked with flags ---> %d\n",flags);
    printf("Number of cells marked with question mark ---> %d\n",QM);
    printf("Number of moves ---> %d\n",moves);
    if(time_s<10)
    {
        printf("Time is ---> %d:0%d\n",time_m,time_s);
    }
    else
    {
        printf("Time is ---> %d:%d\n",time_m,time_s);
    }
    username(r,c,time_m,time_s,moves);
}

#endif // WIN_H_INCLUDED
