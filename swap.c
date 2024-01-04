#include "monty.h"

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
