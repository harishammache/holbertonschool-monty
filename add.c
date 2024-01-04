#include "monty.h"

/**
 * add - Implement the add opcode
 * @stack: A pointer to a pointer to the stack (a doubly linked list)
 * @line_number: The line number in the Monty bytecode
 * file where the "add" opcode is encountere
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n += temp->n;
	*stack = (*stack)->next;
	free(temp);
	(*stack)->prev = NULL;
}
