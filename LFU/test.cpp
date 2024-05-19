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

#ifndef TEST_H
#define TEST_H

#include "test.h"

#endif //TEST_H


void testCache() {
    Cache* cache = createCache(3);

    put(cache, 1, 10);
    put(cache, 2, 20);
    put(cache, 3, 30);
    printf("Test 1: Value for key 1: %d (Expected: 10)\n", get(cache, 1)); // Должен вернуть 10

    put(cache, 4, 40); // Должен удалить ключ 2
    printf("Test 2: Value for key 2: %d (Expected: -1)\n", get(cache, 2)); // Должен вернуть -1 (не найдено)

    printf("Test 3: Value for key 3: %d (Expected: 30)\n", get(cache, 3)); // Должен вернуть 30
    printf("Test 4: Value for key 4: %d (Expected: 40)\n", get(cache, 4)); // Должен вернуть 40

    put(cache, 3, 35); // Обновить значение для ключа 3
    printf("Test 5: Value for key 3: %d (Expected: 35)\n", get(cache, 3)); // Должен вернуть 35

    put(cache, 5, 50); // Должен удалить ключ 1, так как у него наименьшая частота
    printf("Test 6: Value for key 1: %d (Expected: -1)\n", get(cache, 1)); // Должен вернуть -1 (не найдено)
    printf("Test 7: Value for key 4: %d (Expected: 40)\n", get(cache, 4)); // Должен вернуть 40
    printf("Test 8: Value for key 5: %d (Expected: 50)\n", get(cache, 5)); // Должен вернуть 50

    put(cache, 6, 60); // Должен удалить ключ 4, так как у него наименьшая частота
    printf("Test 9: Value for key 4: %d (Expected: -1)\n", get(cache, 4)); // Должен вернуть -1 (не найдено)
    printf("Test 10: Value for key 3: %d (Expected: 35)\n", get(cache, 3)); // Должен вернуть 35
    printf("Test 11: Value for key 5: %d (Expected: 50)\n", get(cache, 5)); // Должен вернуть 50
    printf("Test 12: Value for key 6: %d (Expected: 60)\n", get(cache, 6)); // Должен вернуть 60

    put(cache, 7, 70); // Должен удалить ключ 3, так как у него наименьшая частота
    printf("Test 13: Value for key 3: %d (Expected: -1)\n", get(cache, 3)); // Должен вернуть -1 (не найдено)
    printf("Test 14: Value for key 5: %d (Expected: 50)\n", get(cache, 5)); // Должен вернуть 50
    printf("Test 15: Value for key 6: %d (Expected: 60)\n", get(cache, 6)); // Должен вернуть 60
    printf("Test 16: Value for key 7: %d (Expected: 70)\n", get(cache, 7)); // Должен вернуть 70

    put(cache, 8, 80); // Должен удалить ключ 5, так как у него наименьшая частота
    printf("Test 17: Value for key 5: %d (Expected: -1)\n", get(cache, 5)); // Должен вернуть -1 (не найдено)
    printf("Test 18: Value for key 6: %d (Expected: 60)\n", get(cache, 6)); // Должен вернуть 60
    printf("Test 19: Value for key 7: %d (Expected: 70)\n", get(cache, 7)); // Должен вернуть 70
    printf("Test 20: Value for key 8: %d (Expected: 80)\n", get(cache, 8)); // Должен вернуть 80
}