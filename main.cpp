#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m    = 0;
    int n    = 0;
    int hits = 0;

    if (scanf("%d %d", &m, &n) != 2) 
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

    hits = LFUCacheHits(m, n, requests);
    printf("%d\n", hits);

    free(requests);

    testCache();
    return 0;
}