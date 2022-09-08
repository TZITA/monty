#include "monty.h"
#include <string.h>

/**
 * monty_exec - ep
 * @new_file: file descriptor
 *
 * Return: Int.
 */

int monty_exex(FILE *new_file)
{
	stack_t *s = NULL;
	char *l = NULL;
	size_t len = 0;
	size_t exit_s = EXIT_SUCCESS;
	unsigned int line_number = 0;
	unsigned int prev_tok_len = 0;
	void (*op_function)(stack_t**, unsigned int);

	if (init_s(&s) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	while (getline(&l, &len, new_file) != -1)
	{
		line_number++;
		op_tokens = strtow(l, DELIMITERS);
		if (op_tokens == NULL)
		{
			if (is_line_empty(l, DELIMITERS))
			{
				continue;
			}
			free_s(&s);
			return (error_malloc());
		}
		else if (op_tokens[0][0] == "#")
		{
			free_tokens();
			continue;
		}
		op_function = get_op_function(op_tokens[0]);
		if (op_function == NULL)
		{
			free_s(&s);
			exit_s = error_unk_op(op_tokens[0], line_number);
			free_tokens();
			break;
		}
		prev_tok_len = token_al();
		op_function(&s, line_number);
		if (token_al() != prev_tok_len)
		{
			if (op_tokens && op_tokens[prev_tok_len])
			{
				exit_s = atoi(op_tokens[prev_tok_len]);
			}
			else
			{
				exit_s = EXIT_FAILURE;
			}
			free_tokens();
			break;
		}
		free_tokens();
	}
	free_s(&s);
	if (l && *l == 0)
	{
		free(l);
		return (error_malloc());
	}
	free(l);
	return (exit_s);
}
