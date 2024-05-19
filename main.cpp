#ifndef BAZA_H
#define BAZA_H

#include <stdio.h>
#include <stdlib.h>

#endif //BAZA_H


#ifndef STRUCT_H
#define STRUCT_H

#include "struct.h"

#endif //STRUCT_H


#ifndef LFUCACHE_H
#define LFUCACHE_H

#include "lfu_cache.h"

#endif //LFUCACHE_H

int IWANTTOHAVEATEST = 0;

#define TEST_H
#ifdef TEST_H

#include "test.h"
IWANTTOHAVEATEST = 1;

#endif //TEST_H

int main()
{
    int capacity = 0;
    int n        = 0;
    int hits     = 0;

    if (scanf("%d %d", &capacity, &n) != 2)
    {
        return 1;
    }

    int* requests = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &requests[i]) != 1) {
            free(requests);

            return 1;
        }
    }

    hits = LFUCacheHits(capacity, n, requests);
    printf("%d\n", hits);

    if (IWANTTOHAVEATEST == 1)
    {
        testCache();
    }

    free(requests);
    return 0;
}
