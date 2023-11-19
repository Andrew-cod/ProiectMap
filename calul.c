#include <stdio.h>
#include <stdlib.h>

// posibilitatile de miscare pe tabla de sah
int moveX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int moveY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void afis(int n, int **sol)
{
    // Afisează soluția găsită
    for (int i = 0; i < n; i++)
    {
        printf("|");
        for (int j = 0; j < n; j++)
            printf(" %3d |", sol[i][j]);
        printf("\n");
    }
    printf("\n\n");
}

int valid(int x, int y, int n, int **sol)
{
    return (x >= 0 && x < n && y >= 0 && y < n && sol[x][y] == -1);
}

int solve(int x, int y, int n, int movei, int **sol)
{
    int nextX, nextY;
    if (movei == n * n)
        return 1;
    // incercam toate miscarile ale calului
    for (int k = 0; k < 8; k++)
    {
        nextX = x + moveX[k];
        nextY = y + moveY[k];
        if (valid(nextX, nextY, n, sol)) // verificam daca miscarea este valida (suntem pe pozitie existenta)
        {
            sol[nextX][nextY] = movei;                  // marcam pozitia
            if (solve(nextX, nextY, n, movei + 1, sol)) // verificam daca avem o solutie mai departe
                return 1;
            else
            {
                sol[nextX][nextY] = -1; // in caz ca nu avem o solutie viitoare din aceasta pozitia
            } // marcam pozitie de parca nici nu am fost aici si continuam mai departe din apelul precedent
        }
    }
    return 0;
}

int cifra(char x)
{
    return (x >= '0' && x <= '9');
}

int citeste_n()
{
    int n = 0;
    char x;

    do
    {
        scanf("%c", &x);
    } while (!cifra(x));

    while (cifra(x))
    {
        n = n * 10 + (int)(x - 48);
        scanf("%c", &x);
    }
    return n;
}

int main()
{
    int n = 0, x, y;

    printf("(Tasteaza 0 pentru a iesi din program:\n");
    printf("Dimensiunea table de sah N*N:");

    n = citeste_n();
    if (n == 0)
        return 0;

    // alocare dinamica de memorie
    int **sol = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
        sol[i] = (int *)malloc(sizeof(int) * n);

    int i = 0, j = 0;
    // initializam toata tabla cu -1 (prin conventie Calul inca nu a trecut prin pozitia -1)
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            sol[i][j] = -1;

    int contor = 0;
    do
    {
        printf("Pozitia de start (x y): ");
        // trebuie si aici validare
        x = citeste_n();
        y = citeste_n();
        contor++;
        if (contor >= 3)
        {
            printf("Pozitiile introduse trebuie sa fie valide (Mai mici decat dimesiunea tablei de sah si nenegative), mai incercati odata\n\n");
            // eliberare de memorie
            for (int i = 0; i < n; i++)
            {
                free(sol[i]);
            }
            free(sol);

            main(); // restartarea programului
            return 0;
        }
    } while (!valid(x, y, n, sol));

    sol[x][y] = 0;

    // Începeți călătoria călătorului de la (0, 0)
    if (solve(x, y, n, 1, sol) == 0)
    {
        printf("Nu există soluție.\nIncercati cu alte date de intrare\n\n\n");
        for (int i = 0; i < n; i++)
        {
            free(sol[i]);
        }
        free(sol);

        main(); // restartarea
        return 0;
    }
    else
    {
        afis(n, sol);
    }

    // eliberare de memorie
    for (int i = 0; i < n; i++)
    {
        free(sol[i]);
    }
    free(sol);

    return 0;
}