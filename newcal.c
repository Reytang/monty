#include "monty.h"
/**
 * _add - functon of the prototype
 * @h: top node
 * @line_number: node number
 */
void _add(stack_t **h, unsigned int line_number)
{
	if (*h == NULL || (*h)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*h)->next->n += (*h)->n;
	(*h) = (*h)->next;
	free((*h)->prev);
	(*h)->prev = NULL;
}
/**
 * _sub - functon of the prototype
 * @h: top of list
 * @line_number: line of command
 */
void _sub(stack_t **h, unsigned int line_number)
{
	if (*h == NULL || (*h)->next == NULL)
	{
		printf("L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*h)->next->n -= (*h)->n;
	(*h) = (*h)->next;
	free((*h)->prev);
	(*h)->prev = NULL;
}
/**
 * _mul - functon of the prototype
 * @h: top of list
 * @line_number: line of command
 */
void _mul(stack_t **h, unsigned int line_number)
{
	if (*h == NULL || (*h)->next == NULL)
	{
		printf("L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*h)->next->n *= (*h)->n;
	(*h) = (*h)->next;
	free((*h)->prev);
	(*h)->prev = NULL;
}
/**
 * _div - functon of the prototype
 * @h: top of list
 * @line_number: line of command
 */
void _div(stack_t **h, unsigned int line_number)
{
	if (*h == NULL || (*h)->next == NULL)
	{
		printf("L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*h)->n == 0 || (*h)->next->n == 0)
	{
		printf("L%u: division by zero\n", line_number);
	}
	(*h)->next->n /= (*h)->n;
	(*h) = (*h)->next;
	free((*h)->prev);
	(*h)->prev = NULL;
}
/**
 * _mod - functon of the prototype
 * @h: top of list
 * @line_number: line of command
 */
void _mod(stack_t **h, unsigned int line_number)
{
	if (h == NULL || *h == NULL)
	{
		printf("L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*h)->n == 0 || (*h)->next->n == 0)
	{
		printf("L%u: division by zero\n", line_number);
	}
	(*h)->next->n %= (*h)->n;
	(*h) = (*h)->next;
	free((*h)->prev);
	(*h)->prev = NULL;
}
