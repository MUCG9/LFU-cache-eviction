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
// Функция удаляет узел `node` из двусвязного списка кэша `cache`.
void removeNode(Cache* cache, CacheNode* node) 
{
    // Если есть предыдущий узел, устанавливаем его указатель next на следующий узел
    if (node->prev) 
    {
        node->prev->next = node->next;
    } 
    else // Если удаляемый узел первый, меняем указатель head кэша
    {
        cache->head = node->next;
    }

    // Если есть следующий узел, устанавливаем его указатель prev на предыдущий узел
    if (node->next) 
    {
        node->next->prev = node->prev;
    } 
    else // Если удаляемый узел последний, меняем указатель tail кэша
    {
        cache->tail = node->prev;
    }

    // Освобождаем память, занимаемую узлом
    free(node);
    cache->size--; // Уменьшаем размер кэша
}

// Вставка узла в начало кэша
// Функция добавляет узел `node` в начало двусвязного списка кэша `cache`.
void insertHead(Cache* cache, CacheNode* node) 
{
    // Устанавливаем указатели узла на текущую голову кэша
    node->next = cache->head;
    node->prev = NULL;

    // Если кэш не пустой, устанавливаем указатель prev текущей головы на новый узел
    if (cache->head) 
    {
        cache->head->prev = node;
    } 
    else // Если кэш пустой, устанавливаем tail на новый узел
    {
        cache->tail = node;
    }

    // Устанавливаем новый узел как голову кэша
    cache->head = node;
    cache->size++; // Увеличиваем размер кэша
}

// Обновление частоты использования узла
// Функция увеличивает частоту использования узла `node` и перемещает его на новое место в кэше `cache` в соответствии с новой частотой.
void updateFrequency(Cache* cache, CacheNode* node) 
{
    node->freq++; // Увеличиваем частоту использования узла
    CacheNode* current = node->prev;

    // Ищем позицию для узла с учетом обновленной частоты
    while (current && current->freq <= node->freq) 
    {
        current = current->prev;
    }

    // Удаляем узел из текущей позиции
    if (node->prev) 
    {
        node->prev->next = node->next;
    } 
    else 
    {
        cache->head = node->next;
    }

    if (node->next) 
    {
        node->next->prev = node->prev;
    } 
    else 
    {
        cache->tail = node->prev;
    }

    // Вставляем узел в новую позицию, найденную ранее
    if (current) 
    {
        node->next = current->next;
        node->prev = current;

        if (current->next) 
        {
            current->next->prev = node;
        } 
        else 
        {
            cache->tail = node;
        }
        current->next = node;
    } 
    else // Если узел должен стать новым началом списка
    {
        node->next = cache->head;

        if (cache->head) 
        {
            cache->head->prev = node;
        }

        cache->head = node;
        node->prev = NULL;
    }

    // Если узел оказался в конце списка, обновляем tail
    if (!node->next) {
        cache->tail = node;
    }
}

// Получение значения по ключу из кэша
// Функция ищет узел с ключом `key` в кэше `cache`.
// Если узел найден, увеличивает его частоту и возвращает его значение.
// Иначе возвращает -1.
int get(Cache* cache, int key) 
{
    CacheNode* current = cache->head;

    // Поиск узла с заданным ключом
    while (current) 
    {
        if (current->key == key) 
        {
            updateFrequency(cache, current); // Увеличиваем частоту использования узла
            return current->value; // Возвращаем значение узла
        }
        current = current->next;
    }

    return -1; // Ключ не найден
}

// Вставка нового значения в кэш
// Функция вставляет новый узел с ключом `key` и значением `value` в кэш `cache`.
// Если узел с таким ключом уже существует, обновляет его значение и увеличивает частоту.
// Если кэш заполнен, удаляет узел с наименьшей частотой.
void put(Cache* cache, int key, int value)
{
    CacheNode* current = cache->head;

    // Поиск узла с заданным ключом
    while (current) 
    {
        if (current->key == key) 
        {
            current->value = value; // Обновляем значение
            updateFrequency(cache, current); // Увеличиваем частоту использования узла
            return;
        }
        current = current->next;
    }

    // Если кэш заполнен, удаляем узел с наименьшей частотой
    if (cache->size == cache->capacity) 
    {
        removeNode(cache, cache->tail);
    }

    // Создаем новый узел и вставляем его в начало кэша
    CacheNode* node = createNode(key, value);
    insertHead(cache, node);
}

// Основная функция для подсчета количества попаданий в кэш
// Функция создает кэш с заданной емкостью `capacity`, обрабатывает запросы из массива `requests` и возвращает количество попаданий в кэш.
int LFUCacheHits(int capacity, int n, int* requests)
{
    // Создаем кэш заданной емкости
    Cache* cache = createCache(capacity);
    int hits = 0;

    // Проходим через все запросы
    for (int i = 0; i < n; i++)
    {
        int page = requests[i];

        // Если страница уже в кэше, увеличиваем счетчик попаданий
        if (get(cache, page) != -1)
        {
            hits++;
        }
        else // Иначе вставляем новую страницу в кэш
        {
            put(cache, page, page);
        }
    }

    // Освобождаем память, занимаемую кэшем
    CacheNode* current = cache->head;

    while (current)
    {
        CacheNode* next = current->next;
        free(current);
        current = next;
    }

    free(cache);

    return hits; // Возвращаем количество попаданий
}