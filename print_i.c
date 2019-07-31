#include "holberton.h"


/**
 * _print_i - print an integer (helper function)
 * @n: the integer to print
 * @count: a pointer to a counter for the number of bytes printed
 */
void _print_i(t_buf *buffer, int n, int *count)
{
	int lastRetVal;

	if (n < 0)
	{
		*count = bputchar(buffer, '-');

		if (*count < 0)
			return;

		if (n < -9)
			_print_i(buffer, n / -10, count);

		if (*count < 0)
			return;

		lastRetVal = bputchar(buffer, '0' - n % 10);
	}
	else
	{
		if (n > 9)
			_print_i(buffer, n / 10, count);

		if (*count < 0)
			return;

		lastRetVal = bputchar(buffer, '0' + n % 10);
	}

	if (lastRetVal < 0)
		*count = (-1);
	else
		*count += lastRetVal;
}


/**
 * print_i - print an integer
 * @args: the va_list with the integer to print as it's next element
 *
 * Return: the number of bytes printed
 */
int print_i(t_buf *buffer, va_list args)
{
	int count = 0;

	_print_i(buffer, va_arg(args, int), &count);

	return (count);
}
