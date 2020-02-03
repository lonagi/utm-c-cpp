#include <stdio.h>

const int MK = 8;

//Сдвигать по часовой стрелке строки-столбцы-строки...

int     matrix[][8] = {
               { 2, 7, 2, 7, 1, 4, 0, 3 },
               { 1, 0, 7, 6, 0, -8, 3, 5 },
               { 2, 7, 1, 8, 1, 4, 9, 3 },
               { 9, 2, 8, 5, 2, 0, 0, 6 },
               { 7, 1, 1, 3, 9, 3, 9, 1 },
               { 8, 2, 4, 9, 1, -6, 4, 9 },
               { 0, 3, 9, 0, 9, 4, 8, 8 },
               { 1, 8, 3, 2, 8, 2, 8, 0 }
               };
int     k, t, t2;

void printMa()
{
    for (int i = 0; i < MK; i++)
    {
        for (int j = 0; j < MK; j++)
        {
            printf("%2d ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void makeOffset(int jak)
{
    t2 = matrix[0+jak][MK-1-jak];
    for (int i = MK-1-jak; i > 0+jak; i--)
    {
        matrix[0+jak][i] = matrix[0+jak][i-1];
    }
    matrix[0+jak][0+jak] = t2;

    t2 = matrix[MK-1-jak][MK-1-jak];
    for (int i = MK-1-jak; i > 0+jak; i--)
    {
        matrix[i][MK-1-jak] = matrix[i-1][MK-1-jak];
    }
    matrix[1+jak][MK-1-jak] = matrix[0+jak][0+jak];
    matrix[0+jak][0+jak] = t2;

    t2 = matrix[MK-1-jak][0+jak];
    for (int i = 0+jak; i < MK-2-jak; i++)
    {
        matrix[MK-1-jak][i] = matrix[MK-1-jak][i+1];
    }
    matrix[MK-1-jak][MK-2-jak] = matrix[0+jak][0+jak];
    
    for (int i = 0+jak; i < MK-1-jak; i++)
    {
        matrix[i][0+jak] = matrix[i+1][0+jak];
    }
    matrix[MK-2-jak][0+jak] = t2;

}

int main(int argc, char* argv[])
{
    printMa();

    printf("k =");
    scanf("%i",&k);
    printf("\n");

    for (int j = 0; j < MK/2; j++)
    {
        for (int i = 0; i < k; i++)
        {
                makeOffset(j);
        }
    }

    printMa();

    return 0;
}