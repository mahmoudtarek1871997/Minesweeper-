#ifndef DISTRIBUTEMINES_H_INCLUDED
#define DISTRIBUTEMINES_H_INCLUDED

void distributeMines(int r,int c,int mines,int x,int y,int M[][c],int V[][c],char G[][c],int R[], int C[],int moves,int C_Ts,int P_Ts,int C_Tm,int P_Tm,int time_m,int time_s,int T)
{
    int i,j;
    int counter=0; //counter is the number of the cells which will have mines
    srand(time(NULL));
    while(counter<mines)
    {
        int nx=rand()%r;
        int ny=rand()%c;

        if(M[nx][ny]!=9 && (nx!=x || ny!=y)) // check whether the cell has a mine before ..
        {
            // & whether it is the player choose or not ..
            M[nx][ny]=9 ; // planting a mine

            counter++;

            // distributing the numbers around the mine
            for(i=nx-1; i<=nx+1; i++)
            {
                for(j=ny-1; j<=ny+1; j++)
                {
                    if(i>=0 && i<r && j>=0 && j<c && (i!=nx || j!=ny)) //checking if the cell is not out of the range of the grid and the cell is not the one which have the mine
                    {
                        if(M[i][j]!=9) //checking if the cell have got a mine or not
                        {
                            M[i][j]++;
                        }
                    }
                }
            }

        }
    }
    FILE*OpenedGrid;
    OpenedGrid=fopen("OpenedGrid.txt","w");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            fprintf(OpenedGrid,"%d ",M[i][j]);
        }
        fprintf(OpenedGrid,"\n");
    }
    fclose(OpenedGrid);
    open1(x,y,r,c,M,V,G, R, C, mines, moves,C_Ts,P_Ts,C_Tm,P_Tm,time_m, time_s,T);
}

#endif // DISTRIBUTEMINES_H_INCLUDED
