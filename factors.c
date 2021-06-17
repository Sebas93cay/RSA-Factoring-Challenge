
#include "head_factors.h"

void factor_big_number(void)
{
    printf("Calm down dude!\n");
}

void factor_small_number(char *buff)
{
    unsigned long long int i;
    unsigned long long int n;
    bool factored = false;

    n = strtol(buff, NULL, 10);
    if (n == 2)
    {
        printf("2=2*1\n");
        return;
    }
    if (n == 3)
    {
        printf("3=3*1\n");
        return;
    }
    if (n % 2 == 0)
        printf("%llu=%llu*2\n", n, n / 2);
    else if (n % 3 == 0)
        printf("%llu=%llu*3\n", n, n / 3);
    else
    {
        for (i = 6; (i - 1) * (i - 1) <= n; i += 6)
        {
            if (n % (i - 1) == 0)
            {
                printf("%llu=%llu*%llu\n", n, n / (i - 1), i - 1);
                factored = true;
                break;
            }
            else if (n % (i + 1) == 0)
            {
                printf("%llu=%llu*%llu\n", n, n / (i + 1), i + 1);
                factored = true;
                break;
            }
        }
        if (factored == false)
            printf("%llu=%llu*1\n", n, n);
    }
}

int main(int argc, char **argv)
{
    FILE *file = NULL;
    char *buff = NULL;
    size_t buff_size = 0;
    void *num = NULL;
    unsigned long long int n = 0;
    mpz_t ln;

    if (argc != 2)
        fprintf(stderr, "Usage factors <file>\n"), exit(1);

    mpz_init(ln);
    file = fopen(argv[1], "r");
    while (getline(&buff, &buff_size, file) != EOF)
    {
        if (strlen(buff) < 19)
            factor_small_number(buff);
        else
            factor_big_number();
    }
    free(buff);
    fclose(file);

    mpz_clear(ln);
    return (0);
}
