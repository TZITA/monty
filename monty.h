#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMITERS " \n\t\a\b"

extern char **op_tokens;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: to the previous element of the stack (or queue)
 * @next: to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void free_s(stack_t **s);
int init_s(stack_t **s);
int stack_or_queue(stack_t *s);
int monty_exec(FILE *new_file);
void free_tokens(void);
unsigned int token_al(void);
void (*get_op_function(char *opcode))(stack_t**, unsigned int);

char **strtow(char *str, char *DELIMITERS);
int is_delim(char ch, char *DELIMITERS);
int get_word_length(char *str, char *DELIMITERS);
int get_word_count(char *str, char *DELIMITERS);
char *get_next_word(char *str, char *DELIMITERS);

char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_nb(unsigned int num, unsigned int base, char *buff, int buff_size);

int error_set_op(int error_code);
int st_error(unsigned int line_number, char *op);
int error_monty_usage(void);
int error_malloc(void);
int error_open_file(char *filename);
int error_unk_op(char *opcode, unsigned int line_number);
int error_no_int(unsigned int line_number);
int error_pop(unsigned int line_number);
int error_pint(unsigned int line_number);
int error_div(unsigned int line_number);
int error_pchar(unsigned int line_number, char *message);


void m_push(stack_t **stack, unsigned int line_number);
void m_pall(stack_t **stack, unsigned int line_number);
void m_pint(stack_t **stack, unsigned int line_number);
void m_pop(stack_t **stack, unsigned int line_number);
void m_swap(stack_t **stack, unsigned int line_number);
void m_add(stack_t **stack, unsigned int line_number);
void m_nop(stack_t **stack, unsigned int line_number);
void m_sub(stack_t **stack, unsigned int line_number);
void m_div(stack_t **stack, unsigned int line_number);
void m_mul(stack_t **stack, unsigned int line_number);
void m_mod(stack_t **stack, unsigned int line_number);
void m_pchar(stack_t **stack, unsigned int line_number);
void m_pstr(stack_t **stack, unsigned int line_number);
void m_rotl(stack_t **stack, unsigned int line_number);
void m_rotr(stack_t **stack, unsigned int line_number);
void m_stack(stack_t **stack, unsigned int line_number);
void m_queue(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
