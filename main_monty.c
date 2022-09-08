#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcnt1.h>

/**
 * main - ep
 * @argc: number of args
 * @argv: array of pointers
 *
 * Return: int
 */

int main(int argc, char **argv)
{
	FILE *new_file = NULL;
	int exit_s = EXIT_SUCCESS;

	if (argc != 2)
	{
		return (error_monty_usage());
	}
	new_fie = fopen(argv[1], "r");
	if new_file == NULL
	{
		return (error_open_file());
	}
	exit_s = monty_exec(new_file);
	fclose(new_file);
	return (exit_s);
}
