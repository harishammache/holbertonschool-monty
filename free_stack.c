#include "monty.h"

/**
 * free_stack - Free a stack.
 * @stack: Double pointer to the top of the stack.
 *
 * Description:
 *     This function is used to free a stack. It traverses
 * the stack from the top,
 *     freeing each element until the entire stack is deallocated.
 *     This is essential to prevent memory leaks, especially before the program
 *     termination or when an error occurs and the program
 * needs to exit cleanly.
 */

void free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
