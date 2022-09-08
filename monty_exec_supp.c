#include "monty.h"
#include <string.h>

void (*get_op_function(char *opcode))(stack_t**, unsigned int);
int is_line_empty(char *l, char *DELIMITERS);
unsigned int token_al(void);
void free_tokens(void);

/**
 * get_op_function - ep
 * @opcode: opcode match
 *
 * Return: Pointer to a corresponding function.
 */

void (*get_op_function(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_functions[] = {
		{"push", m_push},
		{"pall", m_pall},
		{NULL, NULL}
	};
	int i;
	for (i = 0; op_functions[i]; i++)
	{
		if (strcmp(opcode, op_functions[i].opcode) == 0)
		{
			return (op_functions[i].f);
		}
	}
		return (NULL);
}

/**
 * is_line_empty - ep
 * @l: line
 * @DELIMITERS: Delimiters
 *
 * Return: -1 or 0.
 */

int is_line_empty(char *l, char *DELIMITERS)
{
	int i;
	int j;

	for (i = 0; l[i]; i++)
	{
		for (j = 0; DELIMITERS[j]; j++)
		{
			if (l[i] == DELIMITER[j])
			{
				break;
			}
		}
		if (DELIMITERS[j] == '\0')
		{
			return (0);
		}
	}	
	return (1);
}

/**
 * token_al - ep
 *
 * Return: length pf token.
 */

unsigned int token_al(void)
{
	unsigned int token_len = 0;

	while (op_tokens[token_len])
	{
		token_len++;
	}
	return (token_len);
}

/**
 * free_tokens - ep
 *
 * Return: Nothing.
 */

void free_tokens(void)
{
	size_t i;

	if (op_tokens == NULL)
	{
		return;
	}
	for (i = 0; op_tokens[i]; i++)
	{
		free(op_tokens[i]);
	}
	free(op_tokens);
}
