#include<stdio.h>

int max(int a, int b)
{
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

int knapsack(int S, int n, int s[], int v[])
{
    int V[n + 1][S + 1];
    int i, si;

    for (i = 0; i <= n; i++)
    {
        for (si = 0; si <= S; si++)
        {
            if (i == 0 || si == 0)
            {
                V[i][si] = 0;
            }
            else if (s[i - 1] <= si)
            {
                V[i][si] = max(v[i - 1] + V[i - 1][si - s[i - 1]], V[i - 1][si]);
            }
            else
            {
                V[i][si] = V[i - 1][si];
            }
        }
    }

    return V[n][S];
}

int main()
{
    int S = 8;
    int n = 6;
    int s[] = {2, 3, 4, 5, 6, 7};
    int v[] = {1, 4, 5, 7, 8, 9};
    int value = knapsack(S, n, s, v);

    printf("Maximum value is: %d\n", value);

    return 0;
}
