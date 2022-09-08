#include "monty.h"
#include <string.h>

int stack_or_queue(stack_t *s);
int init_s(stack_t **s);
void free_s(stack_t **s);

/**
 * stack_or_queue - ep
 * @s: pointer to stack
 *
 * Return: 0, 1 or 2.
 */

int stack_or_queue(stack_t *s)
{
	if (s->n == STACK)
	{
		return (STACK);
	}
	else if (s->n == QUEUE)
	{
		return (QUEUE);
	}
	return (2);
}

/**
 * init_s - ep
 * @s:pointer to stack
 *
 * Return: SUCCESS or FAILURE
 */
int init_s(stack_t **s)
{
	stack_t *stk;

	stk = malloc(sizeof(stack_t));
	if (stk == NULL)
	{
		return (error_malloc());
	}
	stk->n = STACK;
	stk->prev = NULL;
	stk->next = NULL;

	*s = stk;

	return (EXIT_SUCCESS);
}

/**
 * free_s - ep
 * @s: pointer to stack
 *
 * Return: NOTHING.
 */
void free_s(stack_t **s)
{
	stack_t *tmp = *s;

	while (*s)
	{
		tmp = (*s)->next;
		free(*s);
		*s = tmp;
	}
}
