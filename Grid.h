#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

void Grid(int a)
{
    int C_Ts,P_Ts=0,time_m=0, time_s=0,C_Tm,P_Tm=0;

    int r, c,o=0,T=0;   // r >> Grid Rows , c >> Grid Columns , o to check if it is the first open action or not to distribute the mines , T to check if it is the first time to printing the time or not

    // getting Grid Dimensions from the user

    printf("Enter the number of rows of your Grid :");
    char xc[STR_LEN];
    gets(xc);
    if(xc[1]=='\0') //checking if there is 1 char
    {
        if(xc[0]>='0' && xc[0]<='9') //checking if the char is between 0 and 9
        {
            r=xc[0]-'0'; //changing the char to int
            if(r<2 || r>30) //checking the max and min number of rows of the matrix
            {
                system("cls");
                printf("Error! ,Try Again\n\n");
                Grid(0);
            }
        }
        else
        {
            system("cls");
            printf("Error! ,Try Again\n\n");
            Grid(0);
        }
    }
    else if(xc[2]=='\0') //checking if there are 2 chars
    {
        if(xc[0]>='0' && xc[0]<='9' && xc[1]>='0' && xc[1]<='9') //checking if the 2 chars are between 0 and 9
        {
            r=xc[0]-'0';
            r=r*10+xc[1]-'0'; //changing the char to int
            if(r<2 || r>30)
            {
                system("cls");
                printf("Error! ,Try Again\n\n");
                Grid(0);
            }
        }
        else
        {
            system("cls");
            printf("Error! ,Try Again\n\n");
            Grid(0);
        }
    }
    else
    {
        system("cls");
        printf("Error! ,Try Again\n\n");
        Grid(0);
    }
    printf("\nEnter the number of columns of your Grid :");
    char yc[STR_LEN];
    gets(yc);
    if(yc[1]=='\0') //checking if there is 1 char
    {
        if(yc[0]>='0' && yc[0]<='9') //checking if the char is between 0 and 9
        {
            c=yc[0]-'0'; //changing the char to int
            if(c<2 || c>30) //checking the max and min number of columns of the matrix
            {
                system("cls");
                printf("Error! ,Try Again\n\n");
                Grid(0);
            }
        }
        else
        {
            system("cls");
            printf("Error! ,Try Again\n\n");
            Grid(0);
        }
    }
    else if(yc[2]=='\0') //checking if there are 2 chars
    {
        if(yc[0]>='0' && yc[0]<='9' && yc[1]>='0' && yc[1]<='9') //checking if the 2 chars are between 0 and 9
        {
            c=yc[0]-'0';
            c=c*10+yc[1]-'0'; //changing the char to int
            if(c<2 || c>30)
            {
                system("cls");
                printf("Error! ,Try Again\n\n");
                Grid(0);
            }
        }
        else
        {
            system("cls");
            printf("Error! ,Try Again\n\n");
            Grid(0);
        }
    }
    else
    {
        system("cls");
        printf("Error! ,Try Again\n\n");
        Grid(0);
    }
    system("cls");

    int mines,moves=0;
    mines=1+(r*c)/10; //the Formula of mines

    char G[r][c];
    int M[r][c], V[r][c], C[c+1], R[r];

    initialization(r, c, M, G, V, C, R);
    display( r, c, mines, M,V,G, R, C, moves,o,C_Ts,P_Ts,C_Tm,P_Tm,time_m, time_s,T);
}

#endif // GRID_H_INCLUDED
