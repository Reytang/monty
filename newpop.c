#include "monty.h"
/**
 * op_pop - function of the prototype
 * @head: stack head
 * @counter: line number
*/
void op_pop(stack_t **head, unsigned int counter)
{
	stack_t *popq;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.files);
		free(bus.info);
		clear_dll(*head);
		exit(EXIT_FAILURE);
	}
	popq = *head;
	*head = popq->next;
	free(popq);
}
/**
 * op_pint - function of the prototype
 * @head: stack head
 * @counter: line number
*/
void op_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.files);
		free(bus.info);
		clear_dll(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

