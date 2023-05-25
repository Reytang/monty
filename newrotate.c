#include "monty.h"
/**
  *op_rotl- function of the prototype
  *@head: stack head
  *@counter: line number
 */
void op_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *speed = *head, *vx;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	vx = (*head)->next;
	vx->prev = NULL;
	while (speed->next != NULL)
	{
		speed = speed->next;
	}
	speed->next = *head;
	(*head)->next = NULL;
	(*head)->prev = speed;
	(*head) = vx;
}
/**
  *op_rotr- function of the prototype
  *@head: stack head
  *@counter: line number
 */
void op_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *duplq;

	duplq = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (duplq->next)
	{
		duplq = duplq->next;
	}
	duplq->next = *head;
	duplq->prev->next = NULL;
	duplq->prev = NULL;
	(*head)->prev = duplq;
	(*head) = duplq;
}

