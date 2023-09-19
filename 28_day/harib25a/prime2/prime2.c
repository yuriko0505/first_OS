#include "../libapi.h"
#include "../mylib.h"

#define MAX 10000

void HariMain(void) {
    char flag[MAX], s[8];
    int i, j;
    for (i = 0; i < MAX; i++) {
        flag[i] = 0;
    }

    /* Sieve of Eratosthenes */
    for (i = 2; i < MAX; i++) {
        if (flag[i] == 0) {
            /* 印がついていなければ素数 */
            sprintf(s, "%d ", i);
            api_putstr0(s);
            for (j = i * 2; j < MAX; j += i) { 
                flag[j] = 1;
            }
        }
    }
    api_end();
}