#include "monty.h"
/**
 * addnode_ - add node to the h stack
 * @h: h of the stack
 * @n: new_value
 * Return: no return
*/
void addnode_(stack_t **h, int n)
{

	stack_t *n_node, *aux;

	aux = *h;
	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = n_node;
	n_node->n = n;
	n_node->next = *h;
	n_node->prev = NULL;
	*h = n_node;
}



/**
* execute_ - executes the opcode
* @stack: h linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute_(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", push_}, {"pall", pall_}, {"pint", pint_},
				{"pop", pop_},
				{"swap", swap_},
				{"add", add_},
				{"nop", nop_},
				{"sub", sub_},
				{"div", div_},
				{"mul", mul_},
				{"mod", mod_},
				{"pchar", pchar_},
				{"pstr", pstr_},
				{"rotl", rotl_},
				{"rotr", rotr_},
				{"queue", queue_},
				{"stack", stack_},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}




/**
* free_stack - frees a doubly linked list
* @h: h of the stack
*/
void free_stack(stack_t *h)
{
	stack_t *aux;

	aux = h;
	while (h)
	{
		aux = h->next;
		free(h);
		h = aux;
	}
}



/**
 * queue_ - prints the top
 * @h: stack h
 * @counter: line_number
 * Return: no return
*/
void queue_(stack_t **h, unsigned int counter)
{
	(void)h;
	(void)counter;
	bus.lifi = 1;
}

/**
 * addqueue_ - add node to the tail stack
 * @n: new_value
 * @h: h of the stack
 * Return: no return
*/
void addqueue_(stack_t **h, int n)
{
	stack_t *n_node, *aux;

	aux = *h;
	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
	{
		printf("Error\n");
	}
	n_node->n = n;
	n_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*h = n_node;
		n_node->prev = NULL;
	}
	else
	{
		aux->next = n_node;
		n_node->prev = aux;
	}
}


