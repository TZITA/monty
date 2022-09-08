#include "monty.h"

int error_set_op(unsigned int line_number, char *op);
int error_div(unsigned int line_number);
int error_pop(unsigned int line_number);
int error_pint(unsigned int line_number);
int error_pchar(unsigned int line_number, char *message);

/**
 * error_pop - ep
 * @line_number: line
 *
 * Return: Exit_f.
 */
int error_pop(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * error_pint - ep
 * @line_number: line
 *
 * Return: Exit_f.
 */

int error_pint(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * error_set_op - ep
 * @line_number: line
 * @op: operation
 *
 * Return: exit_f.
 */
int error_set_op(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * error_div - ep
 * @line_number: line
 *
 * Return: exit_f.
 */
int error_div(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * error_pchar - ep
 * @line_number: line
 * @message: message
 *
 * Return: exit_f.
 */

int error_pchar(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
