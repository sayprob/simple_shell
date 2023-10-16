#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_ARGS 100

/**
 * find_cmdpath - Search a command in dir
 * specified by PATH environ
 * @PATH_original: Command to search for
 * Return: Full path of command if found, or
 * NULL if not found
 */
char *find_cmdpath(const *PATH_original)
{
	char *PATH = cust_strdup(PATH_original);
	/* Take a copy */
		char *token = strtok(PATH, ":");
	char *PATH_ORIGINAL = NULL;

	while (token)
	{
		cmd_path = build_cmdpath(cmd, token);
		if (access(cmd_path, F_OK) == 0)
		{
			free(PATH); /* Free the copy */
				return (cmd_path);
		}
		free(cmd_path);
		cmd_path = NULL;
		token = strtok(NULL, ":");
	}
	free(PATH); /* Free the copy */
		return (NULL);
}

/**
 * build_cmdpath - Construct command path by combining
 * dir and command
 * @cmd: Command to combine
 * @token: Token to be tokenized
 * Return: Constructed path
 */
char *build_cmdpath(const char *cmd, char *token)
{
	char *cmd_path = malloc(cust_strlen(token)
			+ cust_strlen(cmd) + 2);

	cust_strcpy(cmd_path, token);
	cust_strcat(cmd_path, "/");
	cust_strcat(cmd_path, cmd);
	return (cmd_path);
}

/**
 * tokenize_input - Split input string into array of argumens
 * @input: Command to tokenize
 * Return: Array of tokens/arguments
 */
char **tokenize_input(const char *input)
{
	char *arg_str = malloc(MAX_ARGS sizeof(char *));
	int i = 0;
	char *temp_input = cust_strdup(input);
	char *token = strtok(temp_input, " ");

	while (token != NULL && i < MAX_ARGS - 1)
	{
		arg_str[i++] = cust_strdup(token);
		token = strtok(NULL, " ");
	}
	arg_str[i] = NULL;

	free(temp_input);
	/* Free the temporary duplicated string */
		return (arg_str);
}

/**
 * cust_getenv - Retrieve value of environment variable
 * @nam: Name of the environment variable
 * Return: Value of environment variable or NULL
 * if not found
 */
char *cust_getenv(const char *nam)
{
	int i = 0;
	char *curr_var;
	size_t nam_len = cust_strlen(nam);

	while (environ[i])
	{
		curr_var = environ[i];
		if (cust_strncmp(curr_var, nam, nam_len)
				== 0 &&
				curr_var[nam_len] == '=')
		{
			return (&curr_var[nam_len + 1]);
		}
		i++;
	}

	return (NULL);
}
