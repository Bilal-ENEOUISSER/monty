#include "monty.h"

/**
 * add_ - adds the top two elements in stack
 * @h: top node
 * @line_number: node number
 */
void add_(stack_t **h, unsigned int line_number)
{
	if (*h == NULL || (*h)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*h)->next->n += (*h)->n;
	(*h) = (*h)->next;
	free((*h)->prev);
	(*h)->prev = NULL;
}

/**
 * sub_ - subtract second node from top node
 * @h: top of list
 * @line_number: line of command
 */
void sub_(stack_t **h, unsigned int line_number)
{
	if (*h == NULL || (*h)->next == NULL)
	{
		printf("L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*h)->next->n -= (*h)->n;
	(*h) = (*h)->next;
	free((*h)->prev);
	(*h)->prev = NULL;
}

/**
 * mul_ - multiply second node and top node
 * @h: top of list
 * @line_number: line of command
 */
void mul(stack_t **h, unsigned int line_number)
{
	if (*h == NULL || (*h)->next == NULL)
	{
		printf("L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*h)->next->n *= (*h)->n;
	(*h) = (*h)->next;
	free((*h)->prev);
	(*h)->prev = NULL;
}

/**
 * div_ - divide second node from top node
 * @h: top of list
 * @line_number: line of command
 */
void div_(stack_t **h, unsigned int line_number)
{
	if (*h == NULL || (*h)->next == NULL)
	{
		printf("L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*h)->n == 0 || (*h)->next->n == 0)
	{
		printf("L%u: division by zero\n", line_number);
	}
	(*h)->next->n /= (*h)->n;
	(*h) = (*h)->next;
	free((*h)->prev);
	(*h)->prev = NULL;
}

/**
 * mod_ - mod second node from top node
 * @h: top of list
 * @line_number: line of command
 */
void mod_(stack_t **h, unsigned int line_number)
{
	if (h == NULL || *h == NULL)
	{
		printf("L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*h)->n == 0 || (*h)->next->n == 0)
	{
		printf("L%u: division by zero\n", line_number);
	}
	(*h)->next->n %= (*h)->n;
	(*h) = (*h)->next;
	free((*h)->prev);
	(*h)->prev = NULL;
}
