#include "monty.h"

/**
 * error_set_op - ep
 * @error_code: integer
 *
 * Return: Nothing.
 */

void error_set_op(int error_code)
{
	int token_l = 0;
	int i = 0;
	char *e_s = NULL;
	char **new_t = NULL;

	token_l = token_al();
	new_t = malloc(sizeof(char *) * (token_l + 2));
	if (!op_tokens)
	{
		error_malloc();
		return;
	}
	while (i < token_l)
	{
		new_t[i] = op_tokens[i];
		i++;
	}
	e_s = get_int(error_code);
	if (!e_s)
	{
		free(new_t);
		error_malloc();
		return;
	}
	new_t[i++] = e_s;
	new_t[i] = NULL;
	free(op_tokens);
	op_tokens = new_t;
}
