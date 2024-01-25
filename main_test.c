#include "include/ft_printf_bonus.h"
#include <limits.h>
#include <stdlib.h> 
#include <stdio.h>

void check_leaks(void) 
{
	system("leaks a.out");
	ft_printf("Finished checking leaks!\n");
}


int main(int argc, char **argv)
{
	char *s1 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius.";
	
	ft_printf("%%p : \n");
	printf("Len: %d\n", ft_printf("ft_printf: %p\n", &argc));
	printf("Len: %d\n", printf("og_printf: %p\n", &argc));
	ft_printf("%%c : \n");
	printf("Len: %d\n", ft_printf("ft_printf: %c \n", '0' + 256));
	printf("Len: %d\n", printf("og_printf: %c \n", '0' + 256));
	printf("Len: %d\n", ft_printf("ft_printf: %c %c %c \n", '1', '2', '3'));
	printf("Len: %d\n", printf("og_printf: %c %c %c \n", '1', '2', '3'));
	ft_printf("%%d : \n");
	printf("Len: %d\n", ft_printf("ft_printf: %d \n", INT_MAX ));
	printf("Len: %d\n", printf("og_printf: %d \n", INT_MAX ));
	printf("Len: %d\n", ft_printf("ft_printf: %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	printf("Len: %d\n", printf("og_printf: %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	ft_printf("%%i : \n");
	printf("Len: %d\n", ft_printf("ft_printf: %i \n", INT_MAX));
	printf("Len: %d\n", printf("og_printf: %i \n", INT_MAX));
	printf("Len: %d\n", ft_printf("ft_printf: %i %i \n", INT_MIN, INT_MAX));
	printf("Len: %d\n", printf("og_printf: %i %i \n", INT_MIN, INT_MAX));
	ft_printf("mix : \n");
	printf("Len: %d\n", ft_printf("ft_printf: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0));
	printf("Len: %d\n", printf("og_printf: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0));
	ft_printf(" %% : \n");
	printf("Len: %d\n", ft_printf("ft_printf: %%%% \n"));
	printf("Len: %d\n", printf("og_printf: %%%% \n"));
	printf("Len: %d\n", ft_printf("ft_printf:%% %%\n"));
	printf("Len: %d\n", printf("og_printf:%% %%\n"));
	ft_printf("%%s : \n");
	printf("Len: %d\n", ft_printf("ft_printf: %s %s \n", "", "-"));
	printf("Len: %d\n", printf("og_printf: %s %s \n", "", "-"));
	printf("Len: %d\n", ft_printf("ft_printf: %s %s %s %s %s\n", " - ", "", "4", "", s1));
	printf("Len: %d\n", printf("og_printf: %s %s %s %s %s\n", " - ", "", "4", "", s1));
	ft_printf("%%u : \n");
	printf("Len: %d\n", ft_printf("ft_printf: %u \n", INT_MAX));
	printf("Len: %d\n", printf("og_printf: %u \n", INT_MAX));
	printf("Len: %d\n", ft_printf("ft_printf: %u %u %u %u %u %u %u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	printf("Len: %d\n", printf("og_printf: %u %u %u %u %u %u %u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	ft_printf("%%xX : \n");
	printf("Len: %d\n", ft_printf("ft_printf: %X \n", INT_MAX));
	printf("Len: %d\n", printf("og_printf: %X \n", INT_MAX));
	printf("Len: %d\n", ft_printf("ft_printf: %x \n", INT_MIN));
	printf("Len: %d\n", printf("og_printf: %x \n", INT_MIN));

	if (argc == 2) 
		atexit(check_leaks);

	return (0);
}
