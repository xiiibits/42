extern "C"
{
#define new tripouille
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "leaks.hpp"

int iTest = 1;
int main(void)
{
	signal(SIGSEGV, sigsegv);
	title("ft_strlen\t: ")

	/* 1 */ check(ft_strlen("123") == 3); showLeaks();
	/* 2 */ check(ft_strlen("") == 0); showLeaks();
	/* 3 */ check(ft_strlen("Hello") == 5); showLeaks(); // Basic word
	/* 4 */ check(ft_strlen("Hello, World!") == 13); showLeaks(); // Sentence with punctuation
	/* 5 */ check(ft_strlen("a") == 1); showLeaks(); // Single character
	/* 6 */ check(ft_strlen("\0hidden") == 0); showLeaks(); // String with null terminator at start
	/* 7 */ check(ft_strlen("Hello\0Hidden") == 5); showLeaks(); // String with null terminator in middle
	/* 8 */ check(ft_strlen("    ") == 4); showLeaks(); // Just spaces
	/* 9 */ check(ft_strlen("\t\n\r\v\f") == 5); showLeaks(); // Just escape sequences
	/* 10 */ check(ft_strlen("This is a much longer string that has quite a lot of characters in it to test string length functionality properly") == 114); showLeaks(); // Long string
	/* 11 */ check(ft_strlen("12345678901234567890123456789012345678901234567890") == 50); showLeaks(); // 50 characters
	/* 12 */ check(ft_strlen("😀😃😄") == 12); showLeaks(); // UTF-8 characters (3 emojis, 4 bytes each)
	write(1, "\n", 1);
	return (0);
}