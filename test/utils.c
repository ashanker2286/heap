#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

time_t t;

int *uniq = NULL;

void initRandNumGen(void) {
        srand((unsigned) time(&t));
}

int randomNumGen(int num) {
        return rand() % num;
}


void initRandNumGenUniq(int numOfElements) {
	uniq = (int *) malloc(numOfElements * sizeof(int));	
	memset(uniq, 0, numOfElements * sizeof(int));
        srand((unsigned) time(&t));
}

int randomNumGenUniq(int num) {
        int ret = rand() % num;
	while (uniq[ret] != 0) {
       		ret = rand() % num;
	}
	uniq[ret] = 1;
	return ret;
}

void deinitRandNumGenUniq(void) {
	free(uniq);
	uniq = NULL;
}
