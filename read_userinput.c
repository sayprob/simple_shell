#include "shell.h"

/**
 * read_userinput - Read input command from
 * standard input
 * @input: Buffer to store the input
 */
void read_userinput(char **input)
{
	size_t len = 0;
	char *str_ptr;

	if (getline(input, &len, stdin) == -1)
	{
		free(*input);
		*input = NULL;
		error_userinput();
	}
	for (str_ptr = *input; *str_ptr; str_ptr++)
		if (*str_ptr == '\n')
		{
			*str_ptr = '\0';
			break;
		}
}

/**
 * error_userinput - Handle input errors from user
 *
 * Function is called when getline fails to read
 * user input
 * Checks if error was due to end-of-file condition
 * (like Ctrl-D)
 * if EOF, print a newline and exit successfully
 * Otherwise, print error message using perror
 * and exit with a fail
 */
void error_userinput(void)
{
	if (feof(stdin))
	{
		exit(EXIT_SUCCESS);
	}
	else
	{
		perror("cust_getline");
		exit(EXIT_FAILURE);
	}
}

/**
 * child_execution - Create a child process
 * and execute the given command
 *
 * @arg_str: NULL terminated array of arguments
 * for the command to be executed
 *
 * This function will first attempt to create
 * a child process using fork()
 * If fork fails, an error message is printed
 * and the shell will exit with a fail
 * If fork is successful, and we are in child
 * process, execve()
 * The parent process waits for the child to
 * complete exec using wait()
 */
void child_execution(char **arg_str)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		execve(arg_str[0], arg_str, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
