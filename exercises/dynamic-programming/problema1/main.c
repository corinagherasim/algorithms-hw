/*
1.Se dau două șiruri de caractere s și t. Asupra șirului s se pot aplica în mod repetat operațiile:
●șterge un caracter
●inserează un caracter
●modifică un caracter
Pornind de la șirul s se cere să se obțină șirul t aplicând de un număr minim de orioperațiile date.
Se va afisa numarul total de opratii efectuate şi operaţiile propriu-zise care  trebuie efectuate asupra primului cuvânt pentru a îl obţine pe al doilea.
*/

#include <stdio.h>
#include <stdlib.h>

int matr[105][105], n, m;
char s[105], t[105];

int main()
{
    FILE *f= fopen("date.in", "r");
    FILE *g= fopen("date.out", "w");
    int i, j;
    fscanf (f, "%s %s", (s+1), (t+1));
    n = strlen(s + 1);
    m = strlen(t + 1);
    for (i = 1; i <= n; i++)
        matr[i][0] = i;
    for (j = 1; j <= m; j++)
        matr[0][j] = j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            {
            int min = n;
            if ((1+matr[i-1][j]) < min)
                min = 1+matr[i-1][j];
            if ((1+matr[i][j-1]) < min)
                min = 1+matr[i][j-1];
            if ((matr[i-1][j-1] + (s[i] != t[j])) < min)
                min = matr[i-1][j-1] + (s[i] != t[j]);
            matr[i][j] = min;
            }
    fprintf (g,"%d \n",matr[n][m]);

    i=1;
    j=1;
    while(i<n && j<m)
    {
        int minim=matr[i+1][j+1];
        if(matr[i+1][j]<matr[i][j+1] && matr[i+1][j]<matr[i+1][j+1])
            minim=matr[i+1][j];
        else
            if(matr[i][j+1]<matr[i+1][j] && matr[i][j+1]<matr[i+1][j+1])
                    minim=matr[i][j+1];
        if(minim==matr[i+1][j+1])
        {
            if((minim==matr[i][j] && s[i]!=t[j]) || (minim!=matr[i][j] && s[i]!=t[j]))
                fprintf (g,"Inlocuim %c - %c \n", s[i], t[j]);
            else
                fprintf (g,"Patram %c \n", s[i]);
            i++;
            j++;
        }
        else
        {
            if(minim==matr[i+1][j])
                {
                if(minim==matr[i][j])
                    fprintf (g,"Stergem %c \n", s[i]);
                i++;
                }
            else
                if(minim==matr[i][j+1])
                    {
                    if(minim==matr[i][j])
                        fprintf (g,"Patram %c \n", s[i]);
                    else
                        fprintf (g,"Inseram %c \n", s[i]);
                    j++;
                    }
        }
    }
    while(i==n && j<=m)
        {
            if(s[i]==t[j])
            {
                fprintf (g,"Patram %c \n", s[i]);
                j++;
            }
            else
                if(s[i]!=t[j])
                    {
                        fprintf (g,"Inlocuim %c - %c \n", s[i], t[j]);
                        j++;
                    }
            while(j<=m)
            {
                fprintf (g,"Inseram %c \n", t[j]);
                j++;
            }
        }
        while(j==m && i<=n)
        {
            if(s[i]==t[j])
            {
    			fprintf (g,"Patram %c \n", s[i]);
                i++;
            }
            else
            {
                fprintf (g,"Inlocuim %c - %c \n", s[i], t[j]);
                i++;
                while(i<=n)
                {
                    fprintf (g,"Stergem %c \n", s[i]);
                    i++;
                }
            }
        }
    return 0;
}
