#include "monty.h"
/**
 * push_ - add node to the stack
 * @h: stack h
 * @counter: line_number
 * Return: no return
*/
void push_(stack_t **h, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*h);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode_(h, n);
	else
		addqueue_(h, n);
}

/**
 * pall_ - prints the stack
 * @h: stack h
 * @counter: no used
 * Return: no return
*/
void pall_(stack_t **h, unsigned int counter)
{
	stack_t *s;
	(void)counter;

	s = *h;
	if (s == NULL)
		return;
	while (s)
	{
		printf("%d\n", s->n);
		s = s->next;
	}
}

/**
 * pint_ - prints the top
 * @h: stack h
 * @counter: line_number
 * Return: no return
*/
void pint_(stack_t **h, unsigned int counter)
{
	if (*h == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h)->n);
}

/**
 * pop_ - prints the top
 * @h: stack h
 * @counter: line_number
 * Return: no return
*/
void pop_(stack_t **h, unsigned int counter)
{
	stack_t *s;

	if (*h == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	s = *h;
	*h = s->next;
	free(s);
}

/**
 * swap_ - adds the top two elements of the stack.
 * @h: stack h
 * @counter: line_number
 * Return: no return
*/
void swap_(stack_t **h, unsigned int counter)
{
	stack_t *s;
	int len = 0, aux;

	s = *h;
	while (s)
	{
		s = s->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	s = *h;
	aux = s->n;
	s->n = s->next->n;
	s->next->n = aux;
}
