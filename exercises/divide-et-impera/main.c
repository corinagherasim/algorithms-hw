/*4. Se dau n numere naturale. Să se afișeze al k-ulea lea cel mai mic element din șir.

Date de intrare: fisierul date.in contine:

pe prima linie un număr natural n și un număr natural k și

pe a doua linie, un șir de n numere naturale, separate prin câte un spațiu.

Date de ieșire: fișierul date.out conține valoarea cerută.
*/


#include <stdio.h>
#include <stdlib.h>

int divimp(int t[], int st, int dr)
{
    int mij, sol_st, sol_dr;
    if(st == dr)
        return st;
    else
        {
            mij = (st + dr)/2;
            sol_st = divimp(t, st, mij);
            sol_dr = divimp(t, mij + 1, dr);
            if (t[sol_st] < t[sol_dr])
                return sol_st;
            else
                return sol_dr;
        }
}

int max(int t[], int n)
{
    int i, max=-1;
    for (i=0; i<n; i++)
    {
        if (t[i]>max)
            max=t[i];
    }
    return max;
}

int main()
{
    FILE *f= fopen("date.in", "r");
    FILE *g= fopen("date.out", "w");
    int i, n, k, t[1000];
    fscanf(f,"%d %d", &n, &k);
    for (i=0; i<n; i++)
        fscanf(f,"%d", &t[i]);
    int c, sol, st, dr, maxi;
    maxi=max(t,n);
    for (i=0; i<k; i++)
    {
        st=0;
        dr=n-1;
        c= divimp(t, st, dr);
        sol=t[c];
        t[c]=maxi+1;


    }
    fprintf(g, "%d", sol);
    return 0;
}
