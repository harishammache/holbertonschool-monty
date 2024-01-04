#include "monty.h"
void add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *tmp;    if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	sum = (*stack)->n + tmp->n;
	free(*stack);
	(*stack) = tmp;
	(*stack)->n = sum;
}