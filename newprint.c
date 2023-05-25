#include "monty.h"
/**
 * pall - function of the prototype
 * @h: head of list
 * @line_number: bytecode line number
 */
void pall(stack_t **h, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!h || !*h)
		return;

	(void) line_number;
	temp = *h;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint - function of the prototype
 * @h: head of list
 * @line_number: bytecode line number
 */
void pint(stack_t **h, unsigned int line_number)
{
	if (!h || !*h)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h)->n);

}
/**
 * pchar - function of the prototypes
 * @h: head of list
 * @line_number: bytecode line number
 */
void pchar(stack_t **h, unsigned int line_number)
{
	if (!h || !*h)
	{
		printf("L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (((*h)->n) >= 0 && ((*h)->n) <= 127)
		printf("%c\n", (*h)->n);
	else
	{
		printf("L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

}
/**
 * pstr - function of the prototype
 * and stop only if end of stack, node is 0, or not in ascii table
 * @h: head of list
 * @line_number: bytecode line number
 */
void pstr(stack_t **h, unsigned int line_number)
{
	stack_t *temp;

	if (!h || !*h)
	{
		printf("L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *h;
	while ((temp != NULL) && (temp->n != 0) &&
	       (temp->n >= 0) && (temp->n <= 127))
	{
		printf("%c", (temp)->n);
		temp = temp->next;
	}
	printf("\n");
}
/**
 * nop - function of the prototype
 * @h: head of list
 * @line_number: bytecode line number
 */
void nop(stack_t **h, unsigned int line_number)
{
	(void) h;
	(void) line_number;
}
