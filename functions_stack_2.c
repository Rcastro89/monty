#include "monty.h"
/**
 * swap - swaps the top two elements of the stack.
 * @stack: double linked list
 * @line_number: number of evaluated line
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!*stack || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(sin_espacios);
		free_dlist(*stack);
		free(lines);
		fclose(temp_file);
		free_grid(array, 0);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * nop - do nothing.
 * @stack: double linked list
 * @line_number: number of evaluated line
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)(stack);
	(void)(line_number);
}

/**
 * pchar - pchar the number on the stack
 * @stack: double linked list
 * @line_number: number of evaluated line
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(sin_espacios);
		free_dlist(head);
		free(lines);
		fclose(temp_file);
		free_grid(array, 0);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 126)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(sin_espacios);
		free_dlist(head);
		free(lines);
		fclose(temp_file);
		free_grid(array, 0);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: double linked list
 * @line_number: number of evaluated line
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	(void)(line_number);

	while ((*stack) != NULL)
	{
		if ((*stack)->n < 0 || (*stack)->n > 126)
			break;
		printf("%c", (*stack)->n);
		(*stack) = (*stack)->next;
	}
	if ((*stack) == NULL)
		printf("\n");
}
