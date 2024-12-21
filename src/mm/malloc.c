// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

//For these tasks mem_list.c helped me a lot

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	// calling mmap that I just implemented in order to allocate memory
	// For the flags of mmmap I saw that in sys/mman.h I had all I needed
	// I ll do a little resume here of what I used
	// NULL - basically it lets the kernel to choose the address for me
	// size - the size of the memory that I want to allocate, this was intuitive
	// PROT_READ | PROT_WRITE - I want to be able to read and write in this memory
	// MAP_PRIVATE | MAP_ANONYMOUS - I want a private mapping and I don't want to use a file
	// -1 - I don't want to use a file descriptor
	// 0 - offset
	void *memory = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	// adding the memory basically, mem_list_add was already implemented and it helped a lot
	mem_list_add(memory, size); // found this in mem_list.c
	return memory;
}

// Calloc was very easy now that malloc works
void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	// I use the malloc I've just created and that works wonderful
	void *memory = malloc(nmemb * size);
	// And then I make each byte of the memory allocated with malloc to 0
	// I think I could also used memset here but this was my first thought of
	// implementing it and it worked
	for(size_t i = 0; i < nmemb * size; i++) {
		*((char *)memory + i) = 0;
	}
	return memory;
}

//This was the hardest thing to implement
// At first I didn't thought about using mem_list_find
// and I can say that function saveed me
// I don't think I could do it by myself
void free(void *ptr)
{
	/* TODO: Implement free(). */
	// Munmap because I want to get rid of the memory
	// mem_list_find was very useful here as I could very easily find the length of the memory
	// that I wanted to unmap
	munmap(ptr, mem_list_find(ptr)->len);

	// Then just deleting the memory from the list
	mem_list_del(ptr);
}



void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	// Allocating the memory with the new size that is wanted
	//I just use a malloc
	void *memory = malloc(size);

	// Now Im just copying the memory from the old pointer to the new one
	// mem_list_find was very useful here as I could very easily find the length of the memory
	// that I wanted to copy
	memcpy(memory, ptr, mem_list_find(ptr)->len);

	// and freeing the old memory
	free(ptr);

	// Returning the new memory ofc
	return memory;
}

//
void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	// ptr is the pointer to the memory that I want to reallocate
	// mem_list_find was very useful here as I could very easily find the length of the memory
	// that I wanted to reallocate
	// nmemb is the number of elements that I want to reallocate
	// size is the size of each element
	// and flags just set to 0, it works so  :)))
	return mremap(ptr, mem_list_find(ptr)->len, nmemb * size, 0);
}
