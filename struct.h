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

LFUNode* LFUcreateNode(int key, int value) 
{
    LFUNode* node = (LFUNode*)malloc(sizeof(LFUNode));

    node->key = key;
    node->value = value;
    node->frequency = 1;
    node->prev = NULL;
    node->next = NULL;

    return node;
}
