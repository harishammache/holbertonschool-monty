#include "monty.h"

/**
 * pint - Imprime la valeur en haut de la pile.
 * @stack: Double pointeur vers le haut de la pile.
 * @line_number: Le numéro de la ligne actuelle (pour les messages d'erreur).
 *
 * Description:
 *     Cette fonction est conçue pour exécuter l'opcode 'pint'.
 *     Elle imprime la valeur en haut de la pile, suivie d'une nouvelle ligne.
 *     Avant de tenter d'imprimer, la fonction vérifie si la pile n'est pas vide.
 *     Si la pile est vide, un message d'erreur est affiché sur stderr,
 *     et le programme se termine avec un statut EXIT_FAILURE.
 *     Si la pile contient au moins un élément, la valeur du sommet est imprimée.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
