#ifndef PLAY_H_INCLUDED
#define PLAY_H_INCLUDED
#define STR_LEN 1000

void play(int a)
{
    system("COLOR 3F");
    FILE*game;
    game=fopen("game.txt","r");
    fseek(game,0,SEEK_END);
    if(ftell(game)==0) //check if the file is empty or not
    {
        fclose(game);
        printf("**Minesweeper**\n\n\nLet's play ...\n\n1.Start New Game\n2..Leader board\n3.Exit\n\nSelect number : ");
        int x;
        char xc[STR_LEN];
        gets(xc);
        if(xc[1]!='\0') //if the input is not 1 char
        {
            system("cls");
            printf("Error! ,Try Again\n\n");
            play(0);
        }
        x=xc[0]-'0'; //change the char to int
        if(x==1)
        {
            system("cls");
            Grid(0);
        }
        else if(x==2)
        {
            system("cls");
            printf("**Leaderboard**\n\n");
            leaderboard_list(0);
        }
        else if(x==3)
        {
            system("cls");
            exit1(0);
        }
        else
        {
            system("cls");
            printf("Error! ,Try Again\n\n");
            play(0);
        }
    }
    else
    {
        printf("**Minesweeper**\n\n\nLet's play ...\n\n1.Continue Game\n2.Start New Game\n3.Leader board\n4.Exit\n\nSelect number : ");
        int x;
        char xc[STR_LEN];
        gets(xc);
        fclose(game);
        if(xc[1]!='\0') //if the input is not 1 char
        {
            system("cls");
            printf("Error! ,Try Again\n\n");
            play(0);
        }
        x=xc[0]-'0'; //change the char to int
        if(x==1)
        {
            system("cls");
            load(0);
        }
        else if(x==2)
        {
            system("cls");
            fclose(fopen("game.txt", "w"));
            Grid(0);
        }
        else if(x==3)
        {
            printf("**Leaderboard**\n\n");
            leaderboard_list(0);
        }
        else if(x==4)
        {
            system("cls");
            exit1(0);
        }
        else
        {
            system("cls");
            printf("Error! ,Try Again\n\n");
            play(0);
        }
    }
}

#endif // PLAY_H_INCLUDED
