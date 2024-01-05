#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the script where this instruction appears.
 * @arg: Argument to be pushed onto the stack, expected to be an integer.
 *
 * Description:
 *     This function is used to execute the 'push' opcode.
 * It adds a new element
 *     to the top of the stack with the value specified in 'arg'. The function
 *     verifies if 'arg' is a valid integer using the 'is_number' function.
 *     If 'arg' is not a valid integer or is missing,
 * it prints an error message
 *     and exits with EXIT_FAILURE.
 */

void push(stack_t **stack, unsigned int line_number, const char *arg)
{
	stack_t *new_node;
	int num;

	if (arg == NULL || !is_number(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = atoi(arg);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * is_number - Checks if a string represents a valid integer.
 * @str: String to check.
 *
 * Description:
 *     This function checks whether a given string is a valid integer.
 *     It handles optional '+' or '-' signs at the beginning and ensures
 *     that the rest of the characters are digits. It's used to validate
 *     the argument for the 'push' opcode.
 *
 * Return: true if 'str' is a valid integer, false otherwise.
 */

bool is_number(const char *str)
{
	if (*str == '-' || *str == '+')
	str++;

	while (*str)
	{
		if (!isdigit(*str))
			return (false);
		str++;
	}

	return (true);
}
