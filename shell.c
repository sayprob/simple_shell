#include "shell.h"

/**
 * main - Displays the prompt simple_shell$
 *
 * Return: Nothing
 */
int main(void)
{
	char *input = NULL;

	while (1)
	{
		read_userinput(&input);
		execute_input(input);
		show_prompt();

		free(input); /* Release buffer memory after execting command */
			input = NULL; /* Reset for the subsequent iteration */
	}

	return (0);
}
