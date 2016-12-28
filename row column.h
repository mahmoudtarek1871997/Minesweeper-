#ifndef ROW_COLUMN_H_INCLUDED
#define ROW_COLUMN_H_INCLUDED

int row(int r,int c,int mines,int M[][c],int V[][c],char G[][c],int R[], int C[], int moves,int o,int C_Ts,int P_Ts,int C_Tm,int P_Tm,int time_m,int time_s,int T)
{
    int x;
    char xc[STR_LEN];
    gets(xc);
    if(xc[1]=='\0')
    {
        x=xc[0]-'0';
        x--;
        if(x>=0 && x<r)
        {
            return x;
        }
        else
        {
            system("cls");
            printf("Error! ,Try Again\n\n");
            display( r, c, mines, M,V,G, R, C, moves,o,C_Ts,P_Ts,C_Tm,P_Tm,time_m, time_s,T);
        }
    }
    else if(xc[2]=='\0')
    {
        x=xc[0]-'0';
        x=x*10+xc[1]-'0';
        x--;
        if(x>=0 && x<r)
        {
            return x;
        }
        else
        {
            system("cls");
            printf("Error! ,Try Again\n\n");
            display( r, c, mines, M,V,G, R, C, moves,o,C_Ts,P_Ts,C_Tm,P_Tm,time_m, time_s,T);
        }
    }
    else
    {
        system("cls");
        printf("Error! ,Try Again\n\n");
        display( r, c, mines, M,V,G, R, C, moves,o,C_Ts,P_Ts,C_Tm,P_Tm,time_m, time_s,T);
    }
}

int column(int r,int c,int mines,int M[][c],int V[][c],char G[][c],int R[], int C[], int moves,int o,int C_Ts,int P_Ts,int C_Tm,int P_Tm,int time_m,int time_s,int T)
{
    int y;
    char yc[STR_LEN];
    gets(yc);
    if(yc[1]=='\0')
    {
        y=yc[0]-'0';
        y--;
        if(y>=0 && y<c)
        {
            return y;
        }
        else
        {
            system("cls");
            printf("Error! ,Try Again\n\n");
            display( r, c, mines, M,V,G, R, C, moves,o,C_Ts,P_Ts,C_Tm,P_Tm,time_m, time_s,T);
        }
    }
    else if(yc[2]=='\0')
    {
        y=yc[0]-'0';
        y=y*10+yc[1]-'0';
        y--;
        if(y>=0 && y<c)
        {
            return y;
        }
        else
        {
            system("cls");
            printf("Error! ,Try Again\n\n");
            display( r, c, mines, M,V,G, R, C, moves,o,C_Ts,P_Ts,C_Tm,P_Tm,time_m, time_s,T);
        }
    }
    else
    {
        system("cls");
        printf("Error! ,Try Again\n\n");
        display( r, c, mines, M,V,G, R, C, moves,o,C_Ts,P_Ts,C_Tm,P_Tm,time_m, time_s,T);
    }
}

#endif // ROW_COLUMN_H_INCLUDED
