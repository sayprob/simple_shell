#include "shell.h"

/**
 * main - to display the prompt simple_shell$
 * @argc: argument count
 * @argv: argument vector
 * Return: nothing.
 */
int main(int argc, char **argv)
{
	char *input = NULL;
	int count = 0;

	(void)argc;
	while (1)
	{
		count = count + 1;
		show_prompt();
		read_userinput(&input);
		execute_input(input, argv[0], count);

		free(input);  /*Release buffer memory after executing command*/
		input = NULL; /*Reset for the subsequent iteration*/
	}

	return (0);
}
