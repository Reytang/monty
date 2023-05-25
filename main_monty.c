#include<stdio.h>
#include "monty.h"

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
bus_t bus = { NULL, NULL, NULL, 0 };
/**
* main - funtion of the main prototype
* @argc: arguments
* @argv: file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *info;
	FILE *files;
	size_t sizes = 0;
	ssize_t read = 1;
	stack_t *stacks = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	files = fopen(argv[1], "r");
	bus.files = files;
	if (!files)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read > 0)
	{
		info = NULL;
		read = getline(&info, &sizes, files);
		bus.info = info;
		count++;
		if (read > 0)
		{
			startopcode(info, &stacks, count, files);
		}
		free(info);
	}
	clear_dll(stacks);
	fclose(files);
	return (0);
}

