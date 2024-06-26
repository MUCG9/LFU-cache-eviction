#ifndef BAZA_H
#define BAZA_H

#include <stdio.h>
#include <stdlib.h>

#endif

#ifndef CREATE_H
#define CREATE_H

#include "create.h"

#endif

// Создание нового узла кэша с заданным ключом и значением
CacheNode* createNode(int key, int value)
{
    CacheNode* node = (CacheNode*)malloc(sizeof(CacheNode));
    node->key = key;
    node->value = value;
    node->freq = 1; // Частота использования по умолчанию равна 1
    node->prev = NULL;
    node->next = NULL;
    return node;
}

// Создание пустого кэша с заданной емкостью
Cache* createCache(int capacity)
{
    Cache* cache = (Cache*)malloc(sizeof(Cache));
    cache->capacity = capacity;
    cache->size = 0;
    cache->head = NULL;
    cache->tail = NULL;
    return cache;
}
