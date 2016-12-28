#ifndef CHECK_NAME_H_INCLUDED
#define CHECK_NAME_H_INCLUDED

void check_name(double score,int r,int c,int time_m,int time_s,int moves)
{
    printf("\nThis name is already used\nAre you the user of this name ?\ny.Yes\tn.No\n");
    char xc[STR_LEN];
    gets(xc);
    if(xc[1]!='\0') //if the input is not 1 char
    {
        system("cls");
        printf("Error! ,Try Again\n");
        check_name(score,r,c,time_m,time_s,moves);
    }
    if(xc[0]=='y') //yes
    {
        printf("So, your score is %.2f\n\n",score);
    }
    else if(xc[0]=='n') //no
    {
        system("cls");
        printf("Please, write another name\n");
        username(r,c,time_m,time_s,moves);
    }
    else //the input is not YES or NO !!
    {
        system("cls");
        printf("Error! ,Try Again\n");
        check_name(score,r,c,time_m,time_s,moves);
    }
}

#endif // CHECK_NAME_H_INCLUDED
