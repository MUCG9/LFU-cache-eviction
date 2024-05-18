typedef struct LFUNode {
    int key;              
    int value;             
    int frequency;          
    struct LFUNode* next;  
    struct LFUNode* prev;  
} LFUNode;

typedef struct LFUCache {
    int capacity;                   
    int size;                       
    LFUNode *head;
    LFUNode *tail;
} LFUCache;
