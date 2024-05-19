#ifndef BAZA_H
#define BAZA_H

#include <stdio.h>
#include <stdlib.h>

#endif //BAZA_H

#ifndef SYSTIME_H
#define SYSTIME_H

#include <sys/time.h>

#endif //SYSTIME_H

#ifndef STRUCT_H
#define STRUCT_H

#include "struct.h"

#endif //STRUCT_H


#ifndef LFUCACHE_H
#define LFUCACHE_H

#include "lfu_cache.h"

#endif //LFUCACHE_H

int main()
{
    struct timeval start, end;
    double elapsed;

    int capacity = 0;
    int n        = 0;
    int hits     = 0;

    while (scanf("%d %d", &capacity, &n) == 2)
    {
        int* requests = (int*)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
        {
            if (scanf("%d", &requests[i]) != 1) {
                free(requests);

                return 1;
            }
        }

        gettimeofday(&start, NULL);
        hits = LFUCacheHits(capacity, n, requests);
        gettimeofday(&end, NULL);

        printf("%d\n", hits);

        elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
        printf("%f\n", elapsed);

        free(requests);
    }

    return 0;
}
