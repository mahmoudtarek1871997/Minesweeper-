#ifndef OPEN2_H_INCLUDED
#define OPEN2_H_INCLUDED

void open2(int x,int y,int r,int c,int M[][c],int V[][c],char G[][c],int R[], int C[], int mines, int moves,int o,int C_Ts,int P_Ts,int C_Tm,int P_Tm,int time_m,int time_s,int T)
{
    int i,j,Fn=0;
    if(M[x][y]>0 && M[x][y]<9)
    {
        for(i=x-1; i<=x+1; i++)
        {
            for(j=y-1; j<=y+1; j++)
            {
                if(G[i][j]=='F' && j>-1 && j<c && i>-1 && i<r)
                {
                    Fn++;
                }
            }
        }
        if(M[x][y]==Fn)
        {
            for(i=x-1; i<=x+1; i++)
            {
                for(j=y-1; j<=y+1; j++)
                {
                    if(G[i][j]!='F' && j>-1 && j<c && i>-1 && i<r && (i!=x || j!=y))
                    {
                        if(M[i][j]==9)
                        {
                            HANDLE hConsole;
                            hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
                            // lose
                            system("cls");
                            SetConsoleTextAttribute(hConsole,12);
                            printf("\n****You lose****\n\n");
                            lose(x,y,r,c,M,V,G, R, C, mines, moves,C_Ts,P_Ts,C_Tm,P_Tm,time_m, time_s,T);
                        }
                        else if(M[i][j]==0)
                        {
                            G[i][j]=' ';
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
                        else
                        {
                            G[i][j]=M[i][j]+'0';
                        }
                    }
                }
            }
        }
    }
    system("cls");
    display( r, c, mines, M,V,G, R, C, moves,o,C_Ts,P_Ts,C_Tm,P_Tm,time_m, time_s,T);
}

#endif // OPEN2_H_INCLUDED
