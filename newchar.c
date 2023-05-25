#include "monty.h"
/**
 * op_pchar - function of the prototype
 * @head: stack head
 * @counter: line_number
*/
void op_pchar(stack_t **head, unsigned int counter)
{
	stack_t *charq;

	charq = *head;
	if (!charq)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.files);
		free(bus.info);
		clear_dll(*head);
		exit(EXIT_FAILURE);
	}
	if (charq->n > 127 || charq->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.files);
		free(bus.info);
		clear_dll(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", charq->n);
}
/**
 * op_pstr - function of the prototype
 * @head: stack head
 * @counter: line number
*/
void op_pstr(stack_t **head, unsigned int counter)
{
	stack_t *vx;
	(void)counter;

	vx = *head;
	while (vx)
	{
		if (vx->n > 127 || vx->n <= 0)
		{
			break;
		}
		printf("%c", vx->n);
		vx = vx->next;
	}
	printf("\n");
}
