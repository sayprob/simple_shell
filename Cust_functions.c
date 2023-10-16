#include "shell.h"

/**
 * cust_strncmp - compare upto n chars from two strings
 * @s1: The first string to compare
 * @s2: The second string to compare
 * @n: The num of chars to compare
 * Return: Integer less than, equal to, or greater than
 * zero if s1 is found, respectively, <, to match, or > s2
 */
int cust_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		/* if the characters are different or one string has ended */
			if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
			{
				return (s1[i] - s2[i]);
			}
	}
	return (0);
}
