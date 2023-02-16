#include "include/ft_printf_bonus.h"
#include <limits.h>

void check_leaks(int argc, char *uname)
{
	if (!ft_strncmp(uname, "Linux", 5))
		system("valgrind -q -s --leak-check=full --show-leak-kinds=all\
			--track-origins=yes ./a.out");
	else
		system("leaks a.out && ./a.out");
		ft_printf("Finished checking leaks on %s!\n", uname);

}


int main(int argc, char **argv)
{
	char *s1 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius.";
	if (argc == 2)
		check_leaks(argc, argv[1]);
	else
	{
		ft_printf("%%p : \n");
		printf("Len: %d\n", ft_printf("ft_printf: %p\n", &argc));
		printf("Len: %d\n", printf("og_printf: %p\n", &argc));
		ft_printf("flags + : \n");
		printf("Len: %d\n", ft_printf("ft_printf: %+d \n", -101));
		printf("Len: %d\n", printf("og_printf: %+d \n", -101));
		printf("Len: %d\n", ft_printf("ft_printf: %+i %+i %+i %+i %+i %+i %+i\n", INT_MAX, INT_MIN, LONG_MAX));
		printf("Len: %d\n", printf("og_printf: %+i %+i %+i %+i %+i %+i %+i\n", INT_MAX, INT_MIN, LONG_MAX));
		ft_printf("flags 0 : \n");
		printf("Len: %d\n", ft_printf("ft_printf: %09i \n", INT_MAX));
		printf("Len: %d\n", printf("og_printf: %09i \n", INT_MAX));
		printf("Len: %d\n", ft_printf("ft_printf: %05u \n", -15));
		printf("Len: %d\n", printf("og_printf: %05u \n", -15));
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
		ft_printf("flags dot : \n");
		printf("Len: %d\n", ft_printf("ft_printf: %.1s %.2s %.3s %.4s \n", " - ", "", "4", ""));
		printf("Len: %d\n", printf("og_printf: %.1s %.2s %.3s %.4s \n", " - ", "", "4", ""));
		printf("Len: %d\n", ft_printf("ft_printf: %.8d \n", INT_MAX));
		printf("Len: %d\n", printf("og_printf: %.8d \n", INT_MAX));
		ft_printf("%%i : \n");
		printf("Len: %d\n", ft_printf("ft_printf: %i \n", INT_MAX));
		printf("Len: %d\n", printf("og_printf: %i \n", INT_MAX));
		printf("Len: %d\n", ft_printf("ft_printf: %i %i \n", INT_MIN, INT_MAX));
		printf("Len: %d\n", printf("og_printf: %i %i \n", INT_MIN, INT_MAX));
		ft_printf("flags minus : \n");
		printf("Len: %d\n", ft_printf("ft_printf: %-9d \n", INT_MAX));
		printf("Len: %d\n", printf("og_printf: %-9i \n", INT_MAX));
		printf("Len: %d\n", ft_printf("ft_printf: %-1x \n", -99));
		printf("Len: %d\n", printf("og_printf: %-1x \n", -99));
		printf("Len: %d\n", ft_printf("ft_printf: %-9X %-10X %-11X %-12X %-13X %-14X %-15X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
		printf("Len: %d\n", printf("og_printf: %-9X %-10X %-11X %-12X %-13X %-14X %-15X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
		ft_printf("mix : \n");
		printf("Len: %d\n", ft_printf("ft_printf: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0));
		printf("Len: %d\n", printf("og_printf: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0));
		ft_printf("%% : \n");
		printf("Len: %d\n", ft_printf("ft_printf: %%%% \n"));
		printf("Len: %d\n", printf("og_printf: %%%% \n"));
		printf("Len: %d\n", ft_printf("ft_printf:%% %%\n"));
		printf("Len: %d\n", printf("og_printf:%% %%\n"));
		ft_printf("%%s : \n");
		printf("Len: %d\n", ft_printf("ft_printf: %s %s \n", "", "-"));
		printf("Len: %d\n", printf("og_printf: %s %s \n", "", "-"));
		printf("Len: %d\n", ft_printf("ft_printf: %s %s %s %s %s\n", " - ", "", "4", "", s1));
		printf("Len: %d\n", printf("og_printf: %s %s %s %s %s\n", " - ", "", "4", "", s1));
		ft_printf(" sharp : \n");
		printf("Len: %d\n", ft_printf("ft_printf: %#x %#x %#x %#x %#x %#x %#x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
		printf("Len: %d\n", printf("og_printf: %#x %#x %#x %#x %#x %#x %#x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
		printf("Len: %d\n", ft_printf("ft_printf: %#X %#X %#X %#X %#X %#X %#X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
		printf("Len: %d\n", printf("og_printf: %#X %#X %#X %#X %#X %#X %#X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
		ft_printf("flags space : \n");
		printf("Len: %d\n", ft_printf("ft_printf: % d \n", INT_MAX));
		printf("Len: %d\n", printf("og_printf: % d \n", INT_MAX));
		printf("Len: %d\n", ft_printf("ft_printf: % i \n", INT_MIN));
		printf("Len: %d\n", printf("og_printf: % i \n", INT_MIN));
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
		ft_printf("specifier widht : \n");
		printf("Len: %d\n", ft_printf("ft_printf: %.*s\n", 3, "abcdef"));
		printf("Len: %d\n", printf("og_printf: %.*s\n", 3, "abcdef"));
		ft_printf("specifier procesion : \n");
		printf("Len: %d\n", ft_printf("ft_printf: Preceding with blanks: %10d \n", 1977));
		printf("Len: %d\n", printf("og_printf: Preceding with blanks: %10d \n", 1977));
		printf("Len: %d\n", ft_printf("ft_printf: Preceding with zeros: %010d \n", 1977));
		printf("Len: %d\n", printf("og_printf: Preceding with zeros: %010d \n", 1977));
	}
	return (0);
}
