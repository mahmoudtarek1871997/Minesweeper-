#ifndef SAVE_H_INCLUDED
#define SAVE_H_INCLUDED

void save(int r,int c,int mines,int M[][c],int V[][c],char G[][c],int R[], int C[],int moves,int o,int C_Ts,int P_Ts,int C_Tm,int P_Tm,int time_m,int time_s,int T)
{
    // Time Function
    struct tm *local;
    time_t t;
    t=time(NULL);
    local=localtime(&t);

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
    int i,j;
    FILE*game;
    game=fopen("game.txt","w");
    fprintf(game,"%d %d %d %d %d %d %d %d\n\n",r,c,mines,moves,o,time_m,time_s,T);
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(G[i][j]==' ')
            {
                fprintf(game,"0 ");
            }
            else
            {
                fprintf(game,"%c ",G[i][j]);
            }
        }
        fprintf(game,"\n");
    }
    fprintf(game,"\n");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            fprintf(game,"%d ",M[i][j]);
        }
        fprintf(game,"\n");
    }
    fprintf(game,"\n");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            fprintf(game,"%d ",V[i][j]);
        }
        fprintf(game,"\n");
    }
    fprintf(game,"\n");
    for(j=0; j<c+1; j++)
    {
        fprintf(game,"%d ",C[j]);
    }
    fprintf(game,"\n\n");
    for(i=0; i<r; i++)
    {
        fprintf(game,"%d ",R[i]);
    }
    fclose(game);
}

#endif // SAVE_H_INCLUDED
