#include <stdio.h>
#include <stdlib.h>

#define N 8

//posibilitatile de miscare pe tabla de sah
int moveX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int moveY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int valid(int x, int y, int sol[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}


int solve(int x, int y, int movei, int sol[N][N])
{
    int nextX, nextY;

    if (movei == N * N)
        return 1;

    // incercam toate miscarile ale calului 
    for (int k = 0; k < 8; k++){
        nextX = x + moveX[k];
        nextY = y + moveY[k];
        if (valid(nextX, nextY, sol)) //verificam daca miscarea este valida (suntem pe pozitie existenta)
        {
            sol[nextX][nextY] = movei; //marcam pozitia
            if (solve(nextX, nextY, movei + 1, sol)) //verificam daca avem o solutie mai departe
                return 1;
            else
                sol[nextX][nextY] = -1; // in caz ca nu avem o solutie viitoare din aceasta pozitie
                                        // marcam pozitie de parca nici nu am fost aici si continuam mai departe din apelul precedent
        }
    }

    return 0;
}

void afis(int sol[N][N],int n){
    // Afisează soluția găsită
    for (int i = 0; i < n; i++)
    {   
        printf("|");
        for (int j = 0; j < n; j++)
            printf(" %3d |", sol[i][j]);
        printf("\n");
    }
}


int main(){
    int sol[N][N];
    int i=0,j=0;
    // initializam toata tabla cu -1 (prin conventie Calul inca nu a trecut prin pozitia -1)
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            sol[i][j] = -1;
    sol[0][0] = 0;

    // Începeți călătoria călătorului de la (0, 0)
    if (solve(0, 0, 1, sol) == 0)
    {
        printf("Nu există soluție.\n");
        return 0;
    }
    else
    {
        afis(sol,N);
        
    }

    return 0;
}