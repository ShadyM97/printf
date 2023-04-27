#include "main.h"
/**
  * print_char - function that prints characters
  * @list: list
  * Return: number of printed characters
  */
int print_char(va_list list)
{
	return (_putchar(va_arg(list, int)));
}
/**
  * print_string - function that prints strings
  * @list: list
  * Return: number of printed characters
  */
int print_string(va_list list)
{
	int i = 0;
	char *str;

	str = va_arg(list, char*);
	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i]; i++)
		_putchar(str[i]);
	return (i);
}
/**
  * print_int - function that prints integers
  * @list: list
  * Return: number of printed characters
  */
int print_int(va_list list)
{
	int x, expo = 1, len = 0;
	int n;

	x = va_arg(list, int);
	if (x < 0)
	{
		len +=  _putchar('-');
		n = x * (-1);
	}
	else
		n = x;
	while (n / expo > 9)
		expo *= 10;
	while (expo != 0)
	{
		len = len + _putchar(n / expo + '0');
		n %= expo;
		expo /= 10;
	}
	return (len);
}
/**
  * print_other - function the prints other characters
  * @c: character
  * Return: number of printed characters
  */
int print_other(char c)
{
	int i = 0;

	i = _putchar('%');
	i += _putchar(c);
	return (i);
}
