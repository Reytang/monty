#include "monty.h"

/**
 * is_number - function of the prototype
 * @n: integer
 * Return: 0 if is number, else -1 if not
 */
int is_number(const char *n)
{
	int x = 0;

	if (*n == '-')
		x = 1;
	for (; *(n + x) != '\0'; x++)
	{
		if (isdigit(*(n + x)) == 0)
			return (-1);
	}
	return (0);
}
/**
 * push - function of the prototype
 * @h: head of linked list (node at the bottom of stack)
 * @line_number: bytecode line number
 * @n: integer
 */
void push(stack_t **h, unsigned int line_number, const char *n)
{
	if (!h)
		return;
	if (is_number(n) == -1)
	{
		printf("L%u: usage: push integer\n", line_number);
		free_dlist(h);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (add_end_node(h, atoi(n)) == -1)
		{
			free_dlist(h);
			exit(EXIT_FAILURE);
		}
	}
}
/**
 * pop - function of the prototype
 * @h: head of linked list (node at the bottom of stack)
 * @line_number: bytecode line number
 */
void pop(stack_t **h, unsigned int line_number)
{
	if (h == NULL || *h == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		free_dlist(h);
		exit(EXIT_FAILURE);
	}
	else
		delete_end_node(h);
}
