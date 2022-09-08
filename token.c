#include "monty.h"

char **strtow(char *str, char *DELIMITERS);
int is_delim(char ch, char *DELIMITERS);
int get_word_length(char *str, char *DELIMITERS);
int get_word_count(char *str, char *DELIMITERS);
char *get_next_word(char *str, char *DELIMITERS);

/**
 * strtow - ep
 * @str: s
 * @DELIMITERS: d
 *
 * Return: c
 */
char **strtow(char *str, char *DELIMITERS)
{
	char **words = NULL;
	int wc, wordLen, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = get_word_count(str, DELIMITERS);
	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (i < wc)
	{
		wordLen = get_word_length(str, DELIMITERS);
		if (is_delim(*str, DELIMITERS))
		{
			str = get_next_word(str, DELIMITERS);
		}
		words[i] = malloc((wordLen + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordLen)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0';
		str = get_next_word(str, DELIMITERS);
		i++;
	}
	return (words);
}

/**
 * is_delim - ep
 * @ch: c
 * @DELIMITERS: D
 *
 * Return: m.
 */

int is_delim(char ch, char *DELIMITERS)
{
	int i = 0;

	while (DELIMITERS[i])
	{
		if (DELIMITERS[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

/**
 * get_word_length - gets
 * @str: s
 * @DELIMITERS: D
 *
 * Return: m.
 */
int get_word_length(char *str, char *DELIMITERS)
{
	int wLen = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], DELIMITERS))
		{
			pending = 1;
		}
		else if (pending)
		{
			wLen++;
		}
		if (wLen > 0 && is_delim(str[i], delims))
			break;
		i++;
	}
	return (wLen);
}

/**
 * get_word_count - ep
 * @str: s
 * @DELIMITERS: D
 *
 * Return: wc
 */
int get_word_count(char *str, char *DELIMITERS)
{
	int wc = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		i++;
	}
	return (wc);
}

/**
 * get_next_word - ep
 * @str: s
 * @DELIMITERS: D
 *
 * Return: n.
 */
char *get_next_word(char *str, char *DELIMITERS)
{
	int pending = 0;
	int i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], DELIMITERS))
			pending = 1;
		else if (pending)
		{
			break;
		}
		i++;
	}
	return (str + i);
}
