
#include "head_factors.h"

int num_substract
{
    return (1);
}

int bitwiseadd(void *x, void *y)
{
    while (y != 0)
    {
        int carry = x & y;
        x = x ^ y;
        y = carry << 1;
    }
    return x;
}

void *new_num_memory(void)
{
    void *num = NULL;

    num = calloc(NUM_BYTES, 1);
    if (!num)
        exit(1);
    return (num);
}

int main(int argc, char **argv)
{
    FILE *file = NULL;
    char *buff = NULL;
    size_t buff_size = 0;
    void *num = NULL;

    // if (argc != 2)
    //     fprintf(stderr, "Usage factors <file>\n"), exit(1);
    // num = new_num_memory();
    // file = fopen(argv[1], "r");
    // while (getline(&buff, &buff_size, file) != EOF)
    // {
    // }
    // free(buff);
    // fclose(file);

    return (0);
}
