#ifndef FACTORS_H
#define FACTORS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_FRAC_SIZE 18
#define LLINT_ARRAY_SIZE 2

void str2llu(char *buff, unsigned long long int *n);
char *llu2str(unsigned long long int *n);
void lu2str(unsigned long long int n, char *buff, unsigned int *counter);

#endif
