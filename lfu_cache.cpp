#ifndef BAZA_H
#define BAZA_H

#include <stdio.h>
#include <stdlib.h>

#endif //BAZA_H

#ifndef LFUCACHE_H
#define LFUCACHE_H

#include "lfu_cache.h"

#endif //LFUCACHE_H

// Удаление узла из кэша
void removeNode(Cache* cache, CacheNode* node) {
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
void insertHead(Cache* cache, CacheNode* node) {
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
void updateFrequency(Cache* cache, CacheNode* node) {
    node->freq++;
    CacheNode* current = node->prev;
    while (current && current->freq <= node->freq) {
        current = current->prev;
    }

    // РЈРґР°Р»СЏРµРј СѓР·РµР» РёР· С‚РµРєСѓС‰РµР№ РїРѕР·РёС†РёРё
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

    // Р’СЃС‚Р°РІР»СЏРµРј СѓР·РµР» РІ РЅРѕРІСѓСЋ РїРѕР·РёС†РёСЋ
    if (current) {
        node->next = current->next;
        node->prev = current;
        if (current->next) {
            current->next->prev = node;
        } else {
            cache->tail = node;
        }
        current->next = node;
    } else {
        node->next = cache->head;
        if (cache->head) {
            cache->head->prev = node;
        }
        cache->head = node;
        node->prev = NULL;
    }

    if (!node->next) {
        cache->tail = node;
    }
}

// РџРѕР»СѓС‡РµРЅРёРµ Р·РЅР°С‡РµРЅРёСЏ РїРѕ РєР»СЋС‡Сѓ РёР· РєСЌС€Р°
int get(Cache* cache, int key) {
    CacheNode* current = cache->head;
    while (current) {
        if (current->key == key) {
            updateFrequency(cache, current);
            return current->value;
        }
        current = current->next;
    }
    return -1; // РљР»СЋС‡ РЅРµ РЅР°Р№РґРµРЅ
}

// Р’СЃС‚Р°РІРєР° РЅРѕРІРѕРіРѕ Р·РЅР°С‡РµРЅРёСЏ РІ РєСЌС€
void put(Cache* cache, int key, int value) {
    CacheNode* current = cache->head;
    while (current) {
        if (current->key == key) {
            current->value = value;
            updateFrequency(cache, current);
            return;
        }
        current = current->next;
    }

    if (cache->size == cache->capacity) {
        // РЈРґР°Р»СЏРµРј СѓР·РµР» СЃ РЅР°РёРјРµРЅСЊС€РµР№ С‡Р°СЃС‚РѕС‚РѕР№
        removeNode(cache, cache->tail);
    }

    // Р’СЃС‚Р°РІР»СЏРµРј РЅРѕРІС‹Р№ СѓР·РµР»
    CacheNode* node = createNode(key, value);
    insertHead(cache, node);
}

//счётчик числа попаданий в кэш
int LFUCacheHits(int capacity, int n, int* requests)
{
    Cache* cache = createCache(capacity);
    int hits = 0;

    for (int i = 0; i < n; i++)
    {
        int page = requests[i];
        if (get(cache, page) != -1)
        {
            hits++;
        }
        else
        {
            put(cache, page, page);
        }
    }

    CacheNode* current = cache->head;
    while (current)
    {
        CacheNode* next = current->next;
        free(current);
        current = next;
    }

    free(cache);

    return hits;
}

