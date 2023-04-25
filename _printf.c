#include "main.h"
/**
  * _printf - print function
  * @format: format specifiers
  * Return: number of characters printed
  */
int _printf(const char *format, ...)
{
	va_list vl;
	int i = 0, j = 0;
	int length = 0;
	char buffer[BUFFER_SIZE];
	char *str;

	if (format == NULL)
		return (-1);
	va_start(vl, format);
	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					{
						buffer[j] = va_arg(vl, int);
						j++;
						break;
					}
				case 's':
					{
						str = va_arg(vl, char*);
						while (str[length] != '\0')
							length++;
						write(1, str, length);
					}
			}
		}
		else
		{
			buffer[j] = format[i];
			j++;
		}
		i++;
	}
	write(1, buffer, j);
	va_end(vl);
	return (j);
}
