#include "shell.h"

/**
 * show_prompt - Display the shell prompt
 */
void show_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		_printf("simple_shell$ ");
		fflush(stdout);
	}
}

/**
 * _putchar - custom printf
 * @c: char to print
 */
void _putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

/**
 * _printf - custom printf
 * @format: format specifier
 */
void _printf(const char *format, ...)
{ va_list args;
	int divisor;

	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{ _putchar(*format);
		}
		else
		{ format++;
			if (*format == 'd')
			{ int num = va_arg(args, int);

				if (num < 0)
				{ _putchar('-');
					num = -num;
				}
				divisor = 1;
				while (num / divisor >= 10)
				{
					divisor *= 10; }
				while (divisor > 0)
				{ int digit = num / divisor;

					_putchar('0' + digit);
					num %= divisor;
					divisor /= 10; } }
			else if (*format == 's')
			{ const char *str = va_arg(args, const char *);

				while (*str)
				{ _putchar(*str);
					str++; }
			} else
			{ _putchar('%');
				_putchar(*format); }
		} format++;
	} va_end(args);
}
