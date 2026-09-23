#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int diagonalDifference(int n, int arr[MAX][MAX])
{
    int d1 = 0;
    int d2 = 0;

    for (int i = 0; i < n; i++)
    {
        d1 += arr[i][i];
        d2 += arr[i][n - 1 - i];
    }

    return abs(d1 - d2);
}

int main(void)
{
    int n;

    scanf("%d", &n);

    int arr[MAX][MAX];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    }

    printf("%d\n", diagonalDifference(n, arr));

    return 0;
}