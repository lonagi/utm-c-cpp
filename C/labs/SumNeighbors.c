#include <stdio.h>

//Среднее арфм. соседей

const int MK = 8;

float     matrix[][8] = {
               { 2, 7, 2, 7, 1, 4, 0, 3 },
               { 1, 0, 7, 6, 0, -8, 3, 5 },
               { 2, 7, 1, 8, 1, 4, 9, 3 },
               { 9, 2, 8, 5, 2, 0, 0, 6 },
               { 7, 1, 1, 3, 9, 3, 9, 1 },
               { 8, 2, 4, 9, 1, -6, 4, 9 },
               { 0, 3, 9, 0, 9, 4, 8, 8 },
               { 1, 8, 3, 2, 8, 2, 8, 0 }
               };
float     matrix2[8][8];

int     t;

void printMa(int a)
{
    for (int i = 0; i < MK; i++)
    {
        for (int j = 0; j < MK; j++)
        {
            if(a == 1) printf("%-6.2f ",matrix[i][j]);
            else printf("%-7.2f",matrix2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char* argv[])
{
    printMa(1);

    for (int i = 0; i < MK; i++)
    {
     for (int j = 0; j < MK; j++)
        {
            matrix2[i][j] = 0;
            t = 0;

            if(i != MK-1){
                matrix2[i][j] += matrix[i+1][j];
                t++;
            }
            if(i != 0){
                matrix2[i][j] += matrix[i-1][j];
                t++;
            }
            if(j != MK-1){
                matrix2[i][j] += matrix[i][j+1];
                t++;
            }
            if(j != 0){
                matrix2[i][j] += matrix[i][j-1];
                t++;
            }
            if(i != MK-1 && j != MK-1){
                matrix2[i][j] += matrix[i+1][j+1];
                t++;
            }
            if(i != MK-1 && j != 0){
                matrix2[i][j] += matrix[i+1][j-1];
                t++;
            }
            if(i != 0 && j != MK-1){
                matrix2[i][j] += matrix[i-1][j+1];
                t++;
            }
            if(i != 0 && j != 0){
                matrix2[i][j] += matrix[i-1][j-1];
                t++;
            }
            matrix2[i][j] /= t;
        }
    }

    printMa(0);

    return 0;
}