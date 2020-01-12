#include "libmx.h"

// void *mx_realloc(void *ptr, size_t size) {
// 	void *new_ptr = NULL;
// 	size_t len;

// 	if (size <= 0 && ptr) {
// 		free(ptr);
// 		return NULL;
// 	}
// 	if (!ptr && size)
// 		return malloc(size);
// 	len = malloc_size(ptr);
// 	if (len > size)
// 		new_ptr = (void *)malloc(len);
// 	else
// 		new_ptr = (void *)malloc(size);
// 	if (!new_ptr)
// 		return NULL;
// 	new_ptr = mx_memmove(new_ptr, ptr, size);
// 	free(ptr);
// 	return (void *)new_ptr;
// }

// void *mx_realloc(void *ptr, size_t size) {
//     if (ptr == NULL) {
//         return malloc(size);
//     }
//     if (size == 0) {
//         free(ptr);
//         return NULL;
//     }
//     void *rslt = malloc(size);
//     size_t size_ptr = malloc_size(ptr); // malloc_usable_size(ptr); //  change to malloc_size()
//     if (rslt) {
//         mx_memcpy(rslt, ptr, (size_ptr > size ? size : size_ptr)); /*malloc_size*/
//     }
//     free(ptr);
//     return (void*)rslt;
// }

void *mx_realloc(void *ptr, size_t size) {
    if (size <= 0)
        return NULL;
    void *new_ptr = malloc(size);
    if (!new_ptr)
        return NULL;
    if (!ptr)
        return new_ptr;
    size_t size_ptr = malloc_usable_size(ptr); // malloc_size(ptr); // malloc_usable_size(ptr);
    //printf("%zu\n", size_ptr);
    mx_memcpy(new_ptr, ptr, (size_ptr > size ? size : size_ptr));
    free(ptr);
    return new_ptr;
}
