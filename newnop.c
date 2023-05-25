#include "monty.h"
/**
  *op_nop- function of the prototype
  *@head: stack head
  *@counter: line_number
 */
void op_nop(stack_t **head, unsigned int counter)
{
	(void)counter;
	(void)head;
}
/**
  *op_sub- function of prototype
  *@head: stack head
  *@counter: line number
 */
void op_sub(stack_t **head, unsigned int counter)
{
	stack_t *variable;
	int vz, vy;

	variable = *head;
	for (vy = 0; variable != NULL; vy++)
		variable = variable->next;
	if (vy < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.files);
		free(bus.info);
		clear_dll(*head);
		exit(EXIT_FAILURE);
	}
	variable = *head;
	vz = variable->next->n - variable->n;
	variable->next->n = vz;
	*head = variable->next;
	free(variable);
}
/**
 * op_swap - function of the prototype
 * @head: stack head
 * @counter: line number
*/
void op_swap(stack_t **head, unsigned int counter)
{
	stack_t *qx;
	int qy = 0, qz;

	qx = *head;
	while (qx)
	{
		qx = qx->next;
		qy++;
	}
	if (qy < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.files);
		free(bus.info);
		clear_dll(*head);
		exit(EXIT_FAILURE);
	}
	qx = *head;
	qz = qx->n;
	qx->n = qx->next->n;
	qx->next->n = qz;
}
