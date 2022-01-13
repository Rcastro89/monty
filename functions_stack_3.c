#include "monty.h"
/**
 * rotl - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL, *tmp2 = NULL;

	(void)line_number;
	if (*stack && (*stack)->next && stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		if ((*stack)->next)
		{
			tmp2 = (*stack)->next;
			while (tmp2->next)
			{
				tmp2 = tmp2->next;
			}
			tmp2->next = tmp;
			tmp->next = NULL;
			tmp->prev = tmp2;
		}
		else
		{
			(*stack)->next = tmp;
			tmp->next = NULL;
			tmp->prev = *stack;
		}
	}
}
