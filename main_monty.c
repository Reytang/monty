#include "monty.h"

/**
 * main - function of the prototype
 * @argc: argc counter
 * @argv: arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int x, ispushs = 0;
	unsigned int lines = 1;
	ssize_t n_read;
	char *buffers, *tokens;
	stack_t *h = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	x = open(argv[1], O_RDONLY);
	if (x == -1)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buffers = malloc(sizeof(char) * 10000);
	if (!buffers)
		return (0);
	n_read = read(x, buffers, 10000);
	if (n_read == -1)
	{
		free(buffers);
		close(x);
		exit(EXIT_FAILURE);
	}
	tokens = strtok(buffers, "\n\t\a\r ;:");
	while (tokens != NULL)
	{
		if (ispushs == 1)
		{
			push(&h, lines, tokens);
			ispushs = 0;
			tokens = strtok(NULL, "\n\t\a\r ;:");
			lines++;
			continue;
		}
		else if (strcmp(tokens, "push") == 0)
		{
			ispushs = 1;
			tokens = strtok(NULL, "\n\t\a\r ;:");
			continue;
		}
		else
		{
			if (get_op_func(tokens) != 0)
			{
				get_op_func(tokens)(&h, lines);
			}
			else
			{
				free_dlist(&h);
				printf("L%d: unknown instruction %s\n", lines, tokens);
				exit(EXIT_FAILURE);
			}
		}
		lines++;
		tokens = strtok(NULL, "\n\t\a\r ;:");
	}
	free_dlist(&h); free(buffers);
	close(x);
	return (0);
}
