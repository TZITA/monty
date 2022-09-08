#include "monty.h"

int error_monty_usage(void);
int error_malloc(void);
int error_open_file(char *filename);
int error_unk_op(char *opcode, unsigned int line_number);
int error_no_int(unsigned int line_number);

/**
 * error_monty_usage - ep
 *
 * Return: Always EXIT_FAILURE.
 */

int error_monty_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * error_malloc - ep
 *
 * Return: Always EXIT_FAILURE.
 */

int error_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * error_open_file - ep
 * @filename: Name of file failed to open
 *
 * Return: Always EXIT_FAILURE.
 */

int error_open_file(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * error_unk_op - ep
 * @opcode: Opcode where error occurred.
 * @line_number: Line number 
 *
 * Return: Always EXIT_FAILURE.
 */

int error_unk_op(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		return (EXIT_FAILURE);
}

/**
 * error_no_int - ep
 * @line_number: line
 *
 * Return: Always EXIT_FAILURE.
 */
int error_no_int(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
