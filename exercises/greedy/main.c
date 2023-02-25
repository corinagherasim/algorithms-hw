/*
5. Se citesc de la tastatură două numere naturale n și k.Generați o matrice cu n linii și n coloane care să îndeplinească simultan următoarele condiții:
-conține toate numerele naturale de la 1 la n2, fiecare număr luat o singură dată
-pe fiecare linie elementele sunt așezate crescător de la stânga la dreapta
-suma elementelor de pe o coloană k să fie minimă
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, a[100][100], i, j, cnt=1;
    scanf("%d %d", &n, &k);
    for(i=0;i<n;i++)
        for(j=0;j<k;j++)
    {
        a[i][j]=cnt;
        cnt++;
    }
    for(i=0;i<n;i++)
        for(j=k;j<n;j++)
    {
        a[i][j]=cnt;
        cnt++;
    }
    for(i=0;i<n;i++,printf("\n"))
        for(j=0;j<n;j++)
            printf("%d ", a[i][j]);
    return 0;
}
