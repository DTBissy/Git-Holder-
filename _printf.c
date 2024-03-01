
#include "main.h"

int _printf(const char *format, ...)
{
	int print;
	int c;
	char *s;

	va_list args;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(args, format);

	while (*format) /** Our loop through the string */
	{
		if(*format != '%')/** if character is not '%' print */
		{
		write(1, format, 1);
		print++; /** print the character to stdout */
		}
		else /** if the next character is '%' */
		{
			format++;/** skip the '%' and move to the next */
			if (*format == '\0')
				break;/** stop */ 
			if (*format == 'c')/** if next char is c */
			{
				c = va_arg(args, int);
				write(1, &c, 1);
				print++;
			}
			else if (*format == 's')/**if the next char is 's'*/
			{
				*s = va_arg(args, char*);
				write(1, s, strlen(s));
			}
			else if (*format == '%')/** if next char is '%' print it */
			{
				 write(1, format, 1);
				 print++;
			}
		}
		format++;
	}
	va_end(args);
	return (print);
}

int main()
{
	_printf("Isaac\n");
	_printf("%c\n", 'a');
	return (0);
}
