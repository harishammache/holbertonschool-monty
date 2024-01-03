#include "monty.h"

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
