/*
 * pall.c
 *
 * Description:
 *     Ce fichier contient la fonction pall qui est utilisée pour imprimer
 *     tous les éléments d'une pile. L'impression commence à
 *partir du sommet
 *     de la pile.
 *
 *     Cette fonction parcourt la pile et imprime chaque élément. Si la pile
 *     est vide, elle ne fait rien. C'est un outil utile pour visualiser le
 *     contenu de la pile à un moment donné, particulièrement utile pour le
 *     débogage et la vérification de l'état actuel de la pile.
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
