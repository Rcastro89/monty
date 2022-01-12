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
				free_dlist(head);
				free(lines);
				fclose(temp_file);
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_dlist(head);
		free(lines);
		fclose(temp_file);
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
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, comand);
	free(comand);
	free_dlist(head);
	free(lines);
	fclose(temp_file);
	exit(EXIT_FAILURE);
}

/**
 * pall - no comand found
 * @stack: double linked list
 * @line_number: number of evaluated line
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	print_dlistint(*stack);
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
		fprintf(stderr, "L%d: : can't pint, stack empty\n", line_number);
		free_dlist(*stack);
		free(lines);
		fclose(temp_file);
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
	stack_t *tmp = *stack;

	if (!*stack)
	{
		fprintf(stderr, "L%d: : can't pop an empty\n", line_number);
		free_dlist(*stack);
		free(lines);
		fclose(temp_file);
		exit(EXIT_FAILURE);
	}
	while (!*stack)
		tmp = tmp->next;

	if (tmp == *stack)
	{
		*stack = tmp->next;
		if (*stack != NULL)
			(*stack)->prev = NULL;
	}
	else
	{
		tmp->prev->next = tmp->next;
		if (tmp->next != NULL)
			tmp->next->prev = tmp->prev;
	}
	free(tmp);
}
