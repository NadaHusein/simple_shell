#include "Shell.h"
/**
 * _strlen - gets the length of a string
 * @s: the string to find the length
 * Return: integer length of it
*/
int _strlen(char *s)
{
    int i = 0;
    if(s == NULL)
    return (0);
    while(*s++)
        i++;
    return (i);    
}
/**
 * _strcmp - compares two strings 
 * @s1: first string
 * @s2: second string
 * Return: 0 if(s1 == s2), +ve value if(s1>s2), -ve value if(s1<s2)
*/
int _strcmp (char *s1, char*s2)
{
    while (*s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    if (*s1 != *s2)
    return (*s1 - *s2);

    return (0);
    
}
/**
 * find_substring - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *find_substring(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}
/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

