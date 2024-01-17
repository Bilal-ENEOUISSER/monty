#include "monty.h"
/**
  *nop_- nothing
  *@h: stack h
  *@counter: line_number
  *Return: no return
 */
void nop_(stack_t **h, unsigned int counter)
{
	(void) counter;
	(void) h;
}

/**
 * pchar_ - prints the char at the top of the stack,
 * followed by a new line
 * @h: stack h
 * @counter: line_number
 * Return: no return
*/
void pchar_(stack_t **h, unsigned int counter)
{
	stack_t *h;

	h = *h;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}

/**
 * pstr_ - prints the string starting at the top of the stack,
 * followed by a new
 * @h: stack h
 * @counter: line_number
 * Return: no return
*/
void pstr_(stack_t **h, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *h;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}

/**
  *rotl_- rotates the stack to the top
  *@h: stack h
  *@counter: line_number
  *Return: no return
 */
void rotl_(stack_t **h,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *h, *aux;

	if (*h == NULL || (*h)->next == NULL)
	{
		return;
	}
	aux = (*h)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *h;
	(*h)->next = NULL;
	(*h)->prev = tmp;
	(*h) = aux;
}

/**
  *rotr_- rotates the stack to the bottom
  *@h: stack h
  *@counter: line_number
  *Return: no return
 */
void rotr_(stack_t **h, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	copy = *h;
	if (*h == NULL || (*h)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *h;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*h)->prev = copy;
	(*h) = copy;
}
