#include "monty.h"

/**
 * add - adds the top two elements of the stack..
 * @stack: double linked list
 * @line_number: number of evaluated line
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack && (*stack)->next)
	{
		temp = (*stack)->next;
		(*stack)->next->n = (*stack)->next->n + (*stack)->n;
		pop(stack, line_number);
		*stack = temp;
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(sin_espacios);
		free_dlist(*stack);
		free(lines);
		fclose(temp_file);
		free_grid(array, 0);
		exit(EXIT_FAILURE);
	}
}

/**
 * sub - sub the top two elements of the stack..
 * @stack: double linked list
 * @line_number: number of evaluated line
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack && (*stack)->next)
	{
		temp = (*stack)->next;
		(*stack)->next->n = (*stack)->next->n - (*stack)->n;
		pop(stack, line_number);
		*stack = temp;
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free(sin_espacios);
		free_dlist(*stack);
		free(lines);
		fclose(temp_file);
		free_grid(array, 0);
		exit(EXIT_FAILURE);
	}
}

/**
 * div_1 - div_1 the top two elements of the stack..
 * @stack: double linked list
 * @line_number: number of evaluated line
 */
void div_1(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack && (*stack)->next)
	{
		temp = (*stack)->next;
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			free(sin_espacios);
			free_dlist(*stack);
			free(lines);
			fclose(temp_file);
			free_grid(array, 0);
			exit(EXIT_FAILURE);
		}
		(*stack)->next->n = (*stack)->next->n / (*stack)->n;
		pop(stack, line_number);
		*stack = temp;
	}
	else
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free(sin_espacios);
		free_dlist(*stack);
		free(lines);
		fclose(temp_file);
		free_grid(array, 0);
		exit(EXIT_FAILURE);
	}
}

/**
 * mul - mul the top two elements of the stack..
 * @stack: double linked list
 * @line_number: number of evaluated line
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack && (*stack)->next)
	{
		temp = (*stack)->next;
		(*stack)->next->n = (*stack)->next->n * (*stack)->n;
		pop(stack, line_number);
		*stack = temp;
	}
	else
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(sin_espacios);
		free_dlist(*stack);
		free(lines);
		fclose(temp_file);
		free_grid(array, 0);
		exit(EXIT_FAILURE);
	}
}
