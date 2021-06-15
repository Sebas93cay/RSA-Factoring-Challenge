#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE *file = NULL;
    char *buff = NULL, *end_conf;
    size_t buff_size = 0;
    unsigned long long int n = 0;

    if (argc != 2)
        fprintf(stderr, "Usage factors <file>\n"), exit(1);

    file = fopen(argv[1], "r");
    while (getline(&buff, &buff_size, file) != EOF)
    {
        buff[strlen(buff) - 1] = 'a';
        end_conf = buff;
        n = strtol(buff, &end_conf, 10);
        printf("%s -> %llu\n", buff, n);
        printf("end: %s\n", end_conf);
    }

    return (0);
}
