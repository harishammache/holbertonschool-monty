#include "monty.h"
int main(int argc, char *argv[])
{
    if (argc != 2)
	{
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
	}
}
