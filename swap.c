#include "monty.h"
/**
 * swap - Implement the swap opcode
 * @stack: A pointer to a pointer to the stack (a doubly linked list)
 * @line_number: The line number in the Monty bytecode
 * file where the "swap" opcode is encountere
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;

	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;

	if (first->next != NULL)
		first->next->prev = first;

	*stack = second;
}
