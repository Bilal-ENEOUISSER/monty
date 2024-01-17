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
	(void) s;
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

	s = *h;
	if (!s)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	if (s->n > 127 || s->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", s->n);
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

	s = *h;
	while (s)
	{
		if (s->n > 127 || s->n <= 0)
		{
			break;
		}
		printf("%c", s->n);
		s = s->next;
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
