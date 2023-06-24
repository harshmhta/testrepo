/*
 * mm.c
 *
 * Name: Manjiri Parchure
 *
 * This is the code is for checkpoint1
 * Current implementation is not complete and is a basic version of the functions.
 * I am citing the textbook for the use of the mem_sbrk() function.
 *
 */
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>

#include "mm.h"
#include "memlib.h"

/*
 * If you want to enable your debugging output and heap checker code,
 * uncomment the following line. Be sure not to have debugging enabled
 * in your final submission.
 */
// #define DEBUG

#ifdef DEBUG
// When debugging is enabled, the underlying functions get called
#define dbg_printf(...) printf(__VA_ARGS__)
#define dbg_assert(...) assert(__VA_ARGS__)
#else
// When debugging is disabled, no code gets generated
#define dbg_printf(...)
#define dbg_assert(...)
#endif // DEBUG

// do not change the following!
#ifdef DRIVER
// create aliases for driver tests
#define malloc mm_malloc
#define free mm_free
#define realloc mm_realloc
#define calloc mm_calloc
#define memset mm_memset
#define memcpy mm_memcpy
#endif // DRIVER

#define ALIGNMENT 16

// rounds up to the nearest multiple of ALIGNMENT
static size_t align(size_t x)
{
    return ALIGNMENT * ((x+ALIGNMENT-1)/ALIGNMENT);
}

/*
 * mm_init: returns false on error, true on success.
 */
bool mm_init(void)
{
    // IMPLEMENT THIS
    return true; //For now i am using this as a placeholder, and during actual implementation it will return false on failure
}

/*
 * malloc
 */
void* malloc(size_t size)
{{
    // IMPLEMENT THIS
    if(size != 0){
        // citing mem_sbrk code taken from the textbook
        void *ptr = mem_sbrk(align(size)); 
        if(ptr) //check if memory was allocated
        { 
            return ptr;
        } 
        else
        { 
            return NULL; //if allocation failed we will return NULL
        }
        
    } 
    else
    {
        return NULL; //if size is zero we will return NULL
        
    }
}
}

/*
 * free
 */
void free(void* ptr)
{
    // IMPLEMENT THIS
    if(ptr == NULL)
    {
        return;
    }
}

/*
 * realloc
 */
void* realloc(void* oldptr, size_t size)
{
    
    // IMPLEMENT THIS
    void *pointer = malloc(size); //we will allocate new memory of size bytes

    if(pointer) //check if the memory is succesfully allocated
    {
        memcpy(pointer,oldptr,size); //memcpy will copy old data to the new data
        free(oldptr); //deallocate the old pointer

    }
    else if(size <=0){
        free(oldptr);
        return NULL;
    }
    else if(!oldptr){
        //if old pointer is NULL, we will allocate new memory block
        return malloc(size);
    }
    return pointer;
}

/*
 * calloc
 * This function is not tested by mdriver, and has been implemented for you.
 */
void* calloc(size_t nmemb, size_t size)
{
    void* ptr;
    size *= nmemb;
    ptr = malloc(size);
    if (ptr) {
        memset(ptr, 0, size);
    }
    return ptr;
}

/*
 * Returns whether the pointer is in the heap.
 * May be useful for debugging.
 */
static bool in_heap(const void* p)
{
    return p <= mm_heap_hi() && p >= mm_heap_lo();
}

/*
 * Returns whether the pointer is aligned.
 * May be useful for debugging.
 */
static bool aligned(const void* p)
{
    size_t ip = (size_t) p;
    return align(ip) == ip;
}

/*
 * mm_checkheap
 * You call the function via mm_checkheap(__LINE__)
 * The line number can be used to print the line number of the calling
 * function where there was an invalid heap.
 */
bool mm_checkheap(int line_number)
{
#ifdef DEBUG
    // Write code to check heap invariants here
    // IMPLEMENT THIS
#endif // DEBUG
    return true;
}
