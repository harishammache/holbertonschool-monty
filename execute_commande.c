#include "monty.h"
/**
 * execute_opcode - Execute the corresponding Monty bytecode opcode.
 * @opcode: The opcode to be executed.
 * @stack: A pointer to the stack (a doubly linked list).
 *
 * Return: 0 on success, -1 on failure.
 */
int execute_opcode(char *opcode, stack_t **stack)
{
	char *arg;
	unsigned int line_number = 0;

	arg = strtok(NULL, " \n");
	if (strcmp(opcode, "push") == 0)
	{
		if (arg == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			return (-1);
		}
		push(stack, line_number, arg);
	}
	else if (strcmp(opcode, "pall") == 0)
		pall(stack, line_number);
	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_number);
	else if (strcmp(opcode, "pop") == 0)
		pop(stack, line_number);
	else if (strcmp(opcode, "swap") == 0)
		swap(stack, line_number);
	else if (strcmp(opcode, "add") == 0)
		add(stack, line_number);
	else if (strcmp(opcode, "nop") == 0)
		nop(stack, line_number);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		return (-1);
	}
	return (0);
}
