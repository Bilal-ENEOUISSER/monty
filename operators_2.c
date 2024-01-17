#include "monty.h"

/**
 * nop - do nothing
 * @h: head of list
 * @line_number: bytecode line number
 */
void nop(stack_t **h, unsigned int line_number)
{
	(void) h;
	(void) line_number;
}

/**
 * pchar - print top node in stack as ascii letter
 * @h: head of list
 * @line_number: bytecode line number
 */
void pchar(stack_t **h, unsigned int line_number)
{
	if (!h || !*h)
	{
		printf("L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (((*h)->n) >= 0 && ((*h)->n) <= 127)
		printf("%c\n", (*h)->n);
	else
	{
		printf("L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

}

/**
 * pstr - print top nodes in stack as ascii letter
 * and stop only if end of stack, node is 0, or not in ascii table
 * @h: head of list
 * @line_number: bytecode line number
 */
void pstr(stack_t **h, unsigned int line_number)
{
	stack_t *tmp;

	if (!h || !*h)
	{
		printf("L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *h;
	while ((tmp != NULL) && (tmp->n != 0) &&
	       (tmp->n >= 0) && (tmp->n <= 127))
	{
		printf("%c", (tmp)->n);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - rotate so top of stack becomes last one, second becomes first one
 * @h: node to be rotated
 * @line_number: node number
 */
void rotl(stack_t **h, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;

	if ((*h)->next != NULL)
	{
		tmp = *h;
		while (tmp->next != NULL)
			tmp = tmp->next;
		(*h)->prev = tmp;
		tmp->next = *h;
		(*h)->next->prev = NULL;
		*h = (*h)->next;
		tmp->next->next = NULL;
	}
}

/**
 * rotr - rotate so only bottom node of stack becomes first one
 * @h: node to be rotated
 * @line_number: node number
 */
void rotr(stack_t **h, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;

	if ((*h)->next != NULL)
	{
		tmp = *h;
		while (tmp->next != NULL)
			tmp = tmp->next;
		(*h)->prev = tmp;
		tmp->next = *h;
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		(*h) = (*h)->prev;
	}
}
