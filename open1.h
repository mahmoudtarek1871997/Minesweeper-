#ifndef OPEN1_H_INCLUDED
#define OPEN1_H_INCLUDED

void open1(int x,int y,int r,int c,int M[][c],int V[][c],char G[][c],int R[], int C[], int mines, int moves,int C_Ts,int P_Ts,int C_Tm,int P_Tm,int time_m,int time_s,int T)
{
    int i,j;
    V[x][y]=1;
    if(M[x][y]==0)
    {
        G[x][y]=' ';
        for(i=x-1; i<=x+1; i++)
        {
            for(j=y-1; j<=y+1; j++)
            {
                if(V[i][j]==0 && j>-1 && j<c && i>-1 && i<r)
                {
                    open1(i,j,r,c,M,V,G, R, C, mines, moves,C_Ts,P_Ts,C_Tm,P_Tm,time_m, time_s,T);
                }
            }
        }
    }
    else if(M[x][y]>0 && M[x][y]<9)
    {
        G[x][y]=M[x][y]+'0';
    }
    else if(M[x][y]==9)
    {
        if(G[x][y]!='F')
        {
            HANDLE hConsole;
            hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
            // lose
            system("cls");
            SetConsoleTextAttribute(hConsole,12);
            printf("****You lose****\n\n");
            lose(x,y,r,c,M,V,G, R, C, mines, moves,C_Ts,P_Ts,C_Tm,P_Tm,time_m, time_s,T);
        }
    }
}

#endif // OPEN1_H_INCLUDED
