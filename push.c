#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * push - ajoute un nouvel élément au sommet de la pile
 * @stack: double pointeur vers le haut de la pile
 * @line_number: le numéro de la ligne où l'opcode apparaît
 * pour afficher en cas d'erreur
 * @arg: l'argument à ajouter à la pile, qui doit être un entier
 *
 * Description: Cette fonction crée un nouvel élément de type stack_t,
 *              convertit l'argument arg en entier (en utilisant atoi),
 *              et l'ajoute au sommet de la pile. Si arg n'est pas un entier
 *              valide ou est NULL, un message d'erreur est affiché et le
 *              programme se termine avec EXIT_FAILURE.
 */


void push(stack_t **stack, unsigned int line_number, const char *arg)
{
	int i = 0;

	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (i = 0; arg[i]; i++)
	{
		if (!isdigit(arg[i]) && !(i == 0 && arg[i] == '-'))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	int n = atoi(arg);

	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
