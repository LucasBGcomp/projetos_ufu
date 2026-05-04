#include <stdio.h>
#include "bib.h"

int soma(int n, int M[n][n])
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += M[i][j];
        }
    }
    return sum;
}

int soma_dp(int n, int M[n][n])
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += M[i][i];
    }
    return sum;
}

int soma_ds(int n, int M[n][n])
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += M[i][n - 1 - i];
    }
    return sum;
}

int is_simetrica(int n, int M[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (M[i][j] != M[j][i])
            {
                return 0;
            }
        }
    }
    return 1;
}

int soma_uma_linha(int k, int n, int M[n][n])
{
    int sum = 0;
    for (int j = 0; j < n; j++)
    {
        sum += M[k][j];
    }
    return sum;
}

int soma_uma_coluna(int k, int n, int M[n][n])
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += M[i][k];
    }
    return sum;
}

int is_qm(int n, int M[n][n])
{
    int soma_ref = soma_dp(n, M);
    for (int i = 0; i < n; i++)
    {
        if (soma_uma_linha(i, n, M) != soma_ref || soma_uma_coluna(i, n, M) != soma_ref)
        {
            return 0;
        }
    }

    if (soma_ds(n, M) != soma_ref)
    {
        return 0;
    }

    return 1;
}