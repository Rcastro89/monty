#include "monty.h"
/**
 * main - main function monty
 * @argc: number of parameters received
 * @argv: parameter array
 * Return: success
 */
int main(int argc, char *argv[])
{
	struct stat sb;
	unsigned int number_line = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	temp_file = fopen(argv[1], "r");
	if (temp_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	stat(argv[1], &sb);
	lines = malloc(sb.st_size);
	if (lines == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(temp_file);
		exit(EXIT_FAILURE);
	}
	head = NULL;
	while (fscanf(temp_file, "%[^\n] ", lines) != EOF)
	{
		number_line += 1;
		codes(lines)(&head, number_line);
	}
	free_dlist(head);
	free(lines);
	fclose(temp_file);

	return (0);
}
