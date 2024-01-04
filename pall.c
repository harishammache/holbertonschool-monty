#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * pall - Implement pall opcodes.
 * @stack: A pointer to a pointer to the stack (a doubly linked list)
 * @line_number: The line number in the Monty bytecode
 * file where the "pall" opcode is encountere
 */

void pall(stack_t *stack, unsigned int line_number)
{
	(void) line_number;

	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}
