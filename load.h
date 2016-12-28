#ifndef LOAD_H_INCLUDED
#define LOAD_H_INCLUDED

void load(int a)
{
    // Time Function
    struct tm *local;
    time_t t;
    t=time(NULL);
    local=localtime(&t);

    int i,j,r,c,mines,moves,o,C_Ts,P_Ts,C_Tm,P_Tm,time_m,time_s,T;
    FILE*game;
    game=fopen("game.txt","r");
    fscanf(game," %d %d %d %d %d %d %d %d",&r,&c,&mines,&moves,&o,&time_m,&time_s,&T);
    P_Ts=local->tm_sec; //at the next move the time now will be previous then
    P_Tm=local->tm_min;
    int M[r][c],V[r][c],C[c+1],R[r];
    char G[r][c];
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            fscanf(game," %c",&G[i][j]);
        }
    }
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            fscanf(game," %d",&M[i][j]);
        }
    }
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            fscanf(game," %d",&V[i][j]);
        }
    }
    for(j=0; j<c+1; j++)
    {
        fscanf(game," %d",&C[j]);
    }
    for(i=0; i<r; i++)
    {
        fscanf(game," %d",&R[i]);
    }
    fclose(game);
    display( r, c, mines, M,V,G, R, C, moves,o,C_Ts,P_Ts,C_Tm,P_Tm,time_m, time_s,T);
}


#endif // LOAD_H_INCLUDED
