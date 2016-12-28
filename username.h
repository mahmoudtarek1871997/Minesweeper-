#ifndef USERNAME_H_INCLUDED
#define USERNAME_H_INCLUDED

void username(int r,int c,int time_m,int time_s,int moves)
{
    int i=0,j,k=0,l=0,counter=0;
    char str[STR_LEN],name[STR_LEN];
    printf("\nEnter your name : "); //input the player name
    gets(str);
    while((str[l] < 'A' || str[l] > 'Z') && (str[l] < 'a' || str[l] > 'z')) //count how many char in the name that the player input before the first char (a-z or A-Z)
    {
        l++;
    }
    while (i>=0) //replace the capital char (A-Z) with a the small one (a-z)
    {
        if(str[i]=='\0')
        {
            break;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = 'a' + (str[i] - 'A');
        }
        i++;
    }
    j=i;
    while(str[j-1] < 'a' || str[j-1] > 'z') //remove the char in the name that the player input after the last char (a-z)
    {
        j--;
    }
    system("cls");
    system("COLOR 0F");
    printf("Your name will be : ("); //the name of the player after editing
    for(i=l; i<j; i++)
    {
        if((str[i] >= 'a' && str[i] <= 'z') || str[i]==' ')
        {
            counter++;
            name[k]=str[i];
            printf("%c",name[k]);
            k++;
        }
    }
    printf(")\n\n");
    if(counter==0)
    {
        system("cls");
        printf("Error! ,Try Again\n\n");
        username(r,c,time_m,time_s,moves);
    }
    else
    {
        double score;
        int time;
        time=time_m*60+time_s;
        score=(pow(r,4)*pow(c,4))/(time*moves);
        leaderboard(name,score,r,c,time_m,time_s,moves);
    }
}

#endif // USERNAME_H_INCLUDED
