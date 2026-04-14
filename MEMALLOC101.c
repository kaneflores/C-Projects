// Welcome to MEMALLOC 101 project guide
// sbrk() lets us manipulate the program break ot release/allocate memory in the heap
///
// sbrk(0) gives the current address of the pgrm break
// sbrk(x) with a positive value increments brk by x bytes, as a result of allocating memory
// sbrk(-x) with a negative value decrements brk by x bytes, as a result of releasing memory
// on failutre, sbrk() returns (void*) -1.

struct header_t{
    size_t size;
    unsigned is_free;
    struct header_t *next;
}
//MALLOC*****************
void *malloc(size_t size){

    void *block;
    block = sbrk(size);
    if (block == (void*)-1)
        return NULL;
    return block;
}