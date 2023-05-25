#include "monty.h"
/**
 * op_pall - function of the prototype
 * @head: stack head
 * @counter: num used
*/
void op_pall(stack_t **head, unsigned int counter)
{
	stack_t *variablex;
	(void)counter;

	variablex = *head;
	if (variablex == NULL)
		return;
	while (variablex)
	{
		printf("%d\n", variablex->n);
		variablex = variablex->next;
	}
}
/**
 * op_push - function of the prototype
 * @head: stack head
 * @counter: line_number
*/
void op_push(stack_t **head, unsigned int counter)
{
	int va, vb = 0, vc = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			vb++;
		for (; bus.arg[vb] != '\0'; vb++)
		{
			if (bus.arg[vb] > 57 || bus.arg[vb] < 48)
				vc = 1;
		}
		if (vc == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.files);
			free(bus.info);
			clear_dll(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.files);
		free(bus.info);
		clear_dll(*head);
		exit(EXIT_FAILURE);
	}
	va = atoi(bus.arg);
	if (bus.lifi == 0)
		addheadst(head, va);
	else
		addtailst(head, va);
}

