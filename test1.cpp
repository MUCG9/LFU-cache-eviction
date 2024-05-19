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

// ������� ������������ ����
void testCache() {
    Cache* cache = createCache(3);
    put(cache, 1, 10);
    put(cache, 2, 20);
    put(cache, 3, 30);

    printf("Znachenie dlya key 1: %d\n", get(cache, 1));
    put(cache, 4, 40);

    printf("Znachenie dlya key 2: %d\n", get(cache, 2));
    printf("Znachenie dlya key 3: %d\n", get(cache, 3));
    printf("Znachenie dlya key 4: %d\n", get(cache, 4));

    put(cache, 5, 50);
    printf("Znachenie dlya key 1: %d\n", get(cache, 1));
    printf("Znachenie dlya key 3: %d\n", get(cache, 3));
    printf("Znachenie dlya key 5: %d\n", get(cache, 5));
}

int main() {
    testCache();
    getchar();
    return 0;
}
