#include <stdio.h>
#include <stdlib.h>

#ifndef SYSTIME_H
#define SYSTIME_H

#include <sys/time.h>

#define HASH_SIZE 100000

typedef struct Node
{
    int elt;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct
{
    int m;
    int size;
    Node *head;
    Node *tail;
} LRUCache;

typedef struct HashNode
{
    Node *node;
    struct HashNode *next;
} HashNode;

typedef struct
{
    HashNode *table[HASH_SIZE];
} HashTable;

LRUCache *createLRUCache(int m)
{
    LRUCache *cache = (LRUCache *)malloc(sizeof(LRUCache));
    cache->m = m;
    cache->size = 0;
    cache->head = NULL;
    cache->tail = NULL;
    return cache;
}

void deleteLRUCache(LRUCache *cache)
{
    Node *temp;
    while (cache->head)
    {
        temp = cache->head;
        cache->head = cache->head->next;
        free(temp);
    }
    free(cache);
}

Node *createNode(int elt)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->elt = elt;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void moveToTail(LRUCache *cache, Node *node)
{
    if (node == cache->tail)
    {
        return;
    }

    if (node == cache->head)
    {
        cache->head = cache->head->next;
        if (cache->head)
        {
            cache->head->prev = NULL;
        }
    }
    else
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    node->prev = cache->tail;

    if (cache->tail)
    {
        cache->tail->next = node;
    }

    node->next = NULL;
    cache->tail = node;
}

int cacheHit(LRUCache *cache, HashTable *hashTable, int elt)
{
    int hash = elt % HASH_SIZE;
    HashNode *hashNode = hashTable->table[hash];

    while (hashNode)
    {
        if (hashNode->node->elt == elt)
        {
            moveToTail(cache, hashNode->node);
            return 1;
        }
        hashNode = hashNode->next;
    }

    return 0;
}

void addPage(LRUCache *cache, HashTable *hashTable, int elt)
{
    Node *newNode = createNode(elt);
    HashNode *hashNode = (HashNode *)malloc(sizeof(HashNode));
    int hash = elt % HASH_SIZE;
    int tempHash;
    HashNode *prev = NULL;
    HashNode *current;
    if (cacheHit(cache, hashTable, elt))
    {
        free(newNode);
        free(hashNode);
        return;
    }

    if (cache->size == cache->m)
    {
        Node *temp = cache->head;
        cache->head = cache->head->next;
        if (cache->head)
        {
            cache->head->prev = NULL;
        }
        else
        {
            cache->tail = NULL;
        }

        tempHash = temp->elt % HASH_SIZE;
        current = hashTable->table[tempHash];

        while (current)
        {
            if (current->node == temp)
            {
                if (prev)
                {
                    prev->next = current->next;
                }
                else
                {
                    hashTable->table[tempHash] = current->next;
                }

                free(current);
                break;
            }
            prev = current;
            current = current->next;
        }

        free(temp);
        cache->size--;
    }

    if (cache->tail)
    {
        cache->tail->next = newNode;
        newNode->prev = cache->tail;
    }
    else
    {
        cache->head = newNode;
    }

    cache->tail = newNode;
    cache->size++;

    hashNode->node = newNode;
    hashNode->next = hashTable->table[hash];
    hashTable->table[hash] = hashNode;
}

int main()
{
    int m, n, i;
    int page, hits = 0;
    struct timeval start, end;
    double elapsed;
    LRUCache *cache;
    HashTable *hashTable;

    scanf("%d %d", &m, &n);

    cache = createLRUCache(m);
    hashTable = (HashTable *)malloc(sizeof(HashTable));
    for (i = 0; i < HASH_SIZE; i++)
    {
        hashTable->table[i] = NULL;
    }

    for (i = 0; i < n; i++)
    {
        scanf("%d", &page);
        hits += cacheHit(cache, hashTable, page);
        addPage(cache, hashTable, page);
    }

    deleteLRUCache(cache);
    free(hashTable);

    gettimeofday(&start, NULL);
    hits = LFUCacheHits(capacity, n, requests);
    gettimeofday(&end, NULL);

    printf("%d\n", hits);

    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    printf("LFU time: %f sec\n", elapsed);

    return 0;
}