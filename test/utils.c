#include <time.h>
#include <stdio.h>
#include <stdlib.h>

time_t t;

void initRandNumGen(void) {
        srand((unsigned) time(&t));
}

int randomNumGen(int num) {
        return rand() % num;
}

