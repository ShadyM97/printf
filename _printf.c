#include "main.h"

/**
  * _printf - print function
  * @format: format specifiers
  * Return: number of characters printed
  */
int _printf(const char *format, ...)
{
	va_list vl;
	int i = 0, j = 0, k = 0;
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
			if (format[i] == 'c')
			{
				buffer[j] = va_arg(vl, int);
				j++;
			}
			else if (format[i] == '%')
			{
				buffer[j] = '%';
				j++;
			}
			else
			{
				str = va_arg(vl, char*);
				for (k = 0; str[k]; k++)
				{
					buffer[j] = str[k];
					j++;
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
