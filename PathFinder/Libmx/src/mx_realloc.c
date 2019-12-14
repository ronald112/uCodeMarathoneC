#include "libmx.h"
void *mx_realloc(void *ptr, size_t size) {
    if (ptr == NULL) {
        return malloc(size);
    }
    if (size == 0) {
        free(ptr);
        return NULL;
    }
    void *rslt = malloc(size);
    size_t size_ptr = malloc_usable_size(ptr);// malloc_size(ptr); //  change to malloc_size()
    if (rslt) {
        mx_memcpy(rslt, ptr, (size_ptr > size ? size : size_ptr)); /*malloc_size*/
    }
    free(ptr);
    return (void*)rslt;
}

// void *mx_realloc(void *ptr, size_t size) {
//     if (size <= 0)
//         return NULL;
//     void *new_ptr = malloc(size);
//     if (!new_ptr)
//         return NULL;
//     if (!ptr)
//         return new_ptr;
//     size_t size_ptr = malloc_usable_size(ptr); // change to malloc_size()
//     mx_memcpy(new_ptr, ptr, (size_ptr > size ? size: size_ptr));
//     free(ptr);
//     return new_ptr;
// }
