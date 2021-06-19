#include "head_factors.h"

void factor_big_number(char *buff)
{
    bool factored = false;
    mpz_t n, i, sqpow, remainder, division, aux_i;
    mpz_init_set_str(n, buff, 10);
    mpz_inits(sqpow, remainder, division, aux_i, NULL);
    // mpz_init_set_ui(i, 1000000002);
    mpz_init_set_ui(i, 2);
    buff[strlen(buff) - 1] = '\0';

    mpz_cdiv_r(remainder, n, i);
    if (mpz_cmp_ui(remainder, 0) == 0)
    {
        mpz_cdiv_q(division, n, i);
        printf("%s=", buff);
        mpz_out_str(stdout, 10, division);
        printf("*2\n");
        return;
    }

    mpz_set_str(i, "3", 10);
    mpz_cdiv_r(remainder, n, i);
    if (mpz_cmp_ui(remainder, 0) == 0)
    {
        mpz_cdiv_q(division, n, i);
        printf("%s=", buff);
        mpz_out_str(stdout, 10, division);
        printf("*3\n");
        return;
    }

    mpz_set_str(i, "6", 10);
    mpz_sub_ui(aux_i, i, 1);
    mpz_pow_ui(sqpow, aux_i, 2);

    while (mpz_cmpabs(n, sqpow) >= 0)
    {
        mpz_cdiv_r(remainder, n, aux_i);
        if (mpz_cmp_ui(remainder, 0) == 0)
        {
            mpz_cdiv_q(division, n, aux_i);
            printf("%s=", buff);
            mpz_out_str(stdout, 10, division);
            printf("*");
            mpz_out_str(stdout, 10, aux_i);
            printf("\n");
            factored = true;
            break;
        }
        mpz_sub_ui(aux_i, i, 1);
        mpz_cdiv_r(remainder, n, aux_i);
        if (mpz_cmp_ui(remainder, 0) == 0)
        {
            mpz_cdiv_q(division, n, aux_i);
            printf("%s=", buff);
            mpz_out_str(stdout, 10, division);
            printf("*");
            mpz_out_str(stdout, 10, aux_i);
            printf("\n");
            factored = true;
            break;
        }
        mpz_add_ui(i, i, 6);
        mpz_add_ui(aux_i, i, 1);
        mpz_pow_ui(sqpow, aux_i, 2);
    }
    if (!factored)
    {
        printf("%s=%s*1\n", buff, buff);
    }
    mpz_clears(n, sqpow, i, remainder, division, aux_i, NULL);
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

    if (argc != 2)
        fprintf(stderr, "Usage factors <file>\n"), exit(1);
    file = fopen(argv[1], "r");
    if (!file)
        fprintf(stderr, "file %s could not be opened\n", argv[1]), exit(1);
    while (getline(&buff, &buff_size, file) != EOF)
    {
        if (strlen(buff) < 20)
            factor_small_number(buff);
        else
            factor_big_number(buff);
    }
    free(buff);
    fclose(file);
    return (0);
}
