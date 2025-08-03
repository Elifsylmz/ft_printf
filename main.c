#include <stdio.h>
#include "ft_printf.h"

int main()
{

	int a;

	a = ft_printf("%c\n %s\n %d\n", 'a', "elfsemayilmaz", 1234);

	printf("%p\n", &a);
	printf("%d\n", a);
}