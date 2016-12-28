#ifndef LOSE_H_INCLUDED
#define LOSE_H_INCLUDED

void lose(int x,int y,int r,int c,int M[][c],int V[][c],char G[][c],int R[], int C[], int mines,int moves,int C_Ts,int P_Ts,int C_Tm,int P_Tm,int time_m,int time_s)
{
    FILE*game;
    fclose(fopen("game.txt", "w"));
    FILE*OpenedGrid;
    fclose(fopen("OpenedGrid.txt", "w"));

    HANDLE hConsole;
    hConsole=GetStdHandle(STD_OUTPUT_HANDLE);

    struct tm *local;
    time_t t;
    t=time(NULL);
    local=localtime(&t);

    int i,j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(M[i][j]==9)
            {
                if(G[i][j]=='X' || G[i][j]=='?')
                {
                    G[i][j]='M';
                }
                else if(G[i][j]=='F')
                {
                    G[i][j]='*';
                }
            }
            else if(M[i][j]!=9 && G[i][j]=='F')
            {
                G[i][j]='-';
            }
            else if((G[i][j]=='X' || G[i][j]=='?') && M[i][j]<9 && M[i][j]>=0)
            {
                if(M[i][j]==0)
                {
                    G[i][j]=' ';
                }
                else
                {
                    G[i][j]=M[i][j]+'0';
                }
            }
        }
    }
    G[x][y]='!';
    int flags,QM;
    flags=QM=0;
    for(j=0; j<c+1; j++)
    {
        if(C[j]==0) //printing the numbers of columns to guide the player
        {
            printf("   ");
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
            else if(G[i][j]=='!')
            {
                SetConsoleTextAttribute(hConsole,207);
            }
            else if(G[i][j]=='*')
            {
                SetConsoleTextAttribute(hConsole,159);
            }
            else if(G[i][j]=='M')
            {
                SetConsoleTextAttribute(hConsole,79);
            }
            else if(G[i][j]=='-')
            {
                SetConsoleTextAttribute(hConsole,31);
            }
            printf(" %c ",G[i][j]); //printing the Grid
            SetConsoleTextAttribute(hConsole,12);
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
    C_Ts=local->tm_sec; //the current time is the time now
    C_Tm=local->tm_min;
    if(C_Ts>P_Ts && (C_Ts!=P_Ts || C_Tm!=P_Tm))
    {
        time_s=time_s+C_Ts-P_Ts; //the game time will be the difference between the current and the previous time plus the last game time
        if(time_s>=60)
        {
            time_m=time_m+1;
            time_s=time_s%60; //if the game time with seconds is equal or more than 60 take the mod and increase the game time with minute by one minute
            if(C_Tm>P_Tm)
            {
                if(C_Tm-P_Tm>1)
                {
                    time_m=time_m+C_Tm-P_Tm-1;
                }
            }
            else if(C_Tm<P_Tm)
            {
                if(60-(P_Tm-C_Tm)>1)
                {
                    time_m=time_m+C_Tm-P_Tm-1;
                }
            }
        }
        else
        {
            if(C_Tm>P_Tm)
            {
                if(C_Tm-P_Tm>1)
                {
                    time_m=time_m+C_Tm-P_Tm-1;
                }
            }
            else if(C_Tm<P_Tm)
            {
                if(60-(P_Tm-C_Tm)>1)
                {
                    time_m=time_m+C_Tm-P_Tm-1;
                }
            }
        }
    }
    else if(C_Ts<=P_Ts && (C_Ts!=P_Ts || C_Tm!=P_Tm))
    {
        time_s=time_s+60-(P_Ts-C_Ts); //if the previous time by seconds is equal or more than the current time by seconds the difference will be 60+P-C
        if(time_s>=60)
        {
            time_m=time_m+1;
            time_s=time_s%60;
            if(C_Tm>P_Tm)
            {
                if(C_Tm-P_Tm>1)
                {
                    time_m=time_m+C_Tm-P_Tm-1;
                }
            }
            else if(C_Tm<P_Tm)
            {
                if(60-(P_Tm-C_Tm)>1)
                {
                    time_m=time_m+C_Tm-P_Tm-1;
                }
            }
        }
        else
        {
            if(C_Tm>P_Tm)
            {
                if(C_Tm-P_Tm>1)
                {
                    time_m=time_m+C_Tm-P_Tm-1;
                }
            }
            else if(C_Tm<P_Tm)
            {
                if(60-(P_Tm-C_Tm)>1)
                {
                    time_m=time_m+C_Tm-P_Tm-1;
                }
            }
        }
    }
    if(time_s<10)
    {
        printf("Time is ---> %d:0%d\n",time_m,time_s); //to print the seconds always 2 numbers
    }
    else
    {
        printf("Time is ---> %d:%d\n",time_m,time_s);
    }
    printf("\nPress (Enter) to return to the Main Menu\n");
    char a[STR_LEN];
    gets(a);
    system("cls");
    play(0);
}

#endif // LOSE_H_INCLUDED
