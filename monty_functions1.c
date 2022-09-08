#include "monty.h"

void m_push(stack_t **s, unsigned int line_number);
void m_pall(stack_t **s, unsigned int line_number);
void m_pint(stack_t **s, unsigned int line_number);
void m_pop(stack_t **s, unsigned int line_number);
void m_swap(stack_t **s, unsigned int line_number);

/**
 * m_push - ep
 * @s: stack
 * @line_number: line
 *
 * Return: Nothing.
 */
void m_push(stack_t **s, unsigned int line_number)
{
	stack_t *tmp;
	stack_t *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		error_set_op(error_malloc());
		return;
	}
	if (op_tokens[1] == NULL)
	{
		error_set_op(error_no_int(line_number));
		return;
	}
	for (i = 0; op_tokens[1][i]; i++)
	{
		if (op_tokens[1][i] == '-' && i == 0)
		{
			continue;
		}
		if (op_tokens[1][i] < '0' || op_tokens[1][i] > '9')
		{
			error_set_op(error_no_int(line_number));
			return;
		}
	}
	new->n = atoi(op_tokens[1]);
	if (stack_or_queue(*s) == STACK)
	{
		tmp = (*s)->next;
		new->prev = *s;
		new->next = tmp;
		if (tmp)
		{
			tmp->prev = new;
		}
		(*s)->next = new;
	}
	else
	{
		tmp = *s;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}

/**
 * m_pall - ep
 * @s: stack
 * @line_number: line
 *
 * Return: Nothing.
 */

void m_pall(stack_t **s, unsigned int line_number)
{
	stack_t *tmp = (*s)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}

/**
 * m_pint - ep
 * @s: stack
 * @line_number: line
 *
 * Return: Nothing.
 */
void m_pint(stack_t **s, unsigned int line_number)
{
	if ((*s)->next == NULL)
	{
		error_set_op(error_pint(line_number));
		return;
	}
	printf("%d\n", (*s)->next->n);
}

/**
 * m_pop - ep
 * @s: stack
 * @new_line: line
 *
 * Return: Nothing.
 */

void m_pop(stack_t **s, unsigned int line_number)
{
	stack_t *nxt = NULL;

	if ((*s)->next == NULL)
	{
		error_set_op(error_pop(line_number));
		return;
	}
	nxt = (*s)->next->next;
	free((*s)->next);
	if (nxt)
	{
		nxt->prev = *s;
	}
	(*s)->next = nxt;
}

/**
 * m_swap - ep
 * @s: stack
 * @line_number: line
 *
 * Return: Nothing.
 */

void m_swap(stack_t **s, unsigned int line_number)
{
	stack_t *tmp;

	if ((*s)->next == NULL || (*s)->next->next == NULL)
	{
		error_set_op(st_error(line_number, "swap"));
		return;
	}
	tmp = (*s)->next->next;
	(*s)->next->next = tmp->next;
	(*s)->next->prev = tmp;
	if (tmp->next)
	{
		tmp->next->prev = (*s)->next;
	}
	tmp->next = (*s)->next;
	tmp->prev = *s;
	(*s)->next = tmp;
}
