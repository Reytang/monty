#include "monty.h"

/**
 * get_op_func - function of the prototype
 * @token1: 1st bytecode input (opcode)
 * Return: pointer to correct operation function
 */
void (*get_op_func(char *token1))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruction_s[] = {
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"nop", nop},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	int x = 0;

	while (instruction_s[x].f != NULL)
	{
		if (strcmp(token1, instruction_s[x].opcode) == 0)
			return (instruction_s[x].f);
		x++;
	}
	return (NULL);
}
