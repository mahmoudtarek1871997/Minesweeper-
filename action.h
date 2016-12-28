#ifndef ACTION_H_INCLUDED
#define ACTION_H_INCLUDED

void action(int r,int c,int mines,int M[][c],int V[][c],char G[][c],int R[], int C[],int moves,int o,int C_Ts,int P_Ts,int C_Tm,int P_Tm,int time_m,int time_s,int T)
{
    int x,y;
    char a[STR_LEN];
    printf("\n(o).open a closed or opened cell \t (f).put a flag \t (?).put a question mark\n(r).remove flags or question marks \t (s).save and exit\n\nEnter the action : ");
    gets(a);
    if(a[1]=='\0') //checking if the input is 1 char
    {
        if(a[0]=='s') //save & exit
        {
            save( r, c, mines, M,V,G, R, C, moves,o,C_Ts,P_Ts,C_Tm,P_Tm,time_m, time_s,T);
            system("cls");
            exit1(0);
        }
        else if(a[0]=='o' || a[0]=='f' || a[0]=='?' || a[0]=='r') //checking if the input is one of the 4 actions
        {
            printf("\nEnter the row : ");
            x=row( r, c, mines, M,V,G, R, C, moves,o, C_Ts, P_Ts,C_Tm,P_Tm,time_m, time_s,T);
            printf("\nEnter the column : ");
            y=column( r, c, mines, M,V,G, R, C, moves,o, C_Ts, P_Ts,C_Tm,P_Tm,time_m, time_s,T);
            system("cls");
            if(a[0]=='o' && o==0) // check if this is the first action of open
            {
                if(G[x][y]=='F')
                {
                    system("cls");
                    printf("Error! ,Try Again\n\n");
                    display( r, c, mines, M,V,G, R, C, moves,o,C_Ts,P_Ts,C_Tm,P_Tm,time_m, time_s,T);
                }
                else
                {
                    o++;
                    moves++;
                    distributeMines( r, c, mines, x, y, M,V,G, R, C, moves, C_Ts, P_Ts,C_Tm,P_Tm,time_m, time_s,T);
                }

            }
            else if(a[0]=='o')
            {
                if(G[x][y]=='F')
                {
                    system("cls");
                    printf("Error! ,Try Again\n\n");
                    display( r, c, mines, M,V,G, R, C, moves,o,C_Ts,P_Ts,C_Tm,P_Tm,time_m, time_s,T);
                }
                else
                {
                    moves++;
                    if(V[x][y]==0) //checking if the cell was visited or not
                    {
                        open1(x,y,r,c,M,V,G, R, C, mines, moves,C_Ts,P_Ts,C_Tm,P_Tm,time_m, time_s,T);
                    }
                    else
                    {
                        open2(x,y,r,c,M,V,G, R, C, mines, moves,o,C_Ts,P_Ts,C_Tm,P_Tm,time_m, time_s,T);
                    }
                }
            }
            else if(a[0]=='f')
            {
                if(G[x][y]=='X' || G[x][y]=='?')
                {
                    moves++;
                    if(G[x][y]=='?') //if the cell have ? replace it with a flag
                    {
                        G[x][y]='F';
                    }
                    else
                    {
                        G[x][y]='F';
                    }
                }
                else
                {
                    system("cls");
                    printf("Error! ,Try Again\n\n");
                    display( r, c, mines, M,V,G, R, C, moves,o,C_Ts,P_Ts,C_Tm,P_Tm,time_m, time_s,T);
                }
            }
            else if(a[0]=='?')
            {
                if(G[x][y]=='X' || G[x][y]=='F')
                {
                    moves++;
                    if(G[x][y]=='F') //if the cell have a flag replace it with ?
                    {
                        G[x][y]='?';
                    }
                    else
                    {
                        G[x][y]='?';
                    }
                }
                else
                {
                    system("cls");
                    printf("Error! ,Try Again\n\n");
                    display( r, c, mines, M,V,G, R, C, moves,o,C_Ts,P_Ts,C_Tm,P_Tm,time_m, time_s,T);
                }
            }
            else if(a[0]=='r')
            {
                if(G[x][y]=='?')
                {
                    moves++;
                    G[x][y]='X';
                }
                else if(G[x][y]=='F')
                {
                    moves++;
                    G[x][y]='X';
                }
                else
                {
                    system("cls");
                    printf("Error! ,Try Again\n\n");
                    display( r, c, mines, M,V,G, R, C, moves,o,C_Ts,P_Ts,C_Tm,P_Tm,time_m, time_s,T);
                }
            }

            system("cls");
            display( r, c, mines, M,V,G, R, C, moves,o,C_Ts,P_Ts,C_Tm,P_Tm,time_m, time_s,T);

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

#endif // ACTION_H_INCLUDED
