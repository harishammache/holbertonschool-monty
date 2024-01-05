#include "monty.h"

/**
 * pall - Prints all the values on the stack, starting from the top.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the script where this instruction appears.
 *
 * Description:
 *     This function is used to execute the 'pall' opcode. It traverses the stack
 *     from the top to the bottom, printing the value of each element. The printing
 *     is done in the order such that the top element is printed first followed by
 *     subsequent elements down the stack. If the stack is empty, the function
 *     doesn't print anything. This function is useful for debugging and visualizing
 *     the state of the stack at a given point during the execution of a Monty bytecode
 *     script.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
