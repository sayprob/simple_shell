#include "shell.h"

/**
 * show_prompt - Display the shell prompt
 */
void show_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		_myprintf("simple_shell$ ");
		fflush(stdout);
	}
}

/**
 * _myprintf - to print ouputs to the screen
 * @content: The content to output
 * Return: It should return len of the content
 */
int _myprintf(const char *content)
{
	int len = cust_strlen(content);

	write(STDOUT_FILENO, content, len);

	return (len);
}
