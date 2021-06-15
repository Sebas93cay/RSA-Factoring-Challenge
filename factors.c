
#include "head_factors.h"

void str2llu(char *buff, unsigned long long int *n)
{
    int number_lenght;
    char lost_digit;

    number_lenght = strlen(buff) - 1;

    if (number_lenght <= NUMBER_FRAC_SIZE)
    {
        n[1] = strtol(buff, NULL, 10);
        n[0] = 0;
    }
    else
    {
        n[1] = strtol(buff + number_lenght - NUMBER_FRAC_SIZE, NULL, 10);
        lost_digit = buff[number_lenght - NUMBER_FRAC_SIZE];
        buff[number_lenght - NUMBER_FRAC_SIZE] = '\0';
        n[0] = strtol(buff, NULL, 10);
        buff[number_lenght - NUMBER_FRAC_SIZE] = lost_digit;
    }
}

char *llu2str(unsigned long long int *n)
{
    char *number_text = NULL;
    unsigned int i, counter = 0;

    number_text = calloc(LLINT_ARRAY_SIZE * NUMBER_FRAC_SIZE, sizeof(char));
    if (number_text == NULL)
        return (NULL);

    for (i = 0; i < LLINT_ARRAY_SIZE; i++)
        lu2str(n[i], number_text, &counter);

    return (number_text);
}

void lu2str(unsigned long long int n, char *buff, unsigned int *counter)
{
    int digit;

    if (n == 0)
        return;

    digit = n % 10;
    n = n / 10;
    lu2str(n, buff, counter);
    buff[*counter] = digit + '0';
    *counter += 1;
}

int main(int argc, char **argv)
{
    FILE *file = NULL;
    char *buff = NULL, *number_str;
    size_t buff_size = 0;
    unsigned long long int n_array[LLINT_ARRAY_SIZE] = {0, 0};

    if (argc != 2)
        fprintf(stderr, "Usage factors <file>\n"), exit(1);

    file = fopen(argv[1], "r");
    while (getline(&buff, &buff_size, file) != EOF)
    {
        str2llu(buff, n_array);
        number_str = llu2str(n_array);
        printf("%s -> %s\n", buff, number_str);
    }
    free(buff);
    free(number_str);
    return (0);
}
