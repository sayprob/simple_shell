#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * cust_strlen - Compute length of string
 * @s: String
 * Return: Length of the string
 */
int cust_strlen(const char *s)
{
	int length = 0;

	while (*s++)
		length++;
	return (length);
}

/**
 * cust_strdup - Duplicate string
 * @s: String for duplicate
 * Return: The duplicated string
 */
char *cust_strdup(const char *s)
{
	char *dup = malloc(cust_strlen(s) + 1);

	if (dup)
		cust_strcpy(dup, s);

	return (dup);
}

/**
 * cust_strcpy - Copy source to the destination string
 * @s1: The destination string
 * @s2: The source string
 * Return: Pointer to the destination string
 */
char *cust_strcpy(char *s1, const char *s2)
{
	char *original_s1 = s1;

	while (*s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	s1 = '\0';
	return (original_s1);
}

	/* Null-terminate the destination srting */
	*s1 = '\0';
}

/**
 * cust_strcat - concatenate s2 to s1
 * @s1: The destination string
 * @s2: The source string
 * Return: Pointer to destination string
 */
void *cust_strcat(char *s1, const char *s2)
{
	/* Find end of s1 */
		while (*s1)
		{
			s1++;

	/* Copy s2 to end of s1 */
		while (*s2)
		{
			*s1 = *s2;
			*s1++;
			*s2++;
		}

	/* End resulting string with a null character */
		*s1 = '\0';

	return (original_s1);
}
