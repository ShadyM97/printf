#include "main.h"

int get_specifier(va_list list, char src, char *dest, int index);
/**
  * _printf - print function
  * @format: format specifiers
  * Return: number of characters printed
  */
int _printf(const char *format, ...)
{
	va_list vl;
	int i = 0, j = 0;
	char *buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (buffer == NULL)
		return (-1);
	if (format == NULL)
		return (-1);
	va_start(vl, format);
	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			j = get_specifier(vl, format[i], &buffer[j], j) + j;
		}
		else
		{
			buffer[j] = format[i];
			j++;
		}
		i++;
	}
	write(1, buffer, j);
	free(buffer);
	va_end(vl);
	return (j);
}
/**
  * get_specifier - function to fill buffer according to the specifier
  * @list: list
  * @src: specifier from source input
  * @dest: buffer
  * @index: index of the buffer
  * Return: final index of buffer
  */
int get_specifier(va_list list, char src, char *dest, int index)
{
	int i;
	char *str;

	switch (src)
	{
		case 'c':
			{
				dest[index] = va_arg(list, int);
				index++;
				break;
			}
		case 's':
			{
				str = va_arg(list, char*);
				for (i = 0; str[i]; i++)
				{
					dest[index] = str[i];
					index++;
				}
				break;
			}
		case '%':
			{
				dest[index] = '%';
				index++;
				break;
			}
	}
	return (index);
}
