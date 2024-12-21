// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strncpy(). */
	//with a for I just copy from a string to another
	//from source to destination
	int i;
	for(i = 0; source[i] != '\0'; i++)
		destination[i] = source[i];

	//And adding the end of the string because i finish the for
	// when i find \0, so I need to add it to the destination
	//if i think about it, I could have used strlen or smth but
	//i ll just leave it like that sorry if its tractorlike
	destination[i] = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	//copying just like in strcpy but until len
	// I was receiving a warning if I compare a size_t with an int
	// so I changed the type of i to size_t
	for(size_t i = 0; i < len; i++)
		destination[i] = source[i];
	//No need for adding the end of the string because
	//i copied until len
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	//copying the strlen of destination because i think
	// its more efficient than alweays calling strlen
	int destination_len = strlen(destination);
	for(int i =0; source[i] != '\0'; i++)
		destination[destination_len + i] = source[i];


	//because I stopped the for again at \0 I need to add it
	destination[destination_len + strlen(source)] = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	//saving again the strlen of destination
	int destination_len = strlen(destination);
	//now because im comparing with len I will change to size_t again
	// to avoid damn warnings :(
	for(size_t i = 0; i <len; i++)
		destination[destination_len + i] = source[i];

	// wont forget to add the \0
	destination[destination_len + len] = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	//basically I have to compare 2 strings not that big of a deal
	// the contor set to 0 to go through strings
	// of course, cause of thw warnings i have to set it to size_t
	size_t contor = 0;

	//the while stops when one of the strings reach \0
	while (str1[contor] != '\0' && str2[contor] != '\0')
	{
		// if we find a difference we return -1 if str1 is smaller 1 otherwize
		if (str1[contor] != str2[contor]) {
			if(str1[contor] < str2[contor])
				return -1;
			else
				return 1;
		}
		//always incrementing the contor, 9th grade type of stuff
		contor++;
	}

	//if both strings reach the end at the same time we return 0
	//if not we return 1 if str2 is smaller -1 otherwize
	if (str1[contor] == '\0' && str2[contor] == '\0')
		return 0;
	else
	{
		if (str2[contor] == '\0')
			return 1;
		else
			return -1;
	}
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	//basically same thing as strcmp but until len
	//i think there is no need to explain again
	size_t contor = 0;
	while(contor < len && str1[contor] != '\0' && str2[contor] != '\0')
	{
		if (str1[contor] != str2[contor]){
			if(str1[contor] < str2[contor])
				return -1;
			else
				return 1;
		}
		contor++;
	}

	//i will explain this a little bit
	// instead of checking if both strings reach \0, now
	// checking if contor is equal to len, if it is we return 0
	// then it could be correct if is not zero but both string reach \0
	// just like on strcmp
	if (contor == len)
		return 0;
	else
	{
		if (str1[contor] == '\0' && str2[contor] == '\0')
			return 0;
		else
		{
			if (str2[contor] == '\0')
				return 1;
			else
				return -1;
		}
	}
}

size_t strlen(const char *str)
{
	// just having to see how long a string is
	// again 9th grade type of stuff
	// this is getting easier than pclp1 first homework
	// contor to 0
	size_t contor = 0;

	// a while where i increment the contor until I find \0
	while (str[contor] != '\0')
		contor++;

	return contor;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	// here I have to find the first appearance of c in str
	// using a for until I find c
	// if we find it we return the address of the first appearance
	// if we dont find it and the string ends it goes to return NULL
	for(int i = 0; str[i] != '\0'; i++)
		if (str[i] == c)
			return (char *)str + i;
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	// here I have to find the last appearance of c in str
	// i thought of using the for backwards but I was missing out on smth
	// and it didn't pass the test so I saved myself some time
	// and did it the normal way, updating it again and again

	// setting the last_appearence to NULL ready for being updated to the address
	// of potential c's
	char *last_appearence = NULL;
	// going through the string, last_appearance will be updated again every time
	for(int i =0; str[i] != '\0'; i++)
		if (str[i] == c)
			last_appearence = (char *)str + i;

	// returning it
	return last_appearence;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	// here i have to find the first appearance of needle in haystack
	// going through the haystack
	for(int i =0; haystack[i] != '\0'; i++)
	{
		// going through the needle
		int j = 0;
		// the condition for the while to start is that the needle is not \0
		// and the first character of the needle is found in the haystack
		while (needle[j] != '\0' && haystack[i + j] == needle[j])
			j++;
		// if I found all the needle I return the address of the first appearance
		if (needle[j] == '\0')
			return (char *)haystack + i;
	}
	// if I didn't find it I return NULL
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	// This is something like a hybrid between strstr and strrchr
	// I have to find the last appearance of needle in haystack

	// setting the last_appearence to NULL ready for being updated to the address
    const char *last_appearence = NULL;

	// going through the haystack
    for (int i = 0; haystack[i] != '\0'; i++) {
		    int j = 0;
			// again the condition for the while to start is that the needle is not \0
			// and the first character of the needle is found in the haystack
            while (needle[j] != '\0' && haystack[i + j] == needle[j]) {
                j++;
            }
			// here I update the last_appearence every time I find the needle
			// to get the last one
            if (needle[j] == '\0') {
                last_appearence = &haystack[i];
            }
    }

    return (char *)last_appearence;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	// basically I have to copy num bytes from source to destination
	// so changing the types of the pointers to char
	char *local_destination = (char *)destination;
	char *local_source = (char *)source;

	// num is size_t so I have to change the type of i to size_t
	for(size_t i = 0; i <num; i++)
		local_destination[i] = local_source[i];

	// return it easy peasy
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	//So basically the diffenrce between memcpy and memmove is that
	// memmove handles the case when the memory overlaps
	// so I have to check if the destination is smaller than the source

	// making the types of the pointers char again
    char *local_destination = (char *)destination;
    char *local_source = (char *)source;

	// if the destination is smaller than the source
    if (local_destination < local_source)
    {
		// I copy from source to destination
		// num is size_t so I have to change the type of i to size_t
        for (size_t i = 0; i <num; i++)
            local_destination[i] = local_source[i];
    } else { // if the destination is bigger than the source
		// I copy from the end of the source to the end of the destination
        for (int i = num-1; i >= 0; i--)
            local_destination[i] = local_source[i];
    }

    return local_destination;
}


int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	// I thought about this like a strcmp but with memory
	// So i have to compare the bytes of ptr1 and ptr2
	// I put ptr1 and ptr2 in char * to be able to compare them
	char *local_ptr1 = (char *)ptr1;
	char *local_ptr2 =(char *)ptr2;

	// the contor to go through the bytes
	// num is size_t so I have to change the type of contor to size_t
	// Pretty much from here is the same logic from strcmp
	// but instead of comparing characters I compare bytes
	size_t contor = 0;
	while(contor < num && local_ptr1[contor] == local_ptr2[contor]){
		if(local_ptr1[contor] != local_ptr2[contor]){
			if(local_ptr1[contor] < local_ptr2[contor])
				return -1;
			else
				return 1;
		}
		contor++;
	}

	if(contor == num)
		return 0;
	else
	{
		if(local_ptr1[contor] < local_ptr2[contor])
			return -1;
		else
			return 1;
	}
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	// setting a memory to a value
	char *local_source =(char *)source;

	// just a for not that big of a deal
	for (size_t i=0; i <num; i++)
		local_source[i] = value;

	return local_source;
}
