#include "monty.h"
/**
 * free_dlist - free malloc
 * @head: dlist
 */
void free_dlist(stack_t *head)
{
	stack_t *node;

	node = head;
	while (head)
	{
		node = head->next;
		free(head);
		head = node;
	}
}

/**
 * print_dlistint - print stack
 * @h: double linked list
 * Return: success
 */
size_t print_dlistint(const stack_t *h)
{
	size_t count = 0;

	if (h)
	{
		for (count = 0; h; count++)
		{
			printf("%d\n", h->n);
			h = h->next;
		}
	}
	return (count);
}

/**
 * add_dnodeint - add the value to the end of the stack
 * @head: double linked list
 * @n: number add
 * Return: List
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	new_dlist = malloc(sizeof(stack_t));
	if (new_dlist == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(comand);
		free_dlist(*head);
		free(lines);
		fclose(temp_file);
		exit(EXIT_FAILURE);
	}
	new_dlist->n = n;
	new_dlist->prev = NULL;
	new_dlist->next = NULL;
	if (*head == NULL)
		*head = new_dlist;
	else
	{
		new_dlist->next = *head;
		(*head)->prev = new_dlist;
		*head = new_dlist;
	}
	return (new_dlist);
}
