#include "monty.h"

/**
 * get_op - function to select correct operation function
 * @tok1: 1st bytecode input (opcode)
 * Return: pointer to correct operation function
 */
void (*get_op(char *tok1))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruction_s[] = {
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"add", add_},
		{"sub", sub_},
		{"mul", mul_},
		{"div", div_},
		{"mod", mod_},
		{"pchar", pchar},
		{"pstr", pstr},
		{"nop", nop},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	int i = 0;

	while (instruction_s[i].f != NULL)
	{
		if (strcmp(tok1, instruction_s[i].opcode) == 0)
			return (instruction_s[i].f);
		i++;
	}
	return (NULL);
}
