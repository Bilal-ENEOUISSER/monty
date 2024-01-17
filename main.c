#include "monty.h"

/**
 * main - entry into interpreter
 * @argc: argc counter
 * @argv: arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	int fd = open_file(argv[1]);
	char *buffer = read_file(fd);
	stack_t *h = NULL;

	tokenize(buffer, &h);
	free_resources(fd, buffer, &h);
	return (0);
}

/**
 * open_file - Opens a file and returns the file descriptor.
 * @filename: The name of the file to open.
 * Return: The file descriptor on success, exits on failure.
 */
int open_file(const char *filename)
{
	int fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

/**
 * read_file - Reads content from a file into a buffer.
 * @fd: The file descriptor to read from.
 * Return: A pointer to the allocated buffer containing file content,
 *         exits on failure.
 */
char *read_file(int fd)
{
	char *buffer = malloc(sizeof(char) * 10000);

	if (!buffer)
		exit(EXIT_FAILURE);
	ssize_t n_read = read(fd, buffer, 10000);

	if (n_read == -1)
	{
		free(buffer);
		close(fd);
		exit(EXIT_FAILURE);
	}
	return (buffer);
}

/**
 * tokenize - Tokenizes the input buffer and processes each token.
 * @buffer: The buffer containing the input to tokenize and process.
 * @h: A pointer to the stack used in processing.
 */
void tokenize(char *buffer, stack_t **h)
{
	char *token = strtok(buffer, "\n\t\a\r ;:");
	unsigned int line = 1;
	int ispush = 0;

	while (token != NULL)
	{
		if (ispush == 1)
		{
			push(h, line, token);
			ispush = 0;
		}
		else if (strcmp(token, "push") == 0)
		{
			ispush = 1;
		}
		else
		{
			if (get_op(token) != 0)
				get_op(token)(h, line);
			else
			{
				free_dlist(h);
				fprintf(stderr, "L%d: unknown instruction %s\n", line, token);
				exit(EXIT_FAILURE);
			}
		}
	line++;
	token = strtok(NULL, "\n\t\a\r ;:");
	}
}

/**
 * free_resources - Frees resources (memory and file descriptor).
 * @fd: The file descriptor to close.
 * @buffer: The buffer to free.
 * @h: A pointer to the stack to free.
 */
void free_resources(int fd, char *buffer, stack_t **h)
{
	free_dlist(h);
	free(buffer);
	close(fd);
}
