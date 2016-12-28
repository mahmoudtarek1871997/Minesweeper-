#ifndef EXIT_H_INCLUDED
#define EXIT_H_INCLUDED

void exit1(int a)
{
    char i,xc[STR_LEN];
    printf("Are you sure you want to exit ?\ny.Yes\tn.No\n\n");
    gets(xc);
    if(xc[1]!='\0') //if the input is not 1 char
    {
        system("cls");
        printf("Error! ,Try Again\n\n");
        exit1(0);
    }
    i=xc[0];
    if(i=='y') //yes
    {
        system("cls");
        system("COLOR f9");
        printf("Goodbye ^_^\n");
        exit(0);
    }
    else if(i=='n') //no
    {
        system("cls");
        printf("Return back to the game\n\n");
        play(0);
    }
    else //the input is not YES or NO !!
    {
        system("cls");
        printf("Error! ,Try Again\n\n");
        exit1(0);
    }
}

#endif // EXIT_H_INCLUDED
