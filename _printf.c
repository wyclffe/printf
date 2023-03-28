#include "main.h"

// Helper function to find the specifier function for a given specifier
print_func find_function(const char *specifiers, print_func *functions, char c)
{
	for (int i = 0; i < strlen(specifiers); i++)
	{
		if (specifiers[i] == c)
		{
			return functions[i];
		}
	}
	return NULL;
}
// The main _printf function
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	const char *specifiers = "cds%"; // List of supported conversion specifiers
	
	print_func functions[] = {&print_char, &print_int,
		&print_string, &print_percent};

	int printed_chars = 0;

	for (const char *p = format; *p != '\0'; p++)
	{
		if (*p == '%')
		{
			p++;

 			print_func fn = find_function(specifiers, functions, *p);
			if (fn != NULL)
			{
				fn(args);
    			} else {
        			putchar('%');
				putchar(*p);
				printed_chars += 2;
				}
		} else {
			putchar(*p);
			printed_chars++;
			}
	}
	va_end(args);
	return printed_chars;
}
