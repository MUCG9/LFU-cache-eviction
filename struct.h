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