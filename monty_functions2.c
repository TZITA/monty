#include "monty.h"

void m_add(stack_t **s, unsigned int line_number);
void m_sub(stack_t **s, unsigned int line_number);
void m_div(stack_t **s, unsigned int line_number);
void m_mul(stack_t **s, unsigned int line_number);
void m_mod(stack_t **s, unsigned int line_number);

/**
 * m_add - ep
 * @s: stack
 * @line_number: line
 *
 * Return: n.
 */
void m_add(stack_t **s, unsigned int line_number)
{
	if ((*s)->next == NULL || (*s)->next->next == NULL)
	{
		error_set_op(st_error(line_number, "add"));
		return;
	}
	(*s)->next->next->n += (*s)->next->n;
	m_pop(s, line_number);
}


/**
 * m_sub - ep
 * @s: stack
 * @line_number: line
 *
 * Return: n.
 */
void m_sub(stack_t **s, unsigned int line_number)
{
	if ((*s)->next == NULL || (*s)->next->next == NULL)
	{
		error_set_op(st_error(line_number, "sub"));
		return;
	}
	(*s)->next->next->n -= (*s)->next->n;
	m_pop(s, line_number);
}

/**
 * m_div - ep
 * @s: stack
 * @line_number: line
 *
 * Return: n.
 */
void m_div(stack_t **s, unsigned int line_number)
{
	if ((*s)->next == NULL || (*s)->next->next == NULL)
	{
		error_set_op(st_error(line_number, "div"));
		return;
	}
	(*s)->next->next->n /= (*s)->next->n;
	m_pop(s, line_number);
}

/**
 * m_mul - ep
 * @s: stack
 * @line_number: line
 *
 * Return: n.
 */
void m_mul(stack_t **s, unsigned int line_number)
{
	if ((*s)->next == NULL || (*s)->next->next == NULL)
	{
		error_set_op(st_error(line_number, "mul"));
		return;
	}
	(*s)->next->next->n *= (*s)->next->n;
	m_pop(s, line_number);
}

/**
 * m_mod - ep
 * @s: stack
 * @line_number: line
 *
 * Return: n.
 */
void m_mod(stack_t **s, unsigned int line_number)
{
	if ((*s)->next == NULL || (*s)->next->next == NULL)
	{
		error_set_op(st_error(line_number, "mod"));
		return;
	}
	(*s)->next->next->n %= (*s)->next->n;
	m_pop(s, line_number);
}
