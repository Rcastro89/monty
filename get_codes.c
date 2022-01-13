#include "monty.h"
/**
 * codes - check received command
 * @sin_espacios: instruction line
 * Return: Function
 */
void (*codes(char *sin_espacios))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	char *delim = " \n\t\"";

	instruction_t code[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL},
		{"error", error}
	};

	array = malloc(sizeof(char *) * (25 + 2));
	array[0] = NULL;
	array[1] = NULL;
	array[0] = strtok(sin_espacios, delim);

	i = 0;
	while (code[i].opcode != NULL)
	{
		if (strcmp(code[i].opcode, array[0]) == 0)
		{
			return (code[i].f);
		}
		i++;
	}
	return (code[i + 1].f);
}
