#include "monty.h"
/**
 * op_stack - function of the prototype
 * @head: stack head
 * @counter: line number
*/
void op_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}
/**
 * op_queue - function of the prototype
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void op_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * addtailst - function of the prototype
 * @n: new_value
 * @head: head of the stack
*/
void addtailst(stack_t **head, int n)
{
	stack_t *node1, *vx;

	vx = *head;
	node1 = malloc(sizeof(stack_t));
	if (node1 == NULL)
	{
		printf("Error\n");
	}
	node1->n = n;
	node1->next = NULL;
	if (vx)
	{
		while (vx->next)
			vx = vx->next;
	}
	if (!vx)
	{
		*head = node1;
		node1->prev = NULL;
	}
	else
	{
		vx->next = node1;
		node1->prev = vx;
	}
}
