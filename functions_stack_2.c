#include "monty.h"
/**
 * swap - swaps the top two elements of the stack.
 * @stack: double linked list
 * @line_number: number of evaluated line
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_dlist(*stack);
		free(lines);
		fclose(temp_file);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * add - adds the top two elements of the stack..
 * @stack: double linked list
 * @line_number: number of evaluated line
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_dlist(*stack);
		free(lines);
		fclose(temp_file);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;
}

/**
 * nop - do nothing.
 * @stack: double linked list
 * @line_number: number of evaluated line
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
