#include <stdarg.h>
#include <unistd.h>

int ft_putchar(int c)
{	int count;

	count = 0;
	count += write(1,&c,1);
	return count;
}
int ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		 write(1,&str[i],1);
		i++;
	}
	return i;
}

int find(char c, va_list args)
{
	if(c == 'c')
	{
		return ft_putchar(va_arg(args,int));
	}
	else if (c == 's')
		return ft_putstr(va_arg(args,char *));

}

int ft_printf(const char *format, ...)
{
	va_list args;
	int i;
	int count;

	count=0;
	i = 0;
	va_start(args,format);
	 while (format[i])
	 {
		if(format[i] != '%')
		{
			count += write(1,&format[i],1);
		}
		else
		{
			count += find(format[i+1],args);
		}
		i++;
	 }
	 return count;
}
int main()
{
	ft_printf("gdffghghjkkjl %c %s",'a',"elif");
}