#ifndef BAZA_H
#define BAZA_H

#include <stdio.h>
#include <stdlib.h>

#endif //BAZA_H

#ifndef LFUCACHE_H
#define LFUCACHE_H

#include "lfu_cache.h"

#endif //LFUCACHE_H

void removeNode(Cache* cache, CacheNode* node)
{
    if (node->prev) {
        node->prev->next = node->next;
    } else {
        cache->head = node->next;
    }
    if (node->next) {
        node->next->prev = node->prev;
    } else {
        cache->tail = node->prev;
    }
    free(node);
    cache->size--;
}

// Вставка узла в начало кэша
void insertHead(Cache* cache, CacheNode* node)
{
    node->next = cache->head;
    node->prev = NULL;
    if (cache->head) {
        cache->head->prev = node;
    } else {
        cache->tail = node;
    }
    cache->head = node;
    cache->size++;
}

// Обновление частоты использования узла
void updateFrequency(Cache* cache, CacheNode* node)
{
    node->freq++;
    if (node->next && node->next->freq <= node->freq)
    {
        // Удаляем узел из текущей позиции
        removeNode(cache, node);
        // Ищем новую позицию для узла
        CacheNode* current = cache->head;

        while (current && current->freq <= node->freq)
        {
            current = current->next;
        }
        // Вставляем узел перед current
        node->next = current;

        if (current)
        {
            node->prev = current->prev;
            current->prev = node;
        }
        else
        {
            node->prev = cache->tail;
            cache->tail = node;
        }

        if (node->prev)
        {
            node->prev->next = node;
        }
        else
        {
            cache->head = node;
        }
    }
}

// Получение значения по ключу из кэша
int get(Cache* cache, int key)
{
    CacheNode* current = cache->head;
    while (current)
    {
        if (current->key == key)
        {
            updateFrequency(cache, current);
            return current->value;
        }
        current = current->next;
    }
    return -1; // Ключ не найден
}

// Вставка нового значения в кэш
void put(Cache* cache, int key, int value)
{
    CacheNode* current = cache->head;
    while (current)
    {
        if (current->key == key)
        {
            current->value = value;
            updateFrequency(cache, current);
            return;
        }
        current = current->next;
    }

    if (cache->size == cache->capacity)
    {
        // Удаляем узел с наименьшей частотой
        removeNode(cache, cache->tail);
    }
    // Вставляем новый узел
    CacheNode* node = createNode(key, value);
    insertHead(cache, node);
}
