#include "Shell.h"
/**
 *_memset - fills memory with a constant byte
 *@s: the pointer to the memory area
 *@b: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
*/
char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;
i = 0;
while (i < n)
{
    s[i] = b;
    i++;
}
 return (s);
}
/**
 * ffree - frees an array of strings
 * @string_list: array of strings
 */
void ffree(char **string_list)
{
	char **a = string_list ;

	if (!string_list)
		return;
	while (*string_list)
		free(*string_list++);
	free(a);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous  block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to new block
 */
void *_realloc(void *ptr, int)
{
    char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	re
    turn (p);
}
/**
 * pointer_free - frees a pointer and NULLs the address
 * @ptr: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int pointer_free(void **ptr)
{
	if ((ptr != NULL) && (*ptr != NULL))
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

