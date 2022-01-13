#include "monty.h"
/**
 * push - push the number on the stack
 * @stack: double linked list
 * @line_number: number of evaluated line
 */
void push(stack_t **stack, unsigned int line_number)
{
	int number_add = 0;
	unsigned int i;
	char *token;

	token = strtok(lines, " \n\t\"");
	token = strtok(NULL, " \n\t\"");
	if (token)
	{
		for (i = 0; i < strlen(token); i++)
		{
			if (!isdigit(token[i]))
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free(sin_espacios);
				free_dlist(head);
				free(lines);
				fclose(temp_file);
				free_grid(array, 0);
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(sin_espacios);
		free_dlist(head);
		free(lines);
		fclose(temp_file);
		free_grid(array, 0);
		exit(EXIT_FAILURE);
	}
	number_add = atoi(token);
	add_dnodeint(stack, number_add);
}

/**
 * error - print stack
 * @stack: double linked list
 * @line_number: number of evaluated line
 */
void error(__attribute__((unused)) stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, array[0]);
	free(sin_espacios);
	free_dlist(head);
	free(lines);
	fclose(temp_file);
	free_grid(array, 0);
	exit(EXIT_FAILURE);
}

/**
 * pall - no comand found
 * @stack: double linked list
 * @line_number: number of evaluated line
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp = *stack;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - push the number on the stack
 * @stack: double linked list
 * @line_number: number of evaluated line
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(sin_espacios);
		free_dlist(head);
		free(lines);
		fclose(temp_file);
		free_grid(array, 0);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop - pop the number on the stack
 * @stack: double linked list
 * @line_number: number of evaluated line
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty\n", line_number);
		free(sin_espacios);
		free_dlist(head);
		free(lines);
		fclose(temp_file);
		free_grid(array, 0);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	if (tmp->next)
		{
			*stack = tmp->next;
			(*stack)->prev = NULL;
		}
		else
			*stack = NULL;
		free(tmp);
}
