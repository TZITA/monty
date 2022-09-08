#include "monty.h"

char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_nb(unsigned int num, unsigned int base, char *buff, int buff_size);

/**
 * get_int - ep
 * @num: number
 *
 * Return: ntm.
 */
char *get_int(int num)
{
	unsigned int tmp;
	int len = 0;
	int num_len = 0;
	char *ret;

	tmp = _abs(num);
	len = get_numbase_len(tmp, 10);

	if (num < 0 || num_len < 0)
	{
		len++;
	}
	if (!ret)
	{
		return (NULL);
	}
	fill_nb(tmp, 10, ret, len);
	if (num < 0 || num_len < 0)
	{
		ret[0] = '-';
	}
	return (ret);
}

/**
 * _abs - ep
 * @i: int
 *
 * Return: n.
 */

unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * get_numbase_len - ep
 * @num: number
 * @base: base
 *
 * Return: n.
 */

int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num / base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_nb - ep
 * @num: n
 * @base: base
 * @buff: b
 * @buffer_size: s
 *
 * Return: n.
 */

void fill_numbase_buff(unsigned int num, unsigned int base, char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9)
		{
			buff[i] = rem + 97;
		}
		else
		{
			buff[i] = rem + '0';
		}
		num /= base;
		i--;
	}
}
