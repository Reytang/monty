#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_s - virables
 * @arg: value
 * @files: pointer to monty file
 * @info: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *files;
	char *info;
	int lifi;
}  bus_t;
extern bus_t bus;

char *_relocate(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clear_tab(char *content);
void op_nop(stack_t **head, unsigned int counter);
void op_sub(stack_t **head, unsigned int counter);
void op_div(stack_t **head, unsigned int counter);
void op_mul(stack_t **head, unsigned int counter);
void op_mod(stack_t **head, unsigned int counter);
void op_pchar(stack_t **head, unsigned int counter);
void op_pstr(stack_t **head, unsigned int counter);
void op_rotl(stack_t **head, unsigned int counter);
void op_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void addheadst(stack_t **head, int n);
void addtailst(stack_t **head, int n);
void op_queue(stack_t **head, unsigned int counter);
void op_stack(stack_t **head, unsigned int counter);
void op_push(stack_t **head, unsigned int number);
void op_pall(stack_t **head, unsigned int number);
void op_pint(stack_t **head, unsigned int number);
int startopcode(char *content, stack_t **head, unsigned int counter, FILE *file);
void clear_dll(stack_t *head);
void op_pop(stack_t **head, unsigned int counter);
void op_swap(stack_t **head, unsigned int counter);
void op_add(stack_t **head, unsigned int counter);

#endif

