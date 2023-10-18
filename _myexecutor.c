#include "shell.h"

/**
 * execute_input - Attempts to execute a given command
 * @input: The command to execute
 * @argv: filename
 * @count: loop count
 */
void execute_input(const char *input, char *argv, int count)
{
	int i;
	char **arg_str, *path_cmd;

	if (cust_strncmp(input, "exit", 4) == 0)
	{
		exit_execute(input);
	}
	arg_str = tokenize_input(input);
	if (!arg_str[0])
	{
		free(arg_str);
		return;
	}
	if (access(arg_str[0], F_OK) == 0)
	{
		child_execution(arg_str);
	}
	else
	{
		path_cmd = find_cmdpath(arg_str[0]);
		if (path_cmd)
		{
			free(arg_str[0]);
			arg_str[0] = path_cmd;
			child_execution(arg_str);
		}
		else
		{
			_printf("%s: %d: %s: not found\n", argv, count, arg_str[0]);
			if (!isatty(STDIN_FILENO))
				exit(127);
		}
	}
	for (i = 0; arg_str && arg_str[i] != NULL; i++)
		free(arg_str[i]);
	free(arg_str);
}

/**
 * exit_execute - Checks the user
 * input to see if it matche the "exit" comman
 *
 * @input: The user's input string
 */
void exit_execute(const char *input)
{
	if (cust_strlen(input) == 4)
		exit(EXIT_SUCCESS);
}
