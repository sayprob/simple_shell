#include "shell.h"

/**
 * cust_strlen - Computes length of a string
 * @s: The string
 * Return: Length of string
 */
int cust_strlen(const char *s)
{
	int length = 0;

	while (*s)
	{
		length++;
		s++;
	}
	return (length);
}

/**
 * cust_strdup - Duplicates a string
 * @s: String to duplicate
 * Return: Duplicated string
 */
char *cust_strdup(const char *s)
{
	char *dup = malloc(cust_strlen(s) + 1);

	if (dup)
	{
		char *original_dup = dup;

		while (*s)
		{
			*dup = *s;
			dup++;
			s++;
		}
		*dup = '\0';
		return (original_dup);
	}

	return (NULL);
}

/**
 * cust_strcpy - Copies source to destination string
 * @s1: Destination string
 * @s2: Source string
 * Return: Pointer to destination string
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
	*s1 = '\0'; /* Null-terminate the destination string */

	return (original_s1);
}

/**
 * cust_strcat - Concatenates s2 to s1
 * @s1: Destination string
 * @s2: Source string
 * Return: Pointer to the destination string
 */
char *cust_strcat(char *s1, const char *s2)
{
	char *original_s1 = s1;

	/* Find end of s1 */
	while (*s1)
		s1++;

	/* Copy s2 to the end of s1 */
	while (*s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}

	/* End the resulting string with a null character */
	*s1 = '\0';

	return (original_s1);
}
