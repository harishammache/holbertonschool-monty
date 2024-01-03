#include "monty.h"
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
   {
	char *opcode;
	char *arg;
	unsigned int line_number = 0;

	// Augmente le numéro de ligne pour chaque instruction
	line_number++;

	// Sépare la ligne en opcode et argument potentiel
	opcode = strtok(line, " \t\n");
	arg = strtok(NULL, " \t\n");

	// Si la ligne est vide ou un commentaire, continue à la prochaine ligne
	if (opcode == NULL || opcode[0] == '#')
	{
		continue;
	}

	// Compare et exécute l'opcode
	if (strcmp(opcode, "push") == 0)
	{
		if (arg == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			// Ici, libère toute ressource allouée avant de quitter
			// par exemple: free_stack(&stack); free(line); fclose(file);
			exit(EXIT_FAILURE);
		}
		push(&stack, line_number, arg);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(&stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		// Ici, libère toute ressource allouée avant de quitter
		// par exemple: free_stack(&stack); free(line); fclose(file);
		exit(EXIT_FAILURE);
	}
}


	// Nettoyage et fermeture du fichier
	fclose(file);
	free(line);
	// Libère la pile
	free_stack(&stack);

	return 0;
}
