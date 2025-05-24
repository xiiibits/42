extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "leaks.hpp"
#include <string.h>

int iTest = 1;
int main(void)
{
	signal(SIGSEGV, sigsegv);
	title("ft_isalpha\t: ")

	/* 1 */ check(!ft_isalpha('a' - 1)); showLeaks();
	/* 2 */ check(ft_isalpha('a')); showLeaks();
	/* 3 */ check(!ft_isalpha('z' + 1)); showLeaks();
	/* 4 */ check(ft_isalpha('z')); showLeaks();
	/* 5 */ check(!ft_isalpha('A' - 1)); showLeaks();
	/* 6 */ check(ft_isalpha('A')); showLeaks();
	/* 7 */ check(!ft_isalpha('Z' + 1)); showLeaks();
	/* 8 */ check(ft_isalpha('Z')); showLeaks();
	/* 9 */ check(!ft_isalpha('0')); showLeaks(); // Digit
	/* 10 */ check(!ft_isalpha(' ')); showLeaks(); // Space
	/* 11 */ check(!ft_isalpha('\t')); showLeaks(); // Tab
	/* 12 */ check(!ft_isalpha('\0')); showLeaks(); // Null terminator
	/* 13 */ check(!ft_isalpha('!')); showLeaks(); // Symbol
	/* 14 */ check(!ft_isalpha(128)); showLeaks(); // Extended ASCII
	/* 15 */ check(!ft_isalpha(-1)); showLeaks(); // Negative value
	write(1, "\n", 1);
	return (0);
}