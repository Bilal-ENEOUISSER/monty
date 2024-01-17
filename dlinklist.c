#include "monty.h"

/**
 * is_number - iterates each character of string to check of isdigit
 * @n: integer
 * Return: 0 if is number, else -1 if not
 */
int is_number(const char *n)
{
	int k = 0;

	if (*n == '-')
		k = 1;
	for (; *(n + k) != '\0'; k++)
	{
		if (isdigit(*(n + k)) == 0)
			return (-1);
	}
	return (0);
}

/**
 * add_end_node - add node to front of doubly linked list
 * @h: pointer to head of list
 * @n: node data
 * Return: 0 if success, -1 if failed
 */
int add_end_node(stack_t **h, int n)
{
	stack_t *new;

	if (!h)
		return (-1);
	new = malloc(sizeof(struct stack_s));
	if (!new)
	{
		printf("Error: malloc failed");
		return (-1);
	}
	new->n = n;
	if (*h == NULL)
	{
		*h = new;
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		new->next = *h;
		(*h)->prev = new;
		*h = new;
	}
	return (0);
}

/**
 * del_end_node - deletes node at end of doubly linked list
 * @h: pointer to head of doubly linked list
 */
void del_end_node(stack_t **h)
{
	stack_t *del = NULL;

	del = *h;
	if ((*h)->next == NULL)
	{
		*h = NULL;
		free(del);
	}
	else
	{
		*h = (*h)->next;
		(*h)->prev = NULL;
		free(del);
	}
}

/**
 * free_dlist - frees a doubly linked list with only int data, no strings
 * @h: pointer to head of list
 */
void free_dlist(stack_t **h)
{
	if (!h)
		return;
	while (*h && (*h)->next)
	{
		*h = (*h)->next;
		free((*h)->prev);
	}
	free(*h);
}
