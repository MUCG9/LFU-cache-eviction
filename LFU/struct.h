// Структура узла кэша, представляющая элемент двусвязного списка
typedef struct CacheNode
{
    int key;            // Ключ узла
    int value;          // Значение узла
    int freq;           // Частота использования узла
    struct CacheNode* next; // Указатель на следующий узел
    struct CacheNode* prev; // Указатель на предыдущий узел
} CacheNode;

// Структура кэша, представляющая двусвязный список
typedef struct Cache
{
    int capacity;       // Максимальная емкость кэша
    int size;           // Текущий размер кэша
    CacheNode* head;    // Указатель на первый узел списка
    CacheNode* tail;    // Указатель на последний узел списка
} Cache;