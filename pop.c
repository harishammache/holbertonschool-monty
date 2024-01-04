#include "monty.h"

/**
 * pop - Retire l'élément supérieur de la pile.
 * @stack: Double pointeur vers le haut de la pile.
 * @line_number: Le numéro de la ligne actuelle (pour les messages d'erreur).
 *
 * Description:
 *     Cette fonction est conçue pour exécuter l'opcode 'pop'.
 *     Elle retire l'élément se trouvant au sommet de la pile.
 *     Avant de retirer l'élément, la fonction vérifie
 * si la pile n'est pas vide.
 *     Si la pile est vide, un message d'erreur est affiché sur stderr,
 *     et le programme se termine avec un statut EXIT_FAILURE.
 *     Si la pile contient au moins un élément, cet élément est retiré
 *     et la mémoire qu'il occupait est libérée.
 *     La fonction met ensuite à jour les pointeurs
 * pour maintenir la structure de la pile.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}
