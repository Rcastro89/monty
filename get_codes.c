#include "monty.h"
/**
 * codes - check received command
 * @lines_1: instruction line
 * Return: Function
 */
void (*codes(char *lines_1))(stack_t **stack, unsigned int line_number)
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
	comand = NULL;
	comand = strdup(lines_1);
	comand = strtok(comand, delim);
	while (code[i].opcode != NULL)
	{
		if (strcmp(code[i].opcode, comand) == 0)
		{
			free(comand);
			return (code[i].f);
		}
		i++;
	}
	return (code[i + 1].f);
}
