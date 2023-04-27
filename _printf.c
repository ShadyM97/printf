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
			printed_char += print_specifier(vl, format[i]);
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
	int printed_char = 0, i = 0;
	char *str;

	switch (specifier)
	{
		case 'c':
			{
				_putchar(va_arg(list, int));
				printed_char++;
				break;
			}
		case '%':
			{
				_putchar('%');
				printed_char++;
				break;
			}
		case 's':
			{
				str = va_arg(list, char*);
				for (i = 0; str[i]; i++)
				{
					_putchar(str[i]);
					printed_char++;
				}
			}
	}
	return (printed_char);
}
