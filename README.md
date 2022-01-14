# 0x19. C - Stacks, Queues - LIFO, FIFO
 By Julien Barbier

------------

# Monty.

------------

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

**in this project we was created an interpreter for Monty ByteCode files.**

------------

## Requirements:

------------
- Ubuntu 14.04 LTS
- All .c files pass Betty style: betty-style.pl and betty-doc.pl
- Maximum of one global variable
- No more than 5 functions per file
- Prototypes of all functions are included in header file called monty.h
- All header files are include guarded
- Allowed to use standard library
------------

## Project Data Structure:

------------
```
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```
------------

## Compilation:

------------
The files are to be compiled this way:
```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```
------------

## Usage:

------------
```
$ ./monty <file_path>
```
------------

## Tasks:

------------
0. push, pall
- Implement the push and pall opcodes.
- The opcode push pushes an element to the stack.
- The opcode pall prints all the values on the stack, starting from the top of the stack.
1. pint
- Implement the pint opcode.
- The opcode pint prints the value at the top of the stack, followed by a new line.
2. pop
- Implement the pop opcode.
- The opcode pop removes the top element of the stack.
3. swap
- Implement the swap opcode
- The opcode swap swaps the top two elements of the stack.
4. add
- Implement the add opcode.
- The opcode add adds the top two elements of the stack.
5. nop
- Implement the nop opcode.
- The opcode nop doesn’t do anything.

## Advanced Tasks

- opcodes: sub, div, mul, mod, comments, pchar, pstr, rotl, rotr, stack, queue, Holberton, Add two digits, Multiplication, Multiplication level up


# Authors:
  - Reinaldo Castro - [Rcastro89](https://github.com/Rcastro89) 
  - Carolina Espitia - [caritoespicaita](https://github.com/caritoespicaita) 

