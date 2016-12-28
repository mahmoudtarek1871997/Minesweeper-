#ifndef LEADERBOARD_LIST_H_INCLUDED
#define LEADERBOARD_LIST_H_INCLUDED

void leaderboard_list(int a)
{
    FILE*Leaderboard;
    Leaderboard=fopen("Leaderboard.txt","r");
    fseek(Leaderboard,0,SEEK_END);
    if(ftell(Leaderboard)==0) //check if the file is empty or not
    {
        fclose(Leaderboard);
        printf("The file is empty ,there is no any player right now\nPress (Enter) to return to the Main Menu\n");
        char x[STR_LEN];
        gets(x);
        system("cls");
        play(0);
    }
    else
    {
        fclose(Leaderboard);
        int i,lines=1,ch;
        Leaderboard=fopen("Leaderboard.txt","r");
        while(!feof(Leaderboard))
        {
            ch=fgetc(Leaderboard);
            if(ch=='\n')
            {
                lines++;
            }
        }
        fseek(Leaderboard,0,SEEK_SET);
        struct name_score
        {
            char name[STR_LEN];
            double score;
        };
        struct name_score LBstr[STR_LEN];
        printf("r-name\t\t\t\t\t\tscore\n\n");
        for(i=0;i<lines;i++)
        {
            if(i>8)
            {
                if(i==lines-1)
                {
                    fscanf(Leaderboard,"%[^,],%lf",LBstr[i].name,&LBstr[i].score);
                    printf("%d-%-44s %.2f",i+1,LBstr[i].name, LBstr[i].score);
                }
                else
                {
                    fscanf(Leaderboard,"%[^,],%lf\n",LBstr[i].name,&LBstr[i].score);
                    printf("%d-%-44s %.2f\n",i+1,LBstr[i].name,LBstr[i].score);
                }
            }
            else
            {
                if(i==lines-1)
                {
                    fscanf(Leaderboard,"%[^,],%lf",LBstr[i].name,&LBstr[i].score);
                    printf("%d-%-45s %.2f",i+1,LBstr[i].name, LBstr[i].score);
                }
                else
                {
                    fscanf(Leaderboard,"%[^,],%lf\n",LBstr[i].name,&LBstr[i].score);
                    printf("%d-%-45s %.2f\n",i+1,LBstr[i].name,LBstr[i].score);
                }
            }
        }
        fclose(Leaderboard);
        printf("\n\nPress (Enter) to return to the Main Menu\n");
        char x[STR_LEN];
        gets(x);
        system("cls");
        play(0);
    }
}

#endif // LEADERBOARD_LIST_H_INCLUDED
