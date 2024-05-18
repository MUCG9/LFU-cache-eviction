int LFUCacheHits(int m, int n, int* requests)
{
    Cache* cache = createCache(m);
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
