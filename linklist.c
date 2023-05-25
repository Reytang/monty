#include "monty.h"
/**
 * add_end_node - function of the prototype
 * @h: pointer to head of list
 * @n: node data
 * Return: 0 if success, -1 if failed
 */
int add_end_node(stack_t **h, int n)
{
	stack_t *new1;

	if (!h)
		return (-1);

	new1 = malloc(sizeof(struct stack_s));
	if (!new1)
	{
		printf("Error: malloc failed");
		return (-1);
	}
	new1->n = n;

	if (*h == NULL)
	{
		*h = new1;
		new1->next = NULL;
		new1->prev = NULL;
	}
	else
	{
		new1->next = *h;
		(*h)->prev = new1;
		*h = new1;
	}
	return (0);
}
/**
 * delete_end_node - function of the prototype
 * @h: pointer to head of doubly linked list
 */
void delete_end_node(stack_t **h)
{
	stack_t *delete = NULL;

	delete = *h;
	if ((*h)->next == NULL)
	{
		*h = NULL;
		free(delete);
	}
	else 
	{
		*h = (*h)->next;
		(*h)->prev = NULL;
		free(delete);
	}
}
/**
 * free_dlist - function of the prototype
 * @h: pointer to head of list
 */
void free_dlist(stack_t **h)
{
	if (!h)
		return;

	while (*h && (*h)->next)
	{
		*h = (*h)->next;
		free((*h)->prev);
	}
	free(*h);
}
