#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

void display(int r,int c,int mines,int M[][c],int V[][c],char G[][c],int R[], int C[],int moves,int o,int C_Ts,int P_Ts,int C_Tm,int P_Tm,int time_m,int time_s,int T)
{
    system("COLOR 3F");
    // Time Function
    struct tm *local;
    time_t t;
    t=time(NULL);
    local=localtime(&t);

    int i,j,flags,QM;
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
            if(G[i][j]=='F')
            {
                flags++;
                SetConsoleTextAttribute(hConsole,207);
            }
            else if(G[i][j]=='?')
            {
                QM++;
                SetConsoleTextAttribute(hConsole,159);
            }
            if(G[i][j]=='0')
            {
                G[i][j]=' ';
                printf(" %c ",G[i][j]);
            }
            else
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
                printf(" %c ",G[i][j]); //printing the Grid
            }
            SetConsoleTextAttribute(hConsole,15);
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
    printf("\nNumber of mines ---> %d\n",mines);
    printf("Number of cells marked with flags ---> %d\n",flags);
    printf("Number of cells marked with question mark ---> %d\n",QM);
    printf("Number of moves ---> %d\n",moves);
    if(T==0) //checking if this is the first time to print the time of the game
    {
        T++;
        printf("Time is ---> %d:0%d\n",time_m,time_s);
        P_Ts=local->tm_sec; //at the next move the time now will be previous then
        P_Tm=local->tm_min;
    }
    else if(T>0)
    {
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
        P_Ts=C_Ts; //at the next move the current time will be previous then
        P_Tm=C_Tm;
    }

    //auto save after every move
    save( r, c, mines, M,V,G, R, C, moves,o,C_Ts,P_Ts,C_Tm,P_Tm,time_m, time_s,T);

    // Checking The Win Condition ..... Also it will be executed Once but we must check it after every time we display our grid
    int counter=0;

    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(G[i][j]=='X' || G[i][j]=='F' || G[i][j]=='?')
            {
                counter++;
            }
        }
    }
    if(counter==mines)
    {
        system("cls");
        SetConsoleTextAttribute(hConsole,10);
        printf("****You win****\n");
        win(r,c,M,V,G,R,C,mines,moves,C_Ts,P_Ts,C_Tm,P_Tm,time_m, time_s,T);
    }
    else
    {
        action( r, c, mines, M,V,G, R, C, moves,o,C_Ts,P_Ts,C_Tm,P_Tm,time_m, time_s,T);
    }
}

#endif // DISPLAY_H_INCLUDED
