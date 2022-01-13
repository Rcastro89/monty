#include "monty.h"
/**
 * codes - check received command
 * @sin_espacios: instruction line
 * Return: Function
 */
void (*codes(char *sin_espacios))(stack_t **stack, unsigned int line_number)
{
	int i = 0, j, contdelim = 0;
	char *delim = " \n\t\"";

	instruction_t code[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_1},
		{"mul", mul},
		{"mod", mod},
		{NULL, NULL},
		{"error", error}
	};

	for (i = 0; sin_espacios[i] && sin_espacios; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (sin_espacios[i] == delim[j])
				contdelim++;
		}
	}
	array = malloc(sizeof(char *) * (contdelim + 2));
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
	if (array[0][0] == '#')
		return (code[6].f);
	return (code[i + 1].f);
}
