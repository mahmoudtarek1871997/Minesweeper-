#ifndef LEADERBOARD_H_INCLUDED
#define LEADERBOARD_H_INCLUDED

void leaderboard(char name[],double score,int k,int r,int c,int time_m,int time_s,int moves)
{
    FILE*Leaderboard;
    Leaderboard=fopen("Leaderboard.txt","r");
    fseek(Leaderboard,0,SEEK_END);
    if(ftell(Leaderboard)==0) //check if the file is empty or not to input the first score
    {
        fclose(Leaderboard);
        printf("So, your score is %.2f\n\n",score);
        Leaderboard=fopen("Leaderboard.txt","w");
        fprintf(Leaderboard,"%s,%.2f",name,score);
        fclose(Leaderboard);
    }
    else
    {
        //if it is not the first score put the previous scores in an array of structures to sort it
        fclose(Leaderboard);
        int i,j,lines=1,ch;
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
        for(i=0;i<lines;i++)
        {
            if(i==lines-1)
            {
                fscanf(Leaderboard,"%[^,],%lf",LBstr[i].name,&LBstr[i].score);
            }
            else
            {
                fscanf(Leaderboard,"%[^,],%lf\n",LBstr[i].name,&LBstr[i].score);
            }
        }
        fclose(Leaderboard);
        int f=0;
        struct name_score tempstr;
        for(j=0;j<lines;j++)
        {
            if(strcmp(LBstr[j].name,name)==0)
            {
                if(LBstr[j].name[k]=='\0')
                {
                    f=1; //the name is found so it is used
                    check_name(score,r,c,time_m,time_s,moves);
                    lines--;
                    if(score>LBstr[j].score) //compare the old score with the new one
                    {
                        LBstr[j].score=score;
                        while ((LBstr[j].score>LBstr[j-1].score) && (j>0)) //sort the scores in the leaderboard if the name is repeated
                        {
                            tempstr=LBstr[j];
                            LBstr[j]=LBstr[j-1];
                            LBstr[j-1]=tempstr;
                            j--;
                        }
                        break;
                    }
                }
            }
        }
        if(f==0) //if the name is not found so it is not used
        {
            i=lines;
            printf("So, your score is %.2f\n\n",score);
            j=0;
            LBstr[i].name[j]=name[j];
            while(name[j]!='\0')
            {
                j++;
                LBstr[i].name[j]=name[j];
            }
            j=0;
            while((LBstr[i].name[j]>='a' && LBstr[i].name[j]<='z') || LBstr[i].name[j]==' ')
            {
                j++;
            }
            if(LBstr[i].name[j]<'a' || LBstr[i].name[j]>'z')
            {
                LBstr[i].name[j]='\0';
            }
            LBstr[i].score=score;
            while ((LBstr[i].score>LBstr[i-1].score) && (i>0)) //Sorting the array
            {
                tempstr=LBstr[i];
                LBstr[i]=LBstr[i-1];
                LBstr[i-1]=tempstr;
                i--;
            }
        }
        Leaderboard=fopen("Leaderboard.txt","w"); //put the scores in the file
        printf("**Leaderboard**\n\nr-name\t\t\t\t\t\tscore\n\n");
        for (i=0;i<=lines;i++)
        {
            if(i>8)
            {
                if(i==lines)
                {
                    printf("%d-%-44s %.2f\n\n",i+1,LBstr[i].name,LBstr[i].score);
                    fprintf(Leaderboard,"%s,%.2f",LBstr[i].name,LBstr[i].score);
                }
                else
                {
                    printf("%d-%-44s %.2f\n",i+1,LBstr[i].name,LBstr[i].score);
                    fprintf(Leaderboard,"%s,%.2f\n",LBstr[i].name,LBstr[i].score);
                }
            }
            else
            {
                if(i==lines)
                {
                    printf("%d-%-45s %.2f\n\n",i+1,LBstr[i].name,LBstr[i].score);
                    fprintf(Leaderboard,"%s,%.2f",LBstr[i].name,LBstr[i].score);
                }
                else
                {
                    printf("%d-%-45s %.2f\n",i+1,LBstr[i].name,LBstr[i].score);
                    fprintf(Leaderboard,"%s,%.2f\n",LBstr[i].name,LBstr[i].score);
                }
            }
        }
        fclose(Leaderboard);
    }
    printf("Press (Enter) to return to the Main Menu\n");
    char a[STR_LEN];
    gets(a);
    system("cls");
    play(0);
}


#endif // LEADERBOARD_H_INCLUDED
