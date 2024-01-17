#include "monty.h"
/**
 * add_ - adds the top two elements of the stack.
 * @h: stack h
 * @counter: line_number
 * Return: no return
*/
void add_(stack_t **h, unsigned int counter)
{
	stack_t *s;
	int len = 0, aux;

	s = *h;
	while (h)
	{
		s = s->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	s = *h;
	aux = s->n + s->next->n;
	s->next->n = aux;
	*h = s->next;
	free(s);
}

/**
  *sub_- sustration
  *@h: stack h
  *@counter: line_number
  *Return: no return
 */
void sub_(stack_t **h, unsigned int counter)
{
	stack_t *aux;
	int sus, nodes;

	aux = *h;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	aux = *h;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*h = aux->next;
	free(aux);
}

/**
 * f_mul - multiplies the top two elements of the stack.
 * @h: stack h
 * @counter: line_number
 * Return: no return
*/
void f_mul(stack_t **h, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *h;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	h = *h;
	aux = h->next->n * h->n;
	h->next->n = aux;
	*h = h->next;
	free(h);
}

/**
 * f_div - divides the top two elements of the stack.
 * @h: stack h
 * @counter: line_number
 * Return: no return
*/
void f_div(stack_t **h, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *h;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	h = *h;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n / h->n;
	h->next->n = aux;
	*h = h->next;
	free(h);
}

/**
 * f_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @h: stack h
 * @counter: line_number
 * Return: no return
*/
void f_mod(stack_t **h, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *h;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	h = *h;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n % h->n;
	h->next->n = aux;
	*h = h->next;
	free(h);
}
