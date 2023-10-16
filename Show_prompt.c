#include "shell.h"

/**
 * show_prompt - Display shell prompt
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
 * _myprintf - Print ouputs to the screen
 * @content: Content to output
 * Return: Return len of the content
 */
int _myprintf(const char *content)
{
	int len = cust_strlen(content);

	write(STDOUT_FILENO, content, len);

	return (len);
}
