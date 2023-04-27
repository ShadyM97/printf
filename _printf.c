#include "main.h"

/**
  * _printf - print function
  * @format: format specifiers
  * Return: number of characters printed
  */
int _printf(const char *format, ...)
{
	va_list vl;
	int i = 0;
	int printed_char = 0;

	if (format == NULL)
		return (-1);
	va_start(vl, format);
	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] != '\0')
				printed_char += print_specifier(vl, format[i]);
			else
			{
				return (printed_char);
			}
		}
		else
		{
			_putchar(format[i]);
			printed_char++;
		}
		i++;
	}
	va_end(vl);
	return (printed_char);
}
/**
  * print_specifier - function the prints the specifier
  * @list: input va_list
  * @specifier: input specifier
  * Return: number of characters printed
  */
int print_specifier(va_list list, char specifier)
{
	int printed_char = 0;

	switch (specifier)
	{
		case 'c':
			printed_char = print_char(list);
			break;
		case '%':
			printed_char = _putchar('%');
			break;
		case 's':
			printed_char = print_string(list);
			break;
		case 'd':
			printed_char = print_int(list);
			break;
		case 'i':
			printed_char = print_int(list);
			break;
		default:
			printed_char = print_other(specifier);
			break;
	}
	return (printed_char);
}
