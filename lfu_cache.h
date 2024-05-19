#ifndef BAZA_H
#define BAZA_H

#include <stdio.h>
#include <stdlib.h>

#endif //BAZA_H


#ifndef STRUCT_H
#define STRUCT_H

#include "struct.h"

#endif //STRUCT_H


#ifndef CREATE_H
#define CREATE_H

#include "create.h"

#endif //CREATE_H


// Удаление узла из кэша
void removeNode(Cache* cache, CacheNode* node);

// Вставка узла в начало кэша
void insertHead(Cache* cache, CacheNode* node);

// Обновление частоты использования узла
void updateFrequency(Cache* cache, CacheNode* node);

// Вставка нового значения в кэш
void put(Cache* cache, int key, int value);

// Получение значения по ключу из кэша
int get(Cache* cache, int key);

//счётчик числа попаданий в кэш
int LFUCacheHits(int capacity, int n, int* requests);
