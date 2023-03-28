#include "print.h"

/**
 * main - main function
 *@argc: count
 *@argv: array of params
 *Return: 0
 */
int main(int argc, char const *argv[])
{
	_printf("The answer is %d\n", -42);
	_printf("Hello, %s!\n", "world");
	_printf("Printing a literal percent sign: %%\n");
	_printf("This is an unsupported conversion specifier: %z\n");
	return (0);
}
