#include "monty.h"
/**
* startopcode - function of the prototype
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: 1
*/
int startopcode(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", op_push}, {"pall", op_pall}, {"pint", op_pint},
				{"pop", op_pop},
				{"swap", op_swap},
				{"add", op_add},
				{"nop", op_nop},
				{"sub", op_sub},
				{"div", op_div},
				{"mul", op_mul},
				{"mod", op_mod},
				{"pchar", op_pchar},
				{"pstr", op_pstr},
				{"rotl", op_rotl},
				{"rotr", op_rotr},
				{"queue", op_queue},
				{"stack", op_stack},
				{NULL, NULL}
	};
	unsigned int l = 0;
	char *operation;

	operation = strtok(content, " \n\t");
	if (operation && operation[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[l].opcode && operation)
	{
		if (strcmp(operation, opst[l].opcode) == 0)
		{
			opst[l].f(stack, counter);
			return (0);
		}
		l++;
	}
	if (operation && opst[l].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, operation);
		fclose(file);
		free(content);
		clear_dll(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
/**
* clear_dll - function of the prototype
* @head: head of the stack
*/
void clear_dll(stack_t *head)
{
	stack_t *freevariable;

	freevariable = head;
	while (head)
	{
		freevariable = head->next;
		free(head);
		head = freevariable;
	}
}
/**
 * op_div - function of the prototype
 * @head: stack head
 * @counter: line_number
 * Return: Null
*/
void op_div(stack_t **head, unsigned int counter)
{
	stack_t *l;
	int variablelen = 0, z;

	l = *head;
	while (l)
	{
		l = l->next;
		variablelen++;
	}
	if (variablelen < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.files);
		free(bus.info);
		clear_dll(*head);
		exit(EXIT_FAILURE);
	}
	l = *head;
	if (l->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.files);
		free(bus.info);
		clear_dll(*head);
		exit(EXIT_FAILURE);
	}
	z = l->next->n / l->n;
	l->next->n = z;
	*head = l->next;
	free(l);
}

