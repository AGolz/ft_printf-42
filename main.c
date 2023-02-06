#include "ft_printf.h"
#include <limits.h>


int main(int argc, char **argv)
{
	printf("len: %d\n", ft_printf("ft_printf: %p\n", &argc));
	printf("len: %d\n", printf("printf_org: %p\n", &argc));
	return (0);
}
