#include "main.h"


int _printf(const char *format, ...)
{
	int c;
	int a;
	char *s;
	int printer;
	va_list args;

	if (*format == NULL)
	{
		return (-1);
	}

	va_start (args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			printer++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				break;
			}
			if (*format == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1);
				printer++;
			}
			else if (*format == 's')
			{
				s = va_arg(args, char*);
				write(1, s, strlen(s));
				printer++;
			}
			else if (*format == 'd')
			{
				a = va_arg(args, int);
				char buffer[50];
				snprintf(buffer, sizeof(buffer), "%d", a);
				write(1, buffer, strlen(buffer));
				printer++;
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				printer++;
			}
		}
		format++;
	}
	va_end(args);
	return (printer);
}

int main()
{
	_printf("Isaac\n");
	_printf("%c\n", 'L');
	_printf("%s\n", "ButtHole");
	_printf("%%\n");
	_printf("%d\n", 98); 
	return (0);
}


