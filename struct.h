typedef struct CacheNode {
    int key;              
    int value;             
    int frequency;          
    struct CacheNode* next;  
    struct CacheNode* prev;  
} CacheNode;

typedef struct Cache {
    int capacity;                   
    int size;                       
    LFUNode *head;
    LFUNode *tail;
} Cache;

