#ifndef INITIALIZATION_H_INCLUDED
#define INITIALIZATION_H_INCLUDED

void initialization(int r, int c, int M[][c], char G[][c], int V[][c], int C[], int R[])
{
    int i,j;
    for(i=0 ; i<r ; i++)
    {
        R[i] = i+1 ; //this array of the number of rows which guide the player
        for(j=0 ; j<c ; j++)
        {
            V[i][j]=0; //this matrix to check if the element has been visited or not
            M[i][j]=0; //this matrix where the mines distribute
            G[i][j]='X'; //this matrix which appears to the player
        }
    }
    for(j=0; j<c+1; j++)
    {
        C[j] = j ; //this array of the number of columns which guide the player
    }
}

#endif // INITIALIZATION_H_INCLUDED
