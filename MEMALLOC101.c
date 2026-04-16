// Welcome to MEMALLOC 101 project guide
// sbrk() lets us manipulate the program break ot release/allocate memory in the heap
///
// sbrk(0) gives the current address of the pgrm break
// sbrk(x) with a positive value increments brk by x bytes, as a result of allocating memory
// sbrk(-x) with a negative value decrements brk by x bytes, as a result of releasing memory
// on failutre, sbrk() returns (void*) -1.
typedef char ALIGN[16];
header_t *head, *tail;
union header {
    struct {
        size_t size;
        unsigned is_free;
        union header *next;
    } s;
    ALIGN stub;
};
typedef union header header_t;

//MALLOC*****************
void *malloc(size_t size){
    size_t total size;
    void *block;
    header_t *header;

    
    if (!size){
        return NULL;}
    pthread_mutex_lock(&global_malloc_lock);
    header = get_free_block(size);
    if (header){
        header->s.is_free = 0;
        pthread_mutex_unlock(&global_malloc_lock);
        return (void*)(header + 1);
    }

    total_size = sizeof(header_t) + size;
    block = sbrk(total_size);
    // block = sbrk(size);
    if (block == (void*)-1)
        return NULL;
    return block;
}