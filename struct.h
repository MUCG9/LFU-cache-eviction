typedef struct CacheNode {
    int key;              
    int value;             
    int freq;          
    struct CacheNode* next;  
    struct CacheNode* prev;  
} CacheNode;

typedef struct Cache {
    int capacity;                   
    int size;                       
    CacheNode *head;
    CacheNode *tail;
} Cache;

CacheNode* createNode(int key, int value) 
{
    CacheNode* node = (CacheNode*)malloc(sizeof(CacheNode));

    node->key = key;
    node->value = value;
    node->freq = 1;
    node->prev = NULL;
    node->next = NULL;

    return node;
}

Cache* createCache(int capacity) 
{
    Cache* cache = (Cache*)malloc(sizeof(Cache));

    cache->capacity = capacity;
    cache->size = 0;
    cache->head = NULL;
    cache->tail = NULL;

    return cache;
}