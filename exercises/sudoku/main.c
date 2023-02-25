/* 1.Soluții pentru Sudoku.*/

#include <stdio.h>
#include <stdlib.h>

int sudoku[9][9];

void afisare()
{
     for (int i=0;i<9;i++,printf("\n"))
         for (int j=0;j<9;j++)
            printf("%d ",sudoku[i][j]);
}

int verificare(int linie, int coloana, int num)
{
    for (int x=0;x<=8;x++)
        if (sudoku[linie][x]==num)
            return 0;

    for (int x=0;x<=8;x++)
        if (sudoku[x][coloana]==num)
            return 0;

    int startlinie=linie-linie%3, startcoloana=coloana-coloana%3;

    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            if (sudoku[i+startlinie][j+startcoloana]==num)
                return 0;

    return 1;
}


int rezolvare(int linie, int coloana)
{
    if (linie==8&&coloana==9)
        return 1;

    if (coloana == 9)
    {
        linie++;
        coloana=0;
    }
    if (sudoku[linie][coloana]>0)
        return rezolvare(linie,coloana + 1);

    for (int num=1;num<=9;num++)
    {
        if (verificare(linie,coloana,num)==1)
        {
            sudoku[linie][coloana]=num;

            if (rezolvare(linie,coloana+1)==1)
                return 1;
        }
        sudoku[linie][coloana]=0;
    }
    return 0;
}

int main()
{
    FILE *f = fopen("date.txt","r");
    for (int i=0;i<9;i++)
        for (int j=0;j<9;j++)
            fscanf(f,"%d", &sudoku[i][j]);
    if (rezolvare(0,0)==1)
        afisare(sudoku);
    else
        printf("Nu exista solutii.");

    return 0;
}
