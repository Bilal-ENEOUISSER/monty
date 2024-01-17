#include "monty.h"
/**
 * addnode_ - add node to the h stack
 * @h: h of the stack
 * @n: new_value
 * Return: no return
*/
void addnode_(stack_t **h, int n)
{

	stack_t *new_node, *aux;

	aux = *h;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *h;
	new_node->prev = NULL;
	*h = new_node;
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
				{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
				{"pop", f_pop},
				{"swap", f_swap},
				{"add", f_add},
				{"nop", f_nop},
				{"sub", f_sub},
				{"div", f_div},
				{"mul", f_mul},
				{"mod", f_mod},
				{"pchar", f_pchar},
				{"pstr", f_pstr},
				{"rotl", f_rotl},
				{"rotr", f_rotr},
				{"queue", f_queue},
				{"stack", f_stack},
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
* free_stack_ - frees a doubly linked list
* @h: h of the stack
*/
void free_stack_(stack_t *h)
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
void f_queue_(stack_t **h, unsigned int counter)
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
	stack_t *new_node, *aux;

	aux = *h;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*h = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}



/**
 * stack_ - prints the top
 * @h: stack h
 * @counter: line_number
 * Return: no return
*/
void stack_(stack_t **h, unsigned int counter)
{
	(void)h;
	(void)counter;
	bus.lifi = 0;
}
