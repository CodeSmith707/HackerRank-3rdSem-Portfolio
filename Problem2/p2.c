#include <stdio.h>
#include <stdlib.h>

struct array
{
    int *data;
    int size;
    int capacity;
};

int main(void)
{
    int n, q;

    scanf("%d %d", &n, &q);

    struct array *seq = calloc(n, sizeof(struct array));

    int *answers = malloc(q * sizeof(int));
    int answer_count = 0;

    int last_answer = 0;

    for (int i = 0; i < q; i++)
    {
        int type, x, y;

        scanf("%d %d %d", &type, &x, &y);

        int index = (x ^ last_answer) % n;

        if (type == 1)
        {
            if (seq[index].size == seq[index].capacity)
            {
                if (seq[index].capacity == 0)
                    seq[index].capacity = 2;
                else
                    seq[index].capacity *= 2;

                seq[index].data = realloc(
                    seq[index].data,
                    seq[index].capacity * sizeof(int)
                );
            }

            seq[index].data[seq[index].size] = y;
            seq[index].size++;
        }
        else if (type == 2)
        {
            last_answer =
                seq[index].data[y % seq[index].size];

            answers[answer_count] = last_answer;
            answer_count++;
        }
    }

    for (int i = 0; i < answer_count; i++)
        printf("%d\n", answers[i]);

    for (int i = 0; i < n; i++)
        free(seq[i].data);

    free(seq);
    free(answers);

    return 0;
}