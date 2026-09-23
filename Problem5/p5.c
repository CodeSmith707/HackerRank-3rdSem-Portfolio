#include <stdio.h>
#include <string.h>

#define MAX_LEN 21
#define MAX 100
int main(void)
{
    int n, q;

    scanf("%d", &n);

    char strings[MAX][MAX_LEN];

    for (int i = 0; i < n; i++)
        scanf("%s", strings[i]);

    scanf("%d", &q);

    char query[MAX_LEN];

    for (int i = 0; i < q; i++)
    {
        int count = 0;

        scanf("%s", query);

        for (int j = 0; j < n; j++)
        {
            if (strcmp(query, strings[j]) == 0)
                count++;
        }

        printf("%d\n", count);
    }

    return 0;
}